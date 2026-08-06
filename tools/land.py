"""Bank a finished drive: matched sources into src/, near-misses parked as drafts.

Reads the results file a driver wrote (--output) plus the worklist it ran (--wl), and for
every candidate it claims to have matched, RE-VERIFIES it here before banking. Nothing is
trusted on the driver's say-so: it reports what its own compile said, and a driver bug, a
stale worklist row or a wrong --size would otherwise land a file that does not reproduce
the ROM. The byte gate is the only thing that decides.

Anything that compiles but does not match is parked as NONMATCHING rather than dropped -
it is the best starting point for a later attempt, and losing it is losing real work.

Usage (this is how tangOS Console invokes it):
    python tools/land.py --output results.json --wl worklist.jsonl
"""
import argparse
import json
import pathlib
import subprocess
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

import ledger  # noqa: E402
import match as match_mod  # noqa: E402

REPO = pathlib.Path(__file__).resolve().parent.parent


def load_worklist(path):
    rows = {}
    if not path:
        return rows
    p = pathlib.Path(path)
    if not p.is_file():
        return rows
    for line in p.read_text(encoding="utf-8").splitlines():
        line = line.strip()
        if not line:
            continue
        try:
            r = json.loads(line)
        except Exception:
            continue
        if r.get("name"):
            rows[r["name"]] = r
    return rows


def verify(c_path, name, row, version):
    """Re-run the byte gate ourselves. True only on a real match."""
    cmd = [
        sys.executable,
        str(REPO / "tools" / "match.py"),
        "--c", str(c_path),
        "--func", name,
        "--addr", str(row["addr"]),
        "--size", str(row["size"]),
        "--module", row["module"],
        "--brief",
    ]
    if version:
        cmd += ["--version", version]
    try:
        out = subprocess.run(cmd, capture_output=True, text=True, timeout=600)
    except subprocess.TimeoutExpired:
        return False, "verify timed out"
    text = (out.stdout or "") + (out.stderr or "")
    ok = "MATCHING VERSIONS: none" not in text and ": MATCH" in text
    return ok, text.strip().splitlines()[-1] if text.strip() else ""


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--output", required=True, help="the driver's results JSON")
    ap.add_argument("--wl", default=None, help="the worklist that drive ran (for addr/size/module)")
    ap.add_argument("--version", default=None, help="compiler version to verify with (default: canonical)")
    ap.add_argument("--no-claims", action="store_true", help="accepted for compatibility; this repo has no claims board")
    ap.add_argument("--dry-run", action="store_true", help="verify and report, bank nothing")
    args = ap.parse_args()

    results_path = pathlib.Path(args.output)
    if not results_path.is_file():
        sys.exit(f"{results_path} not found - the driver wrote no results")
    data = json.loads(results_path.read_text(encoding="utf-8"))
    rows = load_worklist(args.wl)

    banked, rejected, parked, skipped = [], [], [], []

    # The driver writes matched C into `sources` (name -> text) and compiling-but-not-matching
    # drafts into `nearMisses`; `results` carries only the verdicts. Older files that inlined
    # c_source on the result still work.
    sources = dict(data.get("sources") or {})
    for nm in data.get("nearMisses") or []:
        if nm.get("name") and nm.get("c_source"):
            sources.setdefault(nm["name"], nm["c_source"])

    for cand in data.get("candidates") or data.get("results") or []:
        name = cand.get("name")
        c_source = cand.get("c_source") or sources.get(name)
        if not name or not c_source:
            continue
        row = rows.get(name) or cand
        if not all(row.get(k) for k in ("addr", "size", "module")):
            skipped.append((name, "no addr/size/module to verify against"))
            continue

        key = ledger.make_key(row["module"], int(str(row["addr"]), 0))
        if key in ledger.load_done():
            skipped.append((name, "already matched or parked"))
            continue

        ext = "cpp" if c_source.lstrip().startswith("//cpp") else "c"
        tmp = REPO / "extracted" / f"_land_{name}.{ext}"
        tmp.parent.mkdir(parents=True, exist_ok=True)
        tmp.write_text(c_source, encoding="utf-8")
        try:
            ok, detail = verify(tmp, name, row, args.version)
        finally:
            tmp.unlink(missing_ok=True)

        record = {
            "module": row["module"],
            "addr": int(str(row["addr"]), 0),
            "name": name,
            "version": args.version or match_mod.CANONICAL,
        }
        if ok:
            if args.dry_run:
                banked.append(name)
                continue
            res = ledger.bank(record, c_source)
            (banked if res != "dup" else skipped).append(name if res != "dup" else (name, "dup"))
        elif cand.get("matched"):
            # The driver said matched and the byte gate disagrees. That is the case this whole
            # re-verify exists for; say so loudly rather than banking it.
            rejected.append((name, detail))
        else:
            parked.append(name)

    print(f"banked   : {len(banked)}")
    for n in banked:
        print(f"  + {n}")
    if rejected:
        print(f"REJECTED : {len(rejected)}  (driver claimed a match the byte gate refused)")
        for n, d in rejected:
            print(f"  ! {n}  {d}")
    if parked:
        print(f"near-miss: {len(parked)} (kept as drafts, not matched)")
    if skipped:
        print(f"skipped  : {len(skipped)}")

    # Non-zero when the driver claimed matches that do not reproduce, so a caller notices.
    return 1 if rejected else 0


if __name__ == "__main__":
    sys.exit(main())
