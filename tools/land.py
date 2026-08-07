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
import pr_linkcheck as _linkcheck  # noqa: E402   this repo's own verification gate

REPO = pathlib.Path(__file__).resolve().parent.parent
_SYMBOL_IDX = _linkcheck.build_symbol_index()


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


def verify(c_path, name, row, version=None):
    """Re-run THIS repo's own gate - tools/pr_linkcheck.py. True only on VERIFIED.

    Deliberately not a match.py call with a size we chose. Here the comparison span comes from the
    compiled object, and the gate sweeps every pinned mwccarm version and both Thumb/ARM flag
    variants, because this title's canonical version is still a guess. Picking a size and a version
    ourselves failed 7 of 25 already-matched files that this gate verifies cleanly - it would have
    rejected real matches on their way into src/."""
    try:
        rel = str(pathlib.Path(c_path).resolve().relative_to(REPO)).replace("\\", "/")
    except ValueError:
        rel = str(c_path)
    try:
        rep = _linkcheck.check_file(rel, _SYMBOL_IDX)
    except Exception as e:
        return False, f"{type(e).__name__}: {e}"
    return rep.get("verdict") == "VERIFIED", (rep.get("detail") or rep.get("verdict") or "")


def with_header(code, name, row):
    """The `// decomp:` header the gate resolves a file's target from; //cpp stays first."""
    if "// decomp:" in code:
        return code
    hdr = f"// decomp: module={row['module']} addr={row['addr']} name={name}"
    lines = code.split("\n")
    at = 1 if lines and lines[0].strip().startswith("//cpp") else 0
    lines.insert(at, hdr)
    return "\n".join(lines)


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
        c_source = with_header(c_source, name, row)
        tmp = REPO / "extracted" / "_land" / f"{name}.{ext}"
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
            # ACTUALLY park it. This branch used to only append to a list, while the module
            # docstring ("near-misses parked as drafts") and the "kept as drafts" summary line
            # both claimed the draft had been saved. Nothing wrote it anywhere - no src file, no
            # nonmatching.jsonl - so every close attempt this tool ever saw was reported as kept
            # and silently dropped. That is precisely what the never-discard-a-close-attempt rule
            # exists to prevent, and it cost two div=3 drafts on 2026-08-07.
            if args.dry_run:
                parked.append(name)
                continue
            draft = REPO / "extracted" / "_land" / f"{name}.{ext}"
            draft.parent.mkdir(parents=True, exist_ok=True)
            draft.write_text(c_source, encoding="utf-8")
            try:
                p = subprocess.run(
                    [sys.executable, str(REPO / "tools" / "nonmatching.py"), "add",
                     "--c", str(draft), "--func", name, "--module", row["module"],
                     "--addr", str(row["addr"]), "--size", str(row["size"]),
                     "--reason", (f"drive near-miss: {detail or 'compiles, does not match'}")[:200]],
                    capture_output=True, text=True, check=False,
                )
                if p.returncode == 0:
                    parked.append(name)
                else:
                    # Loud, not silent: a refused park is still a lost draft unless someone sees it.
                    skipped.append((name, f"PARK FAILED: {(p.stderr or p.stdout).strip()[:140]}"))
            except OSError as e:
                skipped.append((name, f"PARK FAILED: {e}"))
            finally:
                draft.unlink(missing_ok=True)

    # The free tier, the way sm64ds's crackloop land does it (crackloop.py runs clone then
    # paramclone here). A function just banked is new material for the pattern tools - it can
    # be the template, or the byte-identical twin, that unlocks several more - so immediately
    # after banking is the cheapest moment to run them. This costs compiles, not model tokens,
    # and until now nothing ran it: these tools existed but only ever fired by hand.
    #
    # Only the two that bank on their own. twin.py searches and reports but has no banking
    # flag, so it stays a manual step. Never fatal: a post-pass failure must not cost us the
    # matches already banked above.
    if banked and not args.dry_run:
        for tool, extra in (("find_duplicates.py", ["--apply"]), ("templates.py", ["--apply"])):
            print(f"\n-- free tier: {tool} {' '.join(extra)}")
            try:
                subprocess.run(
                    [sys.executable, str(pathlib.Path(__file__).resolve().parent / tool), *extra],
                    check=False,
                )
            except OSError as e:
                print(f"   ({tool} did not run: {e})")
        print()

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
        # With reasons. A bare count hides the difference between "already done, nothing to do"
        # and "the draft could not be parked and is gone" - and the second is the one that costs
        # real work, so it must never be summarised into a number.
        print(f"skipped  : {len(skipped)}")
        for s in skipped:
            n, why = s if isinstance(s, tuple) else (s, "")
            print(f"  - {n}{f'  ({why})' if why else ''}")

    # Non-zero when the driver claimed matches that do not reproduce, so a caller notices.
    return 1 if rejected else 0


if __name__ == "__main__":
    sys.exit(main())
