"""Report decomp completion: matched functions / bytes vs the whole game.

Everything here reads committed data only, so --write-readme runs in CI with no
ROM, the same way sm64ds-decomp's does.

That was not always true. dsd's own function search never finishes for this ROM
(see notes/pictochat-layout.md), so the original function-count source was the
Ghidra dump (extracted/pictochat_funcs.json), which is gitignored - derived from
copyrighted material - and therefore absent from a bare checkout. The totals then
had to come from a local extract, which meant the README bar could only ever be
refreshed by hand, and it drifted: it sat at 301/1551 while main held 651.

tools/gen_symbols.py closed that gap by distilling the Ghidra dump down to a
boundary table (name, module, addr, size - no bytes, which are the only
ROM-derived part) and committing it as config/{arm9,arm7}/symbols.txt. Those two
files carry every function this project knows about, so both halves of the
fraction now come from the repo:

  * matched count: committed src/arm{9,7} file count, minus the files parked
    `// NONMATCHING:` by tools/nonmatching.py.
  * total count, and every function's size: config/**/symbols.txt.

The Ghidra cache is still honoured as a fallback when the boundary tables are
missing, so a checkout that predates gen_symbols.py keeps working. Prefer the
committed tables when both exist: they are what CI, tools/chaos_db_ci.py and the
tangos.dev card already agree on, and a local export can drift from them (run
`python tools/gen_symbols.py --check` if the two disagree).

Usage:
    python tools/progress.py                 # full report
    python tools/progress.py --bar           # ready-to-paste README block
    python tools/progress.py --write-readme  # rewrite that block in README.md
"""
import argparse
import pathlib
import re
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
SRC = REPO / "src"
README = REPO / "README.md"
README_START = "<!-- progress:start -->"
README_END = "<!-- progress:end -->"

SYMBOL_FILES = (REPO / "config" / "arm9" / "symbols.txt",
                REPO / "config" / "arm7" / "symbols.txt")
SYMBOL_RE = re.compile(
    r"^name=(\S+)\s+module=(\S+)\s+addr=0x([0-9a-fA-F]+)\s+size=0x([0-9a-fA-F]+)")

sys.path.insert(0, str(REPO / "tools"))
import ledger as L   # noqa: E402


def matched_files():
    """[(module_sub, path), ...] for every committed src/arm{9,7}/*.c[pp] that
    is actually byte-matched - excludes tools/nonmatching.py's parked files
    (marked `// NONMATCHING:` right after the `// decomp:` marker), which are
    logic-correct but explicitly NOT byte-exact and shouldn't count toward
    "matched" (see nonmatching_files() for those)."""
    out = []
    for sub in ("arm9", "arm7"):
        d = SRC / sub
        if not d.is_dir():
            continue
        for p in sorted(list(d.glob("*.c")) + list(d.glob("*.cpp"))):
            head = p.read_text(encoding="utf-8", errors="ignore")[:400]
            if "// NONMATCHING:" in head:
                continue
            out.append((sub, p))
    return out


def nonmatching_files():
    """[(module_sub, path), ...] for every tools/nonmatching.py-parked file -
    decompiled and logic-verified, but not byte-exact."""
    out = []
    for sub in ("arm9", "arm7"):
        d = SRC / sub
        if not d.is_dir():
            continue
        for p in sorted(list(d.glob("*.c")) + list(d.glob("*.cpp"))):
            head = p.read_text(encoding="utf-8", errors="ignore")[:400]
            if "// NONMATCHING:" in head:
                out.append((sub, p))
    return out


def symbol_table():
    """{(module, addr): size} from the committed boundary tables, {} if absent."""
    out = {}
    for p in SYMBOL_FILES:
        if not p.is_file():
            continue
        for line in p.read_text(encoding="utf-8", errors="ignore").splitlines():
            m = SYMBOL_RE.match(line.strip())
            if m:
                out[(m.group(2), int(m.group(3), 16))] = int(m.group(4), 16)
    return out


def sizes_by_key():
    """{(module, addr): size} for every function this project knows about.

    config/**/symbols.txt first, because it is committed and is the same table
    CI and the tangos.dev card count against. The gitignored Ghidra cache is the
    fallback, so a checkout predating tools/gen_symbols.py still reports a
    percentage rather than nothing."""
    table = symbol_table()
    if table:
        return table
    if not (REPO / "extracted" / "pictochat_funcs.json").is_file():
        return {}
    import funcs as F
    return {(f["module"], f["addr"]): f["size"] for f in F.load_funcs()}


def totals(sizes=None):
    """(count, bytes) over every known function, or None when none are known."""
    sizes = sizes_by_key() if sizes is None else sizes
    if not sizes:
        return None
    return len(sizes), sum(sizes.values())


def matched_stats(sizes=None):
    """(matched_count, matched_bytes_if_known) from committed src/ plus the
    size table (for bytes only - the count itself never depends on it).

    Sizes are joined by (module, addr) from each file's `// decomp:` marker,
    NOT by name: the tables carry placeholder names (FUN_xxxxxxxx) as of
    whenever they were generated, so a function renamed to a real symbol after
    that (every cross-matched one) would silently join to nothing."""
    sizes = sizes_by_key() if sizes is None else sizes
    files = matched_files()
    n = len(files)
    if not sizes:
        return n, None
    sized = 0
    for _, p in files:
        head = p.read_text(encoding="utf-8", errors="ignore")[:400]
        m = L.MARKER_RE.search(head)
        if not m:
            continue
        sized += sizes.get((m.group(1), int(m.group(2), 16)), 0)
    return n, sized


def render_bar(matched, total, matched_bytes, total_bytes, nonmatching):
    nm_suffix = f"  ({nonmatching} more parked NONMATCHING - logic-correct, not byte-exact)" if nonmatching else ""
    if total is None:
        return (f"**{matched} function(s) matched** (byte-exact){nm_suffix}. Total function count "
                f"needs config/**/symbols.txt to report - regenerate it with "
                f"tools/gen_symbols.py (see notes/ghidra-setup.md).")
    pct = 100.0 * matched / total if total else 0.0
    bpct = (100.0 * matched_bytes / total_bytes) if total_bytes else 0.0
    filled = int(pct / 5)
    bar = "#" * filled + "-" * (20 - filled)
    return (f"**{matched} / {total} functions matched ({pct:.1f}%)**  `[{bar}]`{nm_suffix}\n"
            f"{matched_bytes} / {total_bytes} bytes ({bpct:.1f}%)")


def write_readme(block):
    text = README.read_text(encoding="utf-8")
    if README_START not in text or README_END not in text:
        pre = text.rstrip() + f"\n\n{README_START}\n{block}\n{README_END}\n"
        README.write_text(pre, encoding="utf-8")
        return
    pre, rest = text.split(README_START, 1)
    _, post = rest.split(README_END, 1)
    README.write_text(f"{pre}{README_START}\n{block}\n{README_END}{post}", encoding="utf-8")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--bar", action="store_true", help="print the README block only")
    ap.add_argument("--write-readme", action="store_true", help="rewrite it in place")
    args = ap.parse_args()

    sizes = sizes_by_key()
    matched, matched_b = matched_stats(sizes)
    nonmatching = len(nonmatching_files())
    known = totals(sizes)
    total_n, total_b = known if known else (None, None)

    block = render_bar(matched, total_n, matched_b, total_b, nonmatching)

    if args.write_readme:
        write_readme(block)
        print(f"README.md updated: {block.splitlines()[0]}")
        return
    if args.bar:
        print(block)
        return

    print(f"matched: {matched} function(s), {matched_b if matched_b is not None else '?'} bytes")
    if nonmatching:
        print(f"nonmatching (parked): {nonmatching} function(s)")
    if total_n is not None:
        print(f"total (known functions): {total_n} function(s), {total_b} bytes")
        print(f"progress: {100.0 * matched / total_n:.2f}% of functions, "
              f"{100.0 * (matched_b or 0) / total_b:.2f}% of bytes")
    else:
        print("total: unknown (no config/**/symbols.txt and no local "
              "extracted/pictochat_funcs.json - run tools/gen_symbols.py)")


if __name__ == "__main__":
    main()
