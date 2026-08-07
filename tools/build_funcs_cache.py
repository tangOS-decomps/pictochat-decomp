"""Build extracted/pictochat_funcs.json from the Ghidra metadata export + the extracted ROM.

The Ghidra export carries each function's cpu/name/addr/size/mode but not its bytes, because
bytes are ROM-derived and nothing ROM-derived is committed. This joins the two: for every
function whose module was actually extracted, slice its bytes out of that module's binary.

Functions in a module that has not been extracted are written WITHOUT bytes rather than
dropped, so the cache still describes the whole corpus and tools can tell "not extracted"
apart from "does not exist".

Usage:
    python tools/build_funcs_cache.py --metadata path/to/pictochat_funcs_metadata.json
"""
import argparse
import json
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

from match import MODULES, DSD_EXTRACT  # noqa: E402
import funcs as funcs_mod  # noqa: E402

REPO = pathlib.Path(__file__).resolve().parent.parent
OUT = REPO / "extracted" / "pictochat_funcs.json"
# The flat extraction writes these; for ARM7 the flat blob IS the whole module (one segment
# loaded at 0x022C0000), so it is byte-identical to what dsd produces. ARM9 is multi-segment,
# so its flat blob is only correct for the first ~0x800 - see notes/pictochat-layout.md.
FLAT_FALLBACK = {"arm7": REPO / "extracted" / "pictochat_arm7_dec.bin"}


def module_blob(module):
    """(bytes, base) for a module, or (None, base) when it hasn't been extracted."""
    rel, base = MODULES[module]
    p = DSD_EXTRACT / rel
    if p.is_file():
        return p.read_bytes(), base
    flat = FLAT_FALLBACK.get(module)
    if flat and flat.is_file():
        return flat.read_bytes(), base
    return None, base


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--metadata", required=True, help="the Ghidra function metadata export (JSON list)")
    ap.add_argument("--out", default=str(OUT))
    args = ap.parse_args()

    meta = json.loads(pathlib.Path(args.metadata).read_text(encoding="utf-8"))
    blobs = {m: module_blob(m) for m in MODULES}

    out, with_bytes, missing = [], 0, {}
    for f in meta:
        rec = dict(f)
        module = funcs_mod.module_for(f["cpu"], f["addr"])
        data, base = blobs.get(module, (None, 0))
        if data is None:
            missing[module] = missing.get(module, 0) + 1
            out.append(rec)
            continue
        off = f["addr"] - base
        # Take generously here: true_size() needs to see past the cached size to find the
        # trailing literal pool, so hand it the gap too and let it decide the boundary.
        end = min(len(data), off + f["size"] + 0x40)
        if off < 0 or off >= len(data):
            missing[module] = missing.get(module, 0) + 1
            out.append(rec)
            continue
        rec["bytes"] = data[off : off + f["size"]].hex()
        rec["gap_bytes"] = data[off + f["size"] : end].hex()
        out.append(rec)
        with_bytes += 1

    pathlib.Path(args.out).write_text(json.dumps(out), encoding="utf-8")
    print(f"{len(out)} functions -> {args.out}")
    print(f"  with ROM bytes : {with_bytes}")
    for m, n in sorted(missing.items()):
        print(f"  NOT extracted  : {m} ({n} functions)")


if __name__ == "__main__":
    main()
