"""The NONMATCHING hatch: park genuinely-unmatchable functions with
logic-correct C.

A function is NONMATCHING when its C compiles and has the RIGHT logic (the
oracle's word-mismatch count is small and reloc-aware) but cannot be made
byte-exact at this compiler tier - e.g. a base-address materialization
mwccarm folds differently than the ROM, or a similar backend
instruction-selection quirk. This is exactly what pret/pokediamond marks with
`#ifdef NONMATCHING`. It counts toward decompiled-but-not-matched, so the
progress numbers (tools/progress.py) stay honest.

Discipline (ported from sm64ds-decomp's tools/nonmatching.py): a function only
belongs here if it (a) compiles, (b) does NOT byte-match, and (c) is CLOSE
(divergence <= --max-div, default 12) - i.e. the logic is verified right and
only the codegen floor remains. Don't park something you just haven't figured
out yet; that's still a fresh target for tools/templates.py, tools/m2c_draft.py,
or the permuter (see notes/matching-style.md).

  progress/nonmatching.jsonl : local bookkeeping, one line per parked function
  src/arm{9,7}/<name>.c(pp)  : the logic-correct C with a // NONMATCHING header

Usage:
    python tools/nonmatching.py add --c cand.c --func NAME --module unk_autoload_0 \
        --addr 0x02320a64 --size 0x52 --reason "base materialization"
    python tools/nonmatching.py stats
"""
import argparse
import pathlib
import re
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import match as M    # noqa: E402
import ledger as L   # noqa: E402

HEADER = ("// NONMATCHING: {reason} (div={div}). Logic verified correct vs ROM; not\n"
          "// byte-matchable from C at mwccarm {version} (see notes/matching-style.md).\n"
          "// Counts as decompiled, not matched.\n")


def add(args):
    flags = args.flags or (M.DEFAULT_FLAGS_ARM7 if args.module == "arm7" else M.DEFAULT_FLAGS)
    cfile = pathlib.Path(args.c)
    src_text = cfile.read_text(encoding="utf-8")
    if not args.flags and re.search(r"\basm\b", src_text) and "-thumb" in flags:
        flags = flags.replace(" -thumb", "")

    target = M.target_bytes(args.module, args.addr, args.size)
    obj = M.compile_c(cfile, args.version, flags)
    if obj is None:
        sys.exit("nonmatching: candidate does not compile - fix it first, this hatch "
                  "is only for logic-correct-but-unmatchable C")
    code, relocs, _ = M.extract_func(obj, args.func)
    if code is None:
        sys.exit(f"nonmatching: symbol '{args.func}' not found in compiled object")
    ok, ndiff = M.compare(target, code, relocs, verbose=False)
    if ok:
        sys.exit("nonmatching: this candidate actually MATCHES - bank it as a real match "
                 "instead (tools/ledger.py), don't park it")
    if ndiff > args.max_div:
        sys.exit(f"nonmatching: {ndiff} word mismatches > --max-div {args.max_div} - "
                 f"this isn't close enough to be a codegen-floor park; keep iterating")

    marker = L.marker_for(args.module, args.addr, args.func)
    header = HEADER.format(reason=args.reason, div=ndiff, version=args.version)
    body = src_text if src_text.endswith("\n") else src_text + "\n"
    if body.startswith("//cpp"):
        first, rest = body.split("\n", 1)
        body = first + "\n" + marker + header + rest
    else:
        body = marker + header + body

    st = L.append_nonmatching({"addr": args.addr, "name": args.func, "size": args.size,
                                "module": args.module, "divergences": ndiff,
                                "reason": args.reason})
    if not st:
        sys.exit("nonmatching: already matched or parked at this (module, addr)")
    ext = "cpp" if body.startswith("//cpp") else "c"
    out = L.src_path(args.module, args.func, ext)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(body, encoding="utf-8")
    print(f"parked {args.func} @ 0x{args.addr:08x} ({ndiff} word mismatch(es)) -> "
          f"{out.relative_to(REPO)}")


def stats(args):
    n = sum(1 for _ in L.read_records(L.NONMATCHING))
    print(f"{n} function(s) parked in progress/nonmatching.jsonl")
    by_reason = {}
    for r in L.read_records(L.NONMATCHING):
        by_reason[r.get("reason", "?")] = by_reason.get(r.get("reason", "?"), 0) + 1
    for reason, count in sorted(by_reason.items(), key=lambda kv: -kv[1]):
        print(f"  {count:4}  {reason}")


def main():
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest="cmd", required=True)

    a = sub.add_parser("add")
    a.add_argument("--c", required=True)
    a.add_argument("--func", required=True)
    a.add_argument("--module", default="unk_autoload_0", choices=list(M.MODULES))
    a.add_argument("--addr", type=lambda x: int(x, 0), required=True)
    a.add_argument("--size", type=lambda x: int(x, 0), required=True)
    a.add_argument("--reason", required=True)
    a.add_argument("--max-div", type=int, default=12)
    a.add_argument("--version", default=M.CANONICAL)
    a.add_argument("--flags", default=None)
    a.set_defaults(handler=add)

    s = sub.add_parser("stats")
    s.set_defaults(handler=stats)

    args = ap.parse_args()
    args.handler(args)


if __name__ == "__main__":
    main()
