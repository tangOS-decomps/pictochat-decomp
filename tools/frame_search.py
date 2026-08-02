"""Search for a C candidate that reproduces a target function's exact frame
shape (register push-set + stack depth) - the recurring last-mile problem on
large/stateful functions once `tools/frame_shape.py` reports a mismatch (see
notes/tooling.md's frame-shape sections). Doing this by hand means writing a
new full variant file, recompiling, and re-checking for every hypothesis
("should this base pointer be a named local or recomputed inline at each
use?", "-O4,p or -O4,s?", ...) - slow, and every hard function was
re-deriving the same bespoke throwaway search script from scratch.

Author ONE seed .c file with inline toggle markers instead:

    @{name}[choice0|choice1|...]

Every occurrence sharing the same `name` toggles together, so one logical
decision can have different literal text at each call site - e.g. a shared
base pointer:

    @{qhead}[u16 *qhead = conn + 0x70c + q * 4;|]
    ...
    u32 idx = *@{qhead_expr}[qhead|(u16 *)(conn + 0x70c + q * 4)];

An empty choice ("") means "omit this text entirely" for that combination -
how you express "only declare this local under choice X". Different `@{name}`
axes combine as a cartesian product; this tries every combination against
both `-O4,p` and `-O4,s` (unless --no-opt-sweep), and reports results sorted
by distance from the target frame shape (0 = exact register-set+stack match,
though that's necessary, not sufficient - always follow up an exact frame
match with a real `tools/fdiff.py --align` pass to check actual byte content,
same as any other candidate).

Usage:
    python tools/frame_search.py --seed candidate_template.c --func NAME \
        --module arm7 --addr 0x022d5870 --size 0x1ec

Real example from the FUN_022d5870 investigation (notes/tooling.md /
scratch/FUN_022d5870_notes.md): toggling whether `qhead` is a named local
vs. recomputed inline at each of its 3 use sites was the single change that
took the register push-set from a mismatch to an exact match - exactly the
kind of hypothesis this tool now checks in seconds instead of by hand.

Gotcha worth knowing before authoring a seed: a substituted choice is spliced
in as raw text with no parenthesization added around it, so it inherits
whatever precedence the surrounding characters imply. `*@{x}[qhead + 1|...]`
expands to `*qhead + 1` (parses as `(*qhead) + 1`, not an lvalue - a real
compile error this tool will faithfully report, not silently mishandle) when
you meant `*(qhead + 1)`. Wrap multi-token choices in their own parens in the
seed if the surrounding context dereferences or applies an operator to them.
"""
import argparse
import itertools
import pathlib
import re
import sys
import tempfile

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import match as M      # noqa: E402
import frame_shape as FS  # noqa: E402

TOKEN_RE = re.compile(r"@\{(\w+)}\[([^]]*)]")


def parse_axes(seed_text: str) -> dict:
    """name -> number of choices, from the first occurrence; every later
    occurrence of the same name must offer the same choice COUNT (the text
    per choice may differ per occurrence - that's the whole point)."""
    axes = {}
    for m in TOKEN_RE.finditer(seed_text):
        name, n = m.group(1), len(m.group(2).split("|"))
        if name not in axes:
            axes[name] = n
        elif axes[name] != n:
            sys.exit(f"frame_search: '{name}' has inconsistent choice counts "
                      f"across occurrences ({axes[name]} vs {n})")
    return axes


def render(seed_text: str, choice: dict) -> str:
    def repl(m):
        return m.group(2).split("|")[choice[m.group(1)]]
    return TOKEN_RE.sub(repl, seed_text)


FLAGS_LINE_RE = re.compile(r"^// flags: (.*)$", re.M)
OPT_TOKEN_RE = re.compile(r"-O\d[\w,]*")


def embed_opt_flag(src: str, opt: str) -> str:
    """Replace (or add) the -O<n> token on the seed's own `// flags:` line
    with `opt`, keeping every other token (e.g. -noThumb) untouched. Adds a
    `// flags: <opt>` line right after the `// decomp:` marker if the seed
    had none."""
    m = FLAGS_LINE_RE.search(src)
    if m:
        line = m.group(1)
        new_line = OPT_TOKEN_RE.sub(opt, line) if OPT_TOKEN_RE.search(line) else f"{opt} {line}"
        return src[:m.start(1)] + new_line + src[m.end(1):]
    marker_end = src.find("\n") + 1  # after the `// decomp:` line
    return src[:marker_end] + f"// flags: {opt}\n" + src[marker_end:]


def compile_and_probe(src: str, func: str, flags: str):
    with tempfile.NamedTemporaryFile(suffix=".c", mode="w", delete=False, encoding="utf-8") as f:
        f.write(src)
        path = pathlib.Path(f.name)
    try:
        full_flags = M.apply_flags_marker(flags, src)
        obj = M.compile_c(path, M.CANONICAL, full_flags)
        if obj is None:
            return None
        code, _, _ = M.extract_func(obj, func)
        if code is None:
            return None
        pushed, frame, _ = FS.probe(code, False)
        return pushed, frame, len(code)
    finally:
        path.unlink(missing_ok=True)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--seed", required=True, help="C file with @{name}[opt1|opt2|...] markers")
    ap.add_argument("--func", required=True)
    ap.add_argument("--module", required=True, choices=list(M.MODULES))
    ap.add_argument("--addr", required=True, type=lambda x: int(x, 0))
    ap.add_argument("--size", required=True, type=lambda x: int(x, 0))
    ap.add_argument("--no-opt-sweep", action="store_true", help="only try -O4,p, not -O4,s too")
    ap.add_argument("--limit", type=int, default=0, help="cap combinations tried (0 = unlimited)")
    ap.add_argument("--out-dir", default=None, help="where to write best candidates (default: seed's dir)")
    ap.add_argument("--keep", type=int, default=5, help="how many best candidates to save")
    args = ap.parse_args()

    seed_path = pathlib.Path(args.seed)
    seed_text = seed_path.read_text(encoding="utf-8")
    axes = parse_axes(seed_text)
    if not axes:
        sys.exit("frame_search: no @{name}[...] toggle markers found in seed - "
                  "nothing to search (this tool needs at least one axis)")

    names = sorted(axes)
    combos = list(itertools.product(*(range(axes[n]) for n in names)))
    if args.limit:
        combos = combos[:args.limit]

    base_flags = M.DEFAULT_FLAGS_ARM7 if args.module == "arm7" else M.DEFAULT_FLAGS
    opt_variants = ["-O4,p"] if args.no_opt_sweep else ["-O4,p", "-O4,s"]

    target = M.target_bytes(args.module, args.addr, args.size)
    t_pushed, t_frame, _ = FS.probe(target, False)
    print(f"target: pushed={len(t_pushed)} {t_pushed} frame=0x{t_frame:x}")
    total = len(combos) * len(opt_variants)
    print(f"{len(names)} axis(es) {dict(axes)}, {len(combos)} combination(s) "
          f"x {len(opt_variants)} opt variant(s) = {total} compile(s)\n")

    results = []
    for combo in combos:
        choice = dict(zip(names, combo))
        src = render(seed_text, choice)
        for opt in opt_variants:
            flags = base_flags.replace("-O4,p", opt)
            r = compile_and_probe(src, args.func, flags)
            if r is None:
                continue
            pushed, frame, size = r
            frame_dist = abs(len(pushed) - len(t_pushed)) * 1000 + abs(frame - t_frame)
            # Frame shape alone is necessary, not sufficient - two candidates
            # can share an identical prologue with wildly different bodies
            # (confirmed in practice: an early frame_search run on
            # FUN_022d5870 found an exact frame match whose body was still
            # 20 real diff blocks away). Total compiled size is a cheap,
            # strong secondary signal of true closeness - rank on it first
            # once frame_dist is equal, not as an afterthought.
            size_dist = abs(size - args.size)
            dist = frame_dist * 100000 + size_dist
            exact_frame = pushed == t_pushed and frame == t_frame
            results.append((dist, frame_dist, size_dist, choice, opt, pushed, frame, size, src, exact_frame))

    results.sort(key=lambda r: r[0])
    print(f"{len(results)}/{total} compiled successfully. Top {min(args.keep, len(results))}:\n")
    out_dir = pathlib.Path(args.out_dir) if args.out_dir else seed_path.parent
    for i, (dist, frame_dist, size_dist, choice, opt, pushed, frame, size, src, exact_frame) in enumerate(results[:args.keep]):
        tag = ",".join(f"{n}={v}" for n, v in choice.items())
        status = ("EXACT FRAME + SIZE" if size_dist == 0 else "exact frame, size differs") if exact_frame else f"frame_dist={frame_dist}"
        print(f"  [{i}] {opt:6} {tag:50} pushed={len(pushed)} frame=0x{frame:x} "
              f"size=0x{size:x} (target 0x{args.size:x})  {status}")
        # Embed the winning opt-level into the saved file's own `// flags:`
        # marker (replacing any existing -O<n> token, keeping the rest of
        # the line intact) so it's actually reproducible by a plain
        # match.py/fdiff.py call later, not just inside this search run.
        outp = out_dir / f"{seed_path.stem}_best{i}.c"
        outp.write_text(embed_opt_flag(src, opt), encoding="utf-8")

    if results and results[0][9] and results[0][2] == 0:
        print(f"\nEXACT FRAME + SIZE MATCH - see {out_dir / (seed_path.stem + '_best0.c')}")
        print("Still not proof of a real match - run tools/fdiff.py --align on it "
              "next to check actual byte content, then tools/match.py to confirm.")
    elif results:
        print(f"\nNo exact frame+size match. Closest (by frame, then size) saved to "
              f"{out_dir / (seed_path.stem + '_best0.c')}.")


if __name__ == "__main__":
    main()
