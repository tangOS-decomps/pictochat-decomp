#!/usr/bin/env python3
"""Batch Ghidra drafts, with the project ALIGNED to what this repo already knows.

Two separate problems with drafting the ~1250 unmatched functions:

1. COST. tools/ghidra_draft.py starts a JVM and opens the project per call, so
   drafting is several seconds each. Opening once and decompiling N functions
   makes bulk drafting practical.

2. QUALITY, which matters more. Ghidra decompiles each function in isolation
   against whatever it inferred, and its inferences are wrong in ways this repo
   has already corrected:

     * Every already-matched function has a KNOWN, byte-verified signature -
       argument count, widths, return type. Ghidra usually guessed. A caller
       decompiled against a wrong callee signature gets the wrong number of
       arguments and invented casts, which is exactly the noise that makes a
       draft hard to turn into a match. Pushing 300 known signatures in fixes
       every caller of them at once. (FUN_02331a58 is the cautionary case: it
       was submitted as a 1-argument call when the ROM stores TWO parameters -
       a wrong signature that would propagate into every caller drafted
       against it.)

     * Ghidra's function boundaries exclude trailing literal pools for ~42% of
       this ROM's functions (funcs.true_size()), so it can decompile with a
       constant it never sees.

This applies both IN MEMORY and does not save the project, so it is safe to run
against a shared project file - re-run it whenever more functions get matched
and the drafts get better each time.

    python tools/ghidra_batch.py --limit 20                  # smallest unmatched
    python tools/ghidra_batch.py --name FUN_02320938
    python tools/ghidra_batch.py --limit 50 --out scratch/drafts
    python tools/ghidra_batch.py --limit 5 --no-align        # compare quality

Drafts are written as `<out>/<name>.c` with a `// decomp:` marker and the
verify command already in the header, so a draft can go straight into
scratch/batch/ for tools/verify_batch.py once edited into shape.
"""
import argparse
import json
import os
import pathlib
import re
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import funcs as F   # noqa: E402
import match as M   # noqa: E402

GHIDRA_INSTALL_DIR = os.environ.get("GHIDRA_INSTALL_DIR", r"G:\Progams\ghidra_12.1.2_PUBLIC")
PROJECT_DIR = REPO / "ghidra_project"
PROJECT_NAME = "ndsfw"
PROGRAM_FOR = {"arm7": "pictochat_arm7_analyzed.bin"}
DEFAULT_PROGRAM = "pictochat_arm9_segmented.bin"

# `void FUN_x(int a, short *b)` / `unsigned short FUN_x(void)` in a banked file.
SIG_RE = re.compile(
    r"^\s*(?!return|else|if|while|for|switch)"
    r"((?:unsigned |signed |const |volatile |struct )*[A-Za-z_]\w*\s*\**)\s*"
    r"(FUN_[0-9a-fA-F]{8}|[A-Za-z_]\w*)\s*\(([^;{)]*)\)\s*\{", re.M)


def known_signatures():
    """{name: (ret, [param, ...])} for every banked, byte-verified match."""
    out = {}
    for sub in ("arm9", "arm7"):
        d = REPO / "src" / sub
        if not d.is_dir():
            continue
        for p in list(d.glob("*.c")) + list(d.glob("*.cpp")):
            txt = p.read_text(encoding="utf-8", errors="ignore")
            for ret, name, params in SIG_RE.findall(txt):
                if name != p.stem:
                    continue          # only the file's own function
                ps = [x.strip() for x in params.split(",") if x.strip() and x.strip() != "void"]
                out[name] = (ret.strip(), ps)
    return out


def pick_targets(args, done):
    funcs = [f for f in F.load_funcs() if f.get("module")]
    if args.name:
        sel = [f for f in funcs if f["name"] in set(args.name)]
        if not sel:
            sys.exit(f"no such function: {args.name}")
        return sel
    un = [f for f in funcs if (f["module"], f["addr"]) not in done]
    if args.module:
        un = [f for f in un if f["module"] == args.module]
    un = [f for f in un if args.min <= f["size"] <= args.max]
    un.sort(key=lambda f: (f["size"], f["addr"]))
    return un[:args.limit]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--name", action="append", default=None)
    ap.add_argument("--module", default=None, choices=list(M.MODULES))
    ap.add_argument("--limit", type=int, default=20)
    ap.add_argument("--min", type=lambda x: int(x, 0), default=0)
    ap.add_argument("--max", type=lambda x: int(x, 0), default=0x200)
    ap.add_argument("--out", default="scratch/drafts")
    ap.add_argument("--no-align", action="store_true",
                    help="skip pushing known signatures in (to compare draft quality)")
    args = ap.parse_args()

    import ledger as L
    done = L.load_done()
    targets = pick_targets(args, done)
    if not targets:
        sys.exit("nothing to draft")
    sigs = {} if args.no_align else known_signatures()
    outdir = pathlib.Path(args.out)
    outdir.mkdir(parents=True, exist_ok=True)
    print(f"drafting {len(targets)} function(s); "
          f"{len(sigs)} known signature(s) to apply", file=sys.stderr)

    os.environ.setdefault("GHIDRA_INSTALL_DIR", GHIDRA_INSTALL_DIR)
    import pyghidra
    pyghidra.start()
    from ghidra.base.project import GhidraProject
    from ghidra.app.decompiler import DecompInterface
    from ghidra.util.task import ConsoleTaskMonitor
    from ghidra.program.model.symbol import SourceType
    from ghidra.program.model.listing import ParameterImpl, Function
    from ghidra.program.model.data import Undefined4DataType
    from java.util import ArrayList

    by_program = {}
    for f in targets:
        by_program.setdefault(PROGRAM_FOR.get(f["module"], DEFAULT_PROGRAM), []).append(f)

    proj = GhidraProject.openProject(str(PROJECT_DIR), PROJECT_NAME, True)
    written, failed, applied, errors = 0, [], 0, []
    try:
        for program_name, fs in by_program.items():
            prog = proj.openProgram("/", program_name, True)
            try:
                fm = prog.getFunctionManager()
                af = prog.getAddressFactory()

                # --- alignment: teach Ghidra the signatures we have PROVEN ---
                if sigs:
                    # One pass to build name -> Function; FunctionManager only
                    # looks up by numeric id, and re-scanning per signature
                    # would be O(functions * signatures).
                    by_name = {}
                    for cand in fm.getFunctions(True):
                        by_name.setdefault(str(cand.getName()), cand)
                    txn = prog.startTransaction("align known signatures")
                    try:
                        for name, (ret, ps) in sigs.items():
                            gf = by_name.get(name)
                            if gf is None:
                                continue
                            # Parameter COUNT is what actually changes a
                            # caller's decompilation; exact widths matter less
                            # and are riskier to force.
                            if gf.getParameterCount() == len(ps):
                                continue
                            try:
                                lst = ArrayList()      # must be a java.util.List,
                                for i in range(len(ps)):   # a Python list finds no overload
                                    lst.add(ParameterImpl(f"a{i}", Undefined4DataType(), prog))
                                gf.replaceParameters(
                                    lst, Function.FunctionUpdateType.DYNAMIC_STORAGE_FORMAL_PARAMS,
                                    True, SourceType.USER_DEFINED)
                                applied += 1
                            except Exception as e:
                                errors.append(f"{name}: {type(e).__name__}: {str(e)[:90]}")
                    finally:
                        prog.endTransaction(txn, True)

                decomp = DecompInterface()
                decomp.openProgram(prog)
                for f in fs:
                    gf = fm.getFunctionContaining(af.getAddress(f"{f['addr']:08x}"))
                    if gf is None:
                        failed.append((f["name"], "no function at that address in Ghidra"))
                        continue
                    res = decomp.decompileFunction(gf, 30, ConsoleTaskMonitor())
                    if not res.decompileCompleted():
                        failed.append((f["name"], res.getErrorMessage()))
                        continue
                    c = res.getDecompiledFunction().getC()
                    ts = F.true_size(f)
                    hdr = (f"// decomp: module={f['module']} addr=0x{f['addr']:08x} name={f['name']}\n"
                           f"// GHIDRA DRAFT - a reading aid, NOT a matching candidate.\n"
                           f"// size {ts:#x}"
                           + (f" (Ghidra's cache says {f['size']:#x} - it excludes this "
                              f"function's trailing literal pool)" if ts != f["size"] else "")
                           + f", {f['mode']}\n"
                           f"// verify:  python tools/match.py --c <file> --func {f['name']} "
                           f"--addr 0x{f['addr']:08x} --size {ts:#x} --module {f['module']} "
                           f"--version {M.CANONICAL}\n\n")
                    (outdir / f"{f['name']}.c").write_text(hdr + c, encoding="utf-8")
                    written += 1
            finally:
                proj.close(prog)
    finally:
        proj.close()

    print(f"\nwrote {written} draft(s) to {outdir}"
          + (f"; applied {applied} signature correction(s)" if sigs else ""), file=sys.stderr)
    for n, why in failed:
        print(f"  FAILED {n}: {why}", file=sys.stderr)
    for e in errors[:5]:
        print(f"  signature not applied - {e}", file=sys.stderr)
    return 0 if written else 1


if __name__ == "__main__":
    sys.exit(main())
