"""Pick the next functions to attack, and write them as a worklist.

This is the scheduler tangOS Console drives: it asks for `--limit` targets and reads
back JSONL, one row per function. It is also the `enrich` step - `--addr` pins one
exact function - and the Random role, via `--random`.

Two corpora, in preference order:

  extracted/pictochat_funcs.json   the Ghidra export. Has each function's ROM bytes, so
                                   rows can carry target_hex and the true pool-inclusive
                                   size. Requires your own dumps (see README).
  chaos-db.json                    the published progress data. Committed, ROM-free, and
                                   enough to SELECT targets: module, addr, size, matched.

The fallback matters: selecting targets needs no ROM, so a contributor who has not
extracted anything yet can still queue work and let their agent pull context with
disasm.py / fdiff.py per function. Rows are thinner (no target_hex), which Console
handles - it treats those fields as optional.

Already-done functions are excluded via tools/ledger.py, which knows both the matched
set and the parked-nonmatching set, so a target that someone already banked or parked
is never handed out again.
"""
import argparse
import json
import pathlib
import random
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

import ledger  # noqa: E402

REPO = pathlib.Path(__file__).resolve().parent.parent
CHAOS_DB = REPO / "chaos-db.json"
FUNCS_CACHE = REPO / "extracted" / "pictochat_funcs.json"
MODULES = ("main", "itcm", "unk_autoload_0", "unk_autoload_2", "arm7")


def _from_ghidra():
    """The rich corpus: every function with its ROM bytes. None when not extracted."""
    if not FUNCS_CACHE.is_file():
        return None
    try:
        import funcs as funcs_mod
    except Exception:
        return None
    try:
        all_funcs = funcs_mod.load_funcs()
    except SystemExit:
        return None
    out = []
    for f in all_funcs:
        try:
            size = funcs_mod.true_size(f, all_funcs)
        except Exception:
            size = f.get("size", 0)
        out.append(
            {
                "name": f["name"],
                "module": f["module"],
                "addr": int(f["addr"]),
                "size": int(size),
                "bytes": f.get("bytes"),
                "mode": f.get("mode"),
            }
        )
    return out


def _from_chaos_db():
    """The ROM-free corpus: enough to choose targets, not to embed their bytes."""
    if not CHAOS_DB.is_file():
        sys.exit(
            f"{CHAOS_DB.name} not found and extracted/ is absent, so there is no corpus to "
            f"schedule from. Run `python tools/chaos_db_ci.py --out chaos-db.json`, or fetch the "
            f"published copy from the chaos-data branch."
        )
    db = json.loads(CHAOS_DB.read_text(encoding="utf-8"))
    return [
        {
            "name": f["name"],
            "module": f["module"],
            "addr": int(f["addr"]),
            "size": int(f.get("size") or 0),
            "bytes": None,
            "mode": None,
            "matched": bool(f.get("matched")),
        }
        for f in db.get("functions", [])
    ]


def _chaos_matched_keys():
    """Keys of everything chaos-db says is matched.

    progress/matched.jsonl is gitignored, so on a fresh clone (or any machine where nobody has
    run sync_ledger yet) the ledger reports zero matches and every already-done function looks
    available. chaos-db is committed and derived from what is actually in src/, so it is the
    backstop that keeps a stale ledger from handing out finished work.
    """
    if not CHAOS_DB.is_file():
        return set()
    try:
        db = json.loads(CHAOS_DB.read_text(encoding="utf-8"))
    except Exception:
        return set()
    return {
        ledger.make_key(f["module"], int(f["addr"]))
        for f in db.get("functions", [])
        if f.get("matched")
    }


def load_corpus():
    rich = _from_ghidra()
    return (rich, True) if rich else (_from_chaos_db(), False)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--module", choices=MODULES, default=None)
    ap.add_argument("--min", type=lambda x: int(x, 0), default=0x8, help="smallest function size to offer")
    ap.add_argument("--max", type=lambda x: int(x, 0), default=0x200, help="largest function size to offer")
    ap.add_argument("--limit", type=int, default=24)
    ap.add_argument("--random", action="store_true", help="shuffle rather than smallest-first")
    ap.add_argument("--addr", default=None, help="pin ONE function by address; ignores the size filters")
    ap.add_argument("--out", default=None, help="write JSONL here; omit to stream to stdout")
    ap.add_argument("--include-done", action="store_true", help="do not filter out matched/parked functions")
    ap.add_argument(
        "--include-attempted",
        action="store_true",
        help="offer functions PARKED as nonmatching - the ones that already carry a draft to "
        "improve, rather than untouched ones. This is the refine pass.",
    )
    args = ap.parse_args()

    corpus, rich = load_corpus()
    matched_keys = ledger.matched_set() | _chaos_matched_keys()
    if args.include_attempted:
        # Refine mode: parked drafts are exactly the pool we want, so they are the corpus rather
        # than an exclusion. Still skip anything actually matched.
        parked = ledger.nonmatching_set()
        done = matched_keys
        corpus = [f for f in corpus if ledger.make_key(f["module"], f["addr"]) in parked]
    else:
        done = set() if args.include_done else (ledger.load_done() | matched_keys)

    if args.addr is not None:
        # Enrich mode: one exact function, whatever its size. The size filters would
        # silently drop anything over --max, which is how a hand-picked target ends up
        # reported as "could not be enriched".
        want = int(args.addr, 0)
        rows = [f for f in corpus if f["addr"] == want]
        if args.module:
            rows = [f for f in rows if f["module"] == args.module]
        if not rows:
            sys.exit(f"no function at {args.addr}" + (f" in {args.module}" if args.module else ""))
    else:
        rows = []
        for f in corpus:
            if args.module and f["module"] != args.module:
                continue
            if f.get("matched"):
                continue
            if ledger.make_key(f["module"], f["addr"]) in done:
                continue
            if not (args.min <= f["size"] <= args.max):
                continue
            rows.append(f)
        # Smallest first is the useful default: short functions match more often per unit of
        # effort, so a batch of them lands more work than the same count of large ones.
        if args.random:
            random.shuffle(rows)
        else:
            rows.sort(key=lambda f: (f["size"], f["addr"]))
        rows = rows[: args.limit]

    lines = []
    for f in rows:
        row = {
            "name": f["name"],
            "module": f["module"],
            "addr": f"0x{f['addr']:08x}",
            "size": f"0x{f['size']:x}",
        }
        if f.get("bytes"):
            row["target_hex"] = f["bytes"]
        if f.get("mode"):
            row["mode"] = f["mode"]
        lines.append(json.dumps(row))

    text = "\n".join(lines)
    if args.out:
        pathlib.Path(args.out).write_text(text + ("\n" if text else ""), encoding="utf-8")
        src = "extracted/ (with ROM bytes)" if rich else "chaos-db.json (no ROM bytes)"
        print(f"{len(lines)} target(s) -> {args.out}   [corpus: {src}]")
    else:
        print(text)


if __name__ == "__main__":
    main()
