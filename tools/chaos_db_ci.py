"""CI-safe progress data generator: rebuild chaos-db.json from COMMITTED data only
(no ROM, no local extracted/, no ledger), so a GitHub Action can refresh it on every
push and the tangos.dev card / any viewer always shows current numbers.

Same shape as sm64ds-decomp's tools/chaos_db_ci.py, adapted to this repo's model:
  universe   config/{arm9,arm7}/symbols.txt  (name, module, addr, size - committed by
             tools/gen_symbols.py from the local Ghidra export; boundaries, no bytes)
  matched    a committed src/arm9|arm7/*.c[pp] carries a `// decomp: module=.. addr=..`
             marker (tools/ledger.py) for that function and is NOT parked `// NONMATCHING:`

The `stats` block is the contract tangos.dev's romstats-sync reads: totalBytes,
matchedBytes, moduleCount, matchedFunctions (plus totalFunctions, generatedAt).

Until config/{arm9,arm7}/symbols.txt exists the universe is empty and only the matched
COUNT is meaningful - byte totals and the percentage need the symbols table.

Usage: python tools/chaos_db_ci.py [--out chaos-db.json]
"""
import argparse
import json
import pathlib
import re
import time

REPO = pathlib.Path(__file__).resolve().parent.parent
CONFIG = REPO / "config"
SRC = REPO / "src"

# One universe line: name=.. module=.. addr=0x.. size=0x.. (tools/gen_symbols.py output).
SYM_RE = re.compile(
    r"^name=(\S+)\s+module=(\S+)\s+addr=0x([0-9a-fA-F]+)\s+size=0x([0-9a-fA-F]+)\s*$")
# The src-file -> function link (tools/ledger.py marker_for / MARKER_RE).
MARKER_RE = re.compile(
    r"^// decomp: module=(\S+) addr=(0x[0-9a-fA-F]+) name=(\S+)\s*$", re.M)

CPUS = ("arm9", "arm7")


def matched_src():
    """{(module, addr): 'src/arm9/x.c'} for every committed, byte-matched src file -
    keyed by its `// decomp:` marker. Parked `// NONMATCHING:` files are excluded:
    they are logic-correct but not byte-exact, so they do not count as matched."""
    out = {}
    for cpu in CPUS:
        d = SRC / cpu
        if not d.is_dir():
            continue
        for p in sorted(list(d.glob("*.c")) + list(d.glob("*.cpp"))):
            head = p.read_text(encoding="utf-8", errors="ignore")[:400]
            if "// NONMATCHING:" in head:
                continue
            m = MARKER_RE.search(head)
            if not m:
                continue
            module, addr = m.group(1), int(m.group(2), 16)
            out[(module, addr)] = f"src/{cpu}/{p.name}"
    return out


def universe():
    """[(name, module, addr, size), ...] from config/{arm9,arm7}/symbols.txt."""
    rows = []
    for cpu in CPUS:
        sym = CONFIG / cpu / "symbols.txt"
        if not sym.is_file():
            continue
        for line in sym.read_text(encoding="utf-8", errors="ignore").splitlines():
            m = SYM_RE.match(line)
            if m:
                rows.append((m.group(1), m.group(2), int(m.group(3), 16), int(m.group(4), 16)))
    return rows


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default="chaos-db.json")
    args = ap.parse_args()

    matched = matched_src()
    funcs = universe()

    functions = []
    total_b = matched_b = matched_n = 0
    seen = set()
    for name, module, addr, size in funcs:
        seen.add((module, addr))
        src_path = matched.get((module, addr))
        is_matched = src_path is not None
        total_b += size
        rec = {"id": f"{module}:0x{addr:08x}", "module": module, "name": name,
               "addr": addr, "size": size, "matched": is_matched}
        if src_path:
            rec["srcPath"] = src_path
            matched_b += size
            matched_n += 1
        functions.append(rec)

    # A matched src file whose function is not in the symbols table yet (export predates
    # the match, or symbols.txt is missing) still counts - otherwise a fresh match would
    # briefly vanish from the total. It contributes to the matched count with size 0.
    orphan = 0
    for (module, addr), src_path in sorted(matched.items()):
        if (module, addr) in seen:
            continue
        orphan += 1
        matched_n += 1
        functions.append({"id": f"{module}:0x{addr:08x}", "module": module,
                          "name": pathlib.Path(src_path).stem, "addr": addr, "size": 0,
                          "matched": True, "srcPath": src_path})

    stats = {
        "totalFunctions": len(funcs) + orphan,
        "matchedFunctions": matched_n,
        "totalBytes": total_b,
        "matchedBytes": matched_b,
        "moduleCount": len({f["module"] for f in functions}),
    }
    db = {
        "generatedAt": time.strftime("%Y-%m-%d %H:%M", time.gmtime()) + " UTC",
        "project": {"name": "pictochat-decomp", "title": "PictoChat", "platform": "nds"},
        "stats": stats,
        "functions": functions,
    }
    out = pathlib.Path(args.out)
    out.write_text(json.dumps(db), encoding="utf-8")
    pct = (100.0 * matched_b / total_b) if total_b else 0.0
    note = "" if funcs else "  (no symbols.txt yet - matched count only, no total/percentage)"
    print(f"wrote {out} ({out.stat().st_size // 1024} KB): "
          f"{matched_n}/{stats['totalFunctions']} funcs matched, "
          f"{matched_b}/{total_b} bytes ({pct:.2f}%), "
          f"{stats['moduleCount']} modules{note}")


if __name__ == "__main__":
    main()
