#!/usr/bin/env python3
"""Match a function by reusing the source of an already-matched TWIN.

This ROM is full of near-duplicate functions - four BG base getters, three
list-forwarding stubs, a dozen bit setters that differ only in which bit. Every
one of those was matched by hand, one at a time, after reading the same shape
again. That is the work this replaces.

The idea: two functions that disassemble to the SAME SEQUENCE OF MNEMONICS
differ only in their operands. So if one of them is already matched, the other's
C is the matched C with the constants swapped. Build that candidate mechanically
and let tools/match.py say whether it is right.

    python tools/twin.py                      # try every unmatched function
    python tools/twin.py --name FUN_0232xxxx  # just this one
    python tools/twin.py --limit 40 --out scratch/twins

What is compared, and what is substituted, are deliberately different things:

  SKELETON  the mnemonic sequence alone (no registers, no immediates). Two
            functions with the same skeleton perform the same operations in the
            same order, whatever they operate on.
  CONSTS    the ordered immediates and resolved literal-pool words. These are
            what actually differ between twins, and what gets rewritten.
  CALLS     the ordered bl/blx destinations. These MUST be remapped too.
            match.py wildcards relocation slots, so a candidate that calls the
            twin's callees still compares byte-identical while linking the
            wrong functions - a wrong answer with the right bytes. Remapping
            them is not an optimisation, it is what makes the result honest.

A candidate is only emitted when the constants and the calls both line up
one-for-one, and it is only ever reported as a match if match.py agrees.
"""
import argparse
import pathlib
import re
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import funcs as F   # noqa: E402
import match as M   # noqa: E402
import capstone     # noqa: E402

HEX = re.compile(r"#?(?:0x[0-9a-fA-F]+|\b\d+\b)")


COND = ("eq", "ne", "cs", "cc", "mi", "pl", "vs", "vc",
        "hi", "ls", "ge", "lt", "gt", "le", "hs", "lo")


def norm(mn):
    """Mnemonic with the condition suffix and the flag-setting `s` removed.

    Two twins can differ in condition codes - `blt` here, `blo` there - purely
    because one operand is signed and the other is not, which is exactly the
    kind of difference a rewritten source fixes. Comparing normalised
    mnemonics finds those pairs; match.py still has the final say, so a wrong
    guess costs one compile and nothing else."""
    for c in COND:
        if mn.endswith(c) and len(mn) > len(c) + 1:
            mn = mn[:-len(c)]
            break
    return mn[:-1] if mn.endswith("s") and len(mn) > 2 else mn


def _md(mode):
    m = capstone.Cs(capstone.CS_ARCH_ARM,
                    capstone.CS_MODE_THUMB if mode == "thumb" else capstone.CS_MODE_ARM)
    m.detail = True
    return m


def profile(f, all_funcs):
    """(skeleton, consts, calls) for one function, or None if it cannot be read.

    `consts` keeps duplicates and order: position is what lets two twins be
    lined up without understanding either of them."""
    size = F.true_size(f, all_funcs)
    try:
        code = M.target_bytes(f["module"], f["addr"], size)
    except Exception:
        return None
    md = _md(f["mode"])
    skel, consts, calls = [], [], []
    insns = list(md.disasm(code, f["addr"]))
    if not insns:
        return None
    # A trailing literal pool disassembles as garbage instructions. Everything
    # from the last flow-ending instruction onwards is pool, not code.
    end = 0
    for i, ins in enumerate(insns):
        if ins.mnemonic in ("bx", "pop", "b") or ins.mnemonic.startswith("ldm"):
            end = i + 1
    insns = insns[:end] if end else insns
    for ins in insns:
        skel.append(ins.mnemonic)
        if ins.mnemonic in ("bl", "blx") and ins.op_str.startswith("#"):
            calls.append(int(ins.op_str[1:], 0))
            continue
        for tok in HEX.findall(ins.op_str):
            consts.append(int(tok.lstrip("#"), 0))
    # resolved pool words - the values the pc-relative loads actually read
    for ins in insns:
        if ins.mnemonic.startswith("ldr") and "pc" in ins.op_str:
            m = re.search(r"\[pc,?\s*#(-?\d+|0x[0-9a-fA-F]+)\]", ins.op_str)
            if not m:
                continue
            off = int(m.group(1), 0)
            base = (ins.address + 4) if f["mode"] == "thumb" else (ins.address + 8)
            if f["mode"] == "thumb":
                base &= ~3
            pa = base + off
            rel = pa - f["addr"]
            if 0 <= rel + 4 <= len(code):
                consts.append(int.from_bytes(code[rel:rel + 4], "little"))
    return tuple(skel), consts, calls


def name_at(addr, by_addr):
    f = by_addr.get(addr)
    return f["name"] if f else None


def rewrite(src, pairs):
    """Textually swap old->new numbers, longest first so 0x400 does not eat the
    0x40 inside it. Every literal spelling that occurs in this repo's sources is
    covered: 0x-hex of any width, and plain decimal."""
    def forms(v):
        out = {f"0x{v:x}", f"0x{v:X}", f"0x{v:08x}", str(v)}
        if v > 0x7FFFFFFF:
            out.add(str(v - (1 << 32)))          # written as a negative
        return out

    # one pass with a combined pattern, so a value substituted in does not get
    # substituted again by a later rule
    table = {}
    for old, new in pairs:
        if old == new:
            continue
        for spelling in forms(old):
            table.setdefault(spelling, new)
    if not table:
        return src
    pat = re.compile(r"\b(" + "|".join(re.escape(k) for k in
                                       sorted(table, key=len, reverse=True)) + r")\b")

    def sub(m):
        v = table[m.group(1)]
        return f"0x{v:x}" if m.group(1).startswith("0x") else str(v)
    return pat.sub(sub, src)


def source_of(name):
    for sub in ("arm9", "arm7"):
        for ext in ("cpp", "c"):
            p = REPO / "src" / sub / f"{name}.{ext}"
            if p.exists():
                t = p.read_text(encoding="utf-8", errors="ignore")
                if "NONMATCHING" in t or "asm " in t:
                    return None
                return t
    return None


def strip_header(text):
    """Drop the banked file's header/wrapper, keeping the code itself."""
    out = []
    for line in text.splitlines():
        s = line.strip()
        if s.startswith("//") or s.startswith("#pragma") or s == 'extern "C" {':
            continue
        out.append(line)
    body = "\n".join(out).strip()
    if body.endswith("}"):
        # remove the extern "C" closing brace if we removed its opener
        opens = body.count("{")
        if opens < body.count("}"):
            body = body[:body.rfind("}")].rstrip()
    return body


def verify(path, f, all_funcs):
    """Ask match.py. It is the only thing in this tool that decides anything."""
    import subprocess
    o = subprocess.run([sys.executable, str(REPO / "tools" / "match.py"), "--c", str(path),
                        "--func", f["name"], "--addr", hex(f["addr"]),
                        "--size", hex(F.true_size(f, all_funcs)),
                        "--module", f["module"], "--version", M.CANONICAL],
                       capture_output=True, text=True).stdout
    return "MATCHING VERSIONS: " + M.CANONICAL in o


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--name", action="append", default=None)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--out", default="scratch/twins")
    ap.add_argument("--min-skel", type=int, default=4,
                    help="ignore skeletons shorter than this - too generic to mean anything")
    ap.add_argument("--relax", action="store_true",
                    help="compare normalised mnemonics and try EVERY twin, verifying each. "
                         "A wrong guess costs one compile, so casting wider is cheap")
    ap.add_argument("--tries", type=int, default=6,
                    help="--relax: most twins to try per target")
    args = ap.parse_args()

    import ledger as L
    done = L.load_done()
    funcs = [f for f in F.load_funcs() if f.get("module")]
    by_addr = {f["addr"]: f for f in funcs}
    matched = [f for f in funcs if (f["module"], f["addr"]) in done]
    unmatched = [f for f in funcs if (f["module"], f["addr"]) not in done]
    if args.name:
        unmatched = [f for f in unmatched if f["name"] in set(args.name)]

    def key(skel):
        return tuple(norm(m) for m in skel) if args.relax else skel

    print(f"profiling {len(matched)} matched + {len(unmatched)} unmatched", file=sys.stderr)
    index = {}
    for f in matched:
        if source_of(f["name"]) is None:
            continue
        p = profile(f, funcs)
        if p and len(p[0]) >= args.min_skel:
            index.setdefault(key(p[0]), []).append((f, p))
    print(f"{len(index)} distinct matched skeleton(s)", file=sys.stderr)

    outdir = pathlib.Path(args.out)
    outdir.mkdir(parents=True, exist_ok=True)
    made = 0
    for u in unmatched:
        if args.limit and made >= args.limit:
            break
        p = profile(u, funcs)
        if not p:
            continue
        twins = index.get(key(p[0]))
        if not twins:
            continue
        tried = 0
        for tf, tp in twins:
            if args.relax and tried >= args.tries:
                break
            if len(tp[1]) != len(p[1]) or len(tp[2]) != len(p[2]):
                continue
            src = source_of(tf["name"])
            if src is None:
                continue
            body = strip_header(src)
            body = rewrite(body, list(zip(tp[1], p[1])))
            # remap callees by position, and finally the function's own name
            ok = True
            for old_a, new_a in zip(tp[2], p[2]):
                on, nn = name_at(old_a, by_addr), name_at(new_a, by_addr)
                if on is None or nn is None:
                    if old_a != new_a:
                        ok = False
                    continue
                body = re.sub(rf"\b{on}\b", nn, body)
            if not ok:
                continue
            body = re.sub(rf"\b{tf['name']}\b", u["name"], body)
            hdr = "// flags: -noThumb\n" if u["mode"] == "arm" else ""
            text = f"{hdr}// twin of {tf['name']}\n{body}\n"
            dest = outdir / f"{u['name']}.c"
            dest.write_text(text, encoding="utf-8")
            tried += 1
            if not args.relax:
                made += 1
                break
            # In relaxed mode the guess is speculative, so it only counts if
            # match.py agrees. Losers are deleted rather than left to mislead.
            if verify(dest, u, funcs):
                made += 1
                break
            dest.unlink()
    print(f"wrote {made} twin candidate(s) to {outdir}", file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main())
