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
import difflib
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


def _chaos_modules():
    """name -> module, from the committed progress data.

    funcs.module_for resolves ARM9's four segments from boundaries the dsd extraction
    produces, so on a partial extraction it returns None for every ARM9 function. chaos-db
    already records each function's module, so it fills those in - a row with a null module
    is useless to an agent, which has to pass --module to every tool.
    """
    if not CHAOS_DB.is_file():
        return {}
    try:
        db = json.loads(CHAOS_DB.read_text(encoding="utf-8"))
    except Exception:
        return {}
    return {f["name"]: f["module"] for f in db.get("functions", []) if f.get("module")}


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
    fallback_modules = _chaos_modules()
    out = []
    for f in all_funcs:
        try:
            size = int(funcs_mod.true_size(f, all_funcs))
        except Exception:
            size = int(f.get("size", 0))
        # true_size reaches PAST Ghidra's cached size to take in the trailing literal pool
        # mwccarm emits inside the function, so the target bytes have to be re-cut to the same
        # span. Handing out the cached-size bytes with the true size is how a candidate ends up
        # compared against a target that stops short, which reads as a codegen bug and is not one.
        span = None
        if f.get("bytes") is not None:
            span = (f["bytes"] + (f.get("gap_bytes") or ""))[: size * 2]
            if len(span) < size * 2:
                span = None  # not enough extracted to cover the true span; better none than short
        out.append(
            {
                "name": f["name"],
                "module": f.get("module") or fallback_modules.get(f["name"]),
                "addr": int(f["addr"]),
                "size": size,
                "bytes": span,
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


# ---------------------------------------------------------------------------
# Similarity ranking (--similar)
#
# Smallest-first asks "what is cheapest to attempt". This asks "what most resembles something
# already solved", and hands the model those solved functions as worked examples. sm64ds's
# equivalent (tools/coddog.py) took that repo from a ~50% to a ~71% per-target hit rate, so it
# is worth having here - but the ranking is only as good as the example pool, which is why a
# parked NONMATCHING draft is never offered as one.
# ---------------------------------------------------------------------------

_DECODERS = {}


def _decoder(mode):
    """Capstone decoder for a function's instruction set.

    Mode matters far more here than on an all-ARM repo: PictoChat is mostly Thumb (1078 of
    1551 functions), so decoding everything as ARM would turn most of the corpus into garbage
    mnemonics and rank on the garbage."""
    import capstone

    key = "thumb" if mode == "thumb" else "arm"
    if key not in _DECODERS:
        _DECODERS[key] = capstone.Cs(
            capstone.CS_ARCH_ARM,
            capstone.CS_MODE_THUMB if key == "thumb" else capstone.CS_MODE_ARM,
        )
    return _DECODERS[key]


def _opseq(hex_bytes, mode):
    """A function's mnemonic sequence, or () when its bytes were not extracted."""
    if not hex_bytes:
        return ()
    try:
        raw = bytes.fromhex(hex_bytes)
    except ValueError:
        return ()
    return tuple(i.mnemonic for i in _decoder(mode).disasm(raw, 0))


def _src_text(name, module):
    """The committed source for a function, or None. arm7 lives in src/arm7/, everything else
    in src/arm9/ (the dirs are per-processor, not per-module)."""
    d = REPO / "src" / ("arm7" if module == "arm7" else "arm9")
    for ext in (".c", ".cpp"):
        p = d / f"{name}{ext}"
        if p.is_file():
            try:
                return p.read_text(encoding="utf-8")
            except OSError:
                return None
    return None


def _jaccard(a, b):
    return len(a & b) / len(a | b) if (a or b) else 0.0


def _parked_divergences():
    """addr -> recorded divergence count for every parked NONMATCHING draft."""
    out = {}
    p = REPO / "progress" / "nonmatching.jsonl"
    if not p.is_file():
        return out
    for line in p.read_text(encoding="utf-8").splitlines():
        line = line.strip()
        if not line:
            continue
        try:
            r = json.loads(line)
            out[int(str(r["addr"]), 0)] = r.get("divergences")
        except (ValueError, KeyError):
            continue
    return out


def _example_pool(corpus, matched_keys):
    """Functions usable as worked examples: matched, with extractable bytes, and carrying a
    committed source that is NOT a parked `// NONMATCHING` draft. Showing a model a draft that
    is known not to reproduce the ROM teaches it the wrong shape."""
    pool = []
    for f in corpus:
        if ledger.make_key(f["module"], f["addr"]) not in matched_keys:
            continue
        ops = _opseq(f.get("bytes"), f.get("mode"))
        if not ops:
            continue
        src = _src_text(f["name"], f["module"])
        if src is None or "// NONMATCHING" in src[:200]:
            continue
        pool.append({"name": f["name"], "ops": ops, "opset": frozenset(ops), "src": src})
    return pool


def _top_siblings(target_ops, pool, k, jmin, lenlo=0.5, lenhi=2.0):
    """The k most opcode-similar examples: a cheap length window and set-overlap prune, then a
    real sequence ratio on whatever survives (autojunk off - it misfires on code)."""
    n = len(target_ops)
    tset = frozenset(target_ops)
    scored = []
    for m in pool:
        lm = len(m["ops"])
        if lm < n * lenlo or lm > n * lenhi:
            continue
        if _jaccard(tset, m["opset"]) < jmin:
            continue
        scored.append((difflib.SequenceMatcher(None, target_ops, m["ops"], autojunk=False).ratio(), m))
    scored.sort(key=lambda x: -x[0])
    return scored[:k]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--module", choices=MODULES, default=None)
    # Default floor is 0x9, not 0x8, because the <=8-byte tier is worked out: 108 of its 113
    # functions are matched and the 5 left are the residue that cannot be written in C at all -
    # bare `swp` primitives and conditional-return fragments whose declared size is wrong.
    # Smallest-first therefore handed an agent the same unmatchable three every single run.
    ap.add_argument("--min", type=lambda x: int(x, 0), default=0x9, help="smallest function size to offer")
    ap.add_argument("--max", type=lambda x: int(x, 0), default=0x200, help="largest function size to offer")
    ap.add_argument("--limit", type=int, default=24)
    ap.add_argument("--random", action="store_true", help="shuffle rather than smallest-first")
    # Similarity ranking is the DEFAULT, falling back to smallest-first automatically when it
    # cannot rank (no extracted/, or nothing matched yet to compare against). It shipped opt-in
    # "until it has a measured hit rate on this repo", which was a mistake: nothing that calls this
    # tool passes flags, so it could never be turned on and therefore could never earn one.
    # Meanwhile smallest-first is a stable sort, so it re-serves the same unworkable head every
    # run - two separate drives spent their whole budget on FUN_0232dc4c / FUN_0232e6bc /
    # FUN_0232e9a8 before anyone noticed they were the first three either way.
    ap.add_argument("--similar", dest="similar", action="store_true", default=None,
                    help="force similarity ranking (already the default wherever it can rank)")
    ap.add_argument("--no-similar", dest="similar", action="store_false",
                    help="plain smallest-first: skip similarity ranking and worked examples")
    ap.add_argument("--k", type=int, default=2, help="--similar: worked examples attached per target")
    ap.add_argument(
        "--jmin", type=float, default=0.55,
        help="--similar: minimum opcode-set overlap to consider an example at all (prune)",
    )
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
    # Worked examples always come from the FULL corpus. Refine mode narrows `corpus` to parked
    # functions, and building the example pool from that would search a set with nothing matched
    # in it - reporting "similarity ranking unavailable" on a repo that has 449 matched functions
    # sitting right there.
    full_corpus = corpus
    matched_keys = ledger.matched_set() | _chaos_matched_keys()
    if args.include_attempted:
        # Refine mode: parked drafts are exactly the pool we want, so they are the corpus rather
        # than an exclusion. Still skip anything actually matched.
        parked = ledger.nonmatching_set()
        done = matched_keys
        corpus = [f for f in corpus if ledger.make_key(f["module"], f["addr"]) in parked]
        # Attach each parked draft and its recorded divergence count. A refine target without its
        # draft is just a from-scratch target wearing a different label.
        divs = _parked_divergences()
        for f in corpus:
            src = _src_text(f["name"], f["module"])
            if src:
                f["draft"] = src
                f["divergences"] = divs.get(f["addr"])
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
        pool = [] if args.similar is False else _example_pool(full_corpus, matched_keys)
        if args.similar is not False and not pool:
            # Cannot rank: no extracted/ ROM bytes, or nothing matched yet to compare against.
            # Fall back rather than exit - being the default means never refusing to produce a
            # worklist. Explicit --similar still says so out loud, since the user asked for it.
            print("similarity ranking unavailable (needs extracted/ and matched sources) - "
                  "falling back to smallest-first", file=sys.stderr)
        if pool:
            ranked = []
            for f in rows:
                ops = _opseq(f.get("bytes"), f.get("mode"))
                if not ops:
                    continue  # no bytes extracted: unrankable, and unshowable to a model anyway
                sibs = _top_siblings(ops, pool, args.k, args.jmin)
                f = dict(f)
                f["_sim"] = sibs[0][0] if sibs else 0.0
                f["_sibs"] = sibs
                ranked.append(f)
            # Best resemblance first. Size breaks ties so an unrankable-but-tiny function still
            # sorts ahead of an unrankable large one.
            ranked.sort(key=lambda f: (-f["_sim"], f["size"], f["addr"]))
            rows = ranked
        elif args.random:
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
        if f.get("draft"):
            # THE POINT of a refine pass: hand back the parked draft and how far off it is, so the
            # model improves it instead of rewriting from zero. Without this, refine mode selected
            # the right functions and then threw away the very work that made them worth selecting -
            # a draft sitting 3 words from byte-exact was being re-derived from scratch every run.
            row["draft"] = f["draft"]
            if f.get("divergences") is not None:
                row["divergences"] = f["divergences"]
        if f.get("_sibs") is not None:
            # Field names match sm64ds's coddog worklist rows on purpose: drive.py speaks that
            # same protocol, so one driver reads either repo's worklist without a special case.
            row["coddog_sim"] = round(f["_sim"], 4)
            row["siblings"] = [{"name": m["name"], "sim": round(r, 4)} for r, m in f["_sibs"]]
            row["examples"] = [{"name": m["name"], "c_source": m["src"]} for _, m in f["_sibs"]]
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
