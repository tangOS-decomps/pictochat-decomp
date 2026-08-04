"""Reconstruct progress/matched.jsonl from committed data alone.

The ledger (progress/matched.jsonl) is local-only (gitignored - see
tools/ledger.py) so two contributors' bookkeeping never conflicts, but that
means a fresh clone (or a clone that just pulled someone else's merged PR)
starts with an EMPTY ledger even though src/ already has real matches in it.
Run this once after cloning or pulling to catch the local ledger up, so
tools/templates.py and friends don't waste time re-deriving candidates for
functions that are already matched.

Two ways a committed src/ file is matched back to (module, addr):
  1. Its `// decomp: module=... addr=0x... name=...` marker comment (see
     tools/ledger.py's marker_for()) - every file banked through ledger.bank()
     has one and this is the reliable path, robust to renames.
  2. Falling back to this project's filename convention (see
     notes/matching-style.md) for older files banked before the marker
     existed: src/arm{9,7}/<name>.c[pp], or <name>_<addr8hex>.c[pp] when a
     symbol name is disambiguated across modules. This ONLY works if the
     Ghidra cache's name for that address still matches the filename - it
     breaks once a function is renamed from its FUN_xxxxxxxx placeholder to a
     real symbol without the marker, which is exactly what the marker fixes.

Usage:
    python tools/sync_ledger.py            # report only
    python tools/sync_ledger.py --apply    # write progress/matched.jsonl
"""
import argparse
import pathlib
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
SRC = REPO / "src"
sys.path.insert(0, str(REPO / "tools"))
import funcs as F    # noqa: E402
import ledger as L   # noqa: E402


def scan_markers():
    """{(module, addr): name} from every `// decomp:` marker comment found in
    src/arm9 and src/arm7, EXCLUDING files parked as `// NONMATCHING:`.

    The NONMATCHING skip matters: those files are logic-correct decompilations
    that are NOT byte-exact (tools/nonmatching.py parks them), so banking them
    into matched.jsonl overstates the match count and makes the ledger claim
    matches that `tools/match.py` will not reproduce. tools/progress.py already
    counts them separately; this used to disagree with it, which is how four
    parked functions ended up recorded as matched.
    """
    out = {}
    for sub in ("arm9", "arm7"):
        d = SRC / sub
        if not d.is_dir():
            continue
        for p in list(d.glob("*.c")) + list(d.glob("*.cpp")):
            head = p.read_text(encoding="utf-8", errors="ignore")[:600]
            if "// NONMATCHING:" in head:
                continue
            m = L.MARKER_RE.search(head)
            if m:
                module, addr, name = m.group(1), int(m.group(2), 16), m.group(3)
                out[(module, addr)] = name
    return out


def find_src_by_name(f):
    sub = "arm7" if f["module"] == "arm7" else "arm9"
    d = SRC / sub
    for cand in (d / f"{f['name']}.c", d / f"{f['name']}.cpp",
                 d / f"{f['name']}_{f['addr']:08x}.c",
                 d / f"{f['name']}_{f['addr']:08x}.cpp"):
        if cand.is_file():
            # Same NONMATCHING skip as scan_markers() - a parked file must not
            # be banked as a match via the filename fallback either.
            if "// NONMATCHING:" in cand.read_text(encoding="utf-8", errors="ignore")[:600]:
                return None
            return cand
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true", help="write progress/matched.jsonl")
    args = ap.parse_args()

    markers = scan_markers()
    found_marker, found_name, missing_addr = 0, 0, 0
    for f in F.load_funcs():
        if f["module"] is None:
            missing_addr += 1
            continue
        key = (f["module"], f["addr"])
        if key in markers:
            name, via = markers[key], "marker"
            found_marker += 1
        else:
            src = find_src_by_name(f)
            if not src:
                continue
            name, via = f["name"], "name"
            found_name += 1
        if args.apply:
            L.append_matched({"addr": f["addr"], "name": name, "size": f["size"],
                               "module": f["module"], "versions": [f"sync:{via}"]})

    total = found_marker + found_name
    print(f"{total} committed src/ file(s) matched back to a known function "
          f"({found_marker} via marker, {found_name} via filename fallback)"
          f"{' -> progress/matched.jsonl' if args.apply else ' (dry-run; pass --apply to write)'}")
    if missing_addr:
        print(f"  ({missing_addr} Ghidra function(s) fell outside every known module range "
              f"and were skipped - see tools/funcs.py)")


if __name__ == "__main__":
    main()
