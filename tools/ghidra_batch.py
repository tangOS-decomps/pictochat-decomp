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


def _split_decl(decl):
    """`unsigned short *p` -> ("unsigned short *", "p"). A parameter may also be
    a bare type with no name (`int`), in which case the name is empty."""
    d = decl.strip()
    m = re.match(r"^(.*?)([A-Za-z_]\w*)$", d)
    if not m or not m.group(1).strip():
        return d, ""
    return m.group(1).strip(), m.group(2)


def ghidra_type(dt, prog):
    """Map one of this repo's C type spellings onto a Ghidra data type.

    Only the spellings that actually occur in banked matches are handled; an
    unknown one returns None and the caller falls back to leaving Ghidra's own
    guess alone, which is strictly better than forcing a wrong type in."""
    from ghidra.program.model.data import (
        VoidDataType, IntegerDataType, UnsignedIntegerDataType, ShortDataType,
        UnsignedShortDataType, CharDataType, UnsignedCharDataType,
        LongDataType, UnsignedLongDataType, PointerDataType, Undefined4DataType)
    s = " ".join(dt.replace("const", "").replace("volatile", "").split())
    stars = s.count("*")
    s = s.replace("*", "").strip()
    base = {
        "void": VoidDataType(), "int": IntegerDataType(),
        "unsigned": UnsignedIntegerDataType(), "unsigned int": UnsignedIntegerDataType(),
        "signed int": IntegerDataType(),
        "short": ShortDataType(), "unsigned short": UnsignedShortDataType(),
        "char": CharDataType(), "unsigned char": UnsignedCharDataType(),
        "signed char": CharDataType(),
        "long": LongDataType(), "unsigned long": UnsignedLongDataType(),
    }.get(s)
    if base is None:
        # An unknown struct/typedef: as a pointer it is still worth modelling
        # (pointer-ness drives the decompiler's expressions far more than the
        # pointee does); as a value it is not worth guessing.
        if not stars:
            return None
        base = Undefined4DataType()
    for _ in range(stars):
        base = PointerDataType(base)
    return base


# Markers that mean the decompiler did NOT understand something, so the draft
# needs real work before it is a matching candidate. Counting them is a decent
# proxy for how far a draft is from usable - see triage_score().
NOISE_RE = re.compile(
    r"\bundefined\d*\b|\bCONCAT\d+\b|\bunaff_\w+|\bin_\w+|\bextraout_\w+"
    r"|halt_baddata|switchD|\bcode \*|WARNING:")


def triage_score(c_text):
    """(noise, statements) for one decompiled body. Lower noise is better."""
    body = c_text.split("\n\n", 1)[1] if "\n\n" in c_text else c_text
    return len(NOISE_RE.findall(body)), sum(1 for l in body.splitlines() if l.strip())


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
    if args.corpus:
        return un                      # everything still unmatched
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
    ap.add_argument("--corpus", action="store_true",
                    help="draft EVERY still-unmatched function into <out>/<module>/, "
                         "no size cap and no limit, and write <out>/INDEX.md")
    ap.add_argument("--reindex", action="store_true",
                    help="drop drafts for functions that are now matched and rebuild "
                         "<out>/INDEX.md from the remaining headers - no Ghidra needed")
    args = ap.parse_args()
    if args.reindex:
        return reindex(pathlib.Path(args.out))
    if args.corpus and args.max == 0x200:
        args.max = 1 << 30             # the size cap is a sampling aid, not a corpus one

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
    written, failed, applied, errors, index = 0, [], 0, [], []
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
                            # Push the whole prototype, not just the arity.
                            # Arity alone stops a caller dropping arguments;
                            # TYPES are what stop it emitting undefined4 and the
                            # CONCAT22/_2_2_ artifacts that come from not knowing
                            # a value's width.
                            try:
                                lst = ArrayList()      # must be a java.util.List;
                                for i, decl in enumerate(ps):   # a Python list finds no overload
                                    pt, pn = _split_decl(decl)
                                    gt = ghidra_type(pt, prog) or Undefined4DataType()
                                    lst.add(ParameterImpl(pn or f"a{i}", gt, prog))
                                rt = ghidra_type(ret, prog)
                                if rt is not None:
                                    gf.setReturnType(rt, SourceType.USER_DEFINED)
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
                    noise, stmts = triage_score(c)
                    hdr = (f"// decomp: module={f['module']} addr=0x{f['addr']:08x} name={f['name']}\n"
                           f"// GHIDRA DRAFT - a reading aid, NOT a matching candidate.\n"
                           f"// size {ts:#x}"
                           + (f" (Ghidra's cache says {f['size']:#x} - it excludes this "
                              f"function's trailing literal pool)" if ts != f["size"] else "")
                           + f", {f['mode']}\n"
                           f"// triage: noise={noise} statements={stmts}"
                           + ("  <- clean draft, start here\n" if noise == 0 else "\n")
                           + f"// verify:  python tools/match.py --c <file> --func {f['name']} "
                           f"--addr 0x{f['addr']:08x} --size {ts:#x} --module {f['module']} "
                           f"--version {M.CANONICAL}\n\n")
                    dest = outdir / f["module"] if args.corpus else outdir
                    dest.mkdir(parents=True, exist_ok=True)
                    (dest / f"{f['name']}.c").write_text(hdr + c, encoding="utf-8")
                    index.append((noise, stmts, ts, f, dest.name))
                    written += 1
                    if args.corpus and written % 100 == 0:
                        print(f"  ... {written}/{len(targets)} drafted", file=sys.stderr)
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

    if args.corpus:
        write_index(outdir, index, failed, applied, sigs)
        print(f"wrote {outdir/'INDEX.md'}", file=sys.stderr)
    return 0 if written else 1


def reindex(outdir):
    """Rebuild INDEX.md from the drafts already on disk, dropping any whose
    function has since been matched.

    Starting Ghidra to re-derive drafts that have not changed is pure waste, and
    leaving drafts for functions that are already banked is worse than waste -
    it sends the next reader off to redo finished work."""
    import ledger as L
    done = L.load_done()
    by_addr = {(f["module"], f["addr"]): f for f in F.load_funcs() if f.get("module")}
    index, dropped = [], []
    for p in sorted(outdir.rglob("*.c")):
        txt = p.read_text(encoding="utf-8", errors="ignore")
        m = re.search(r"// decomp: module=(\S+) addr=0x([0-9a-f]+) name=(\S+)", txt)
        t = re.search(r"// triage: noise=(\d+) statements=(\d+)", txt)
        if not m or not t:
            continue
        key = (m.group(1), int(m.group(2), 16))
        f = by_addr.get(key)
        if f is None:
            continue
        if key in done:
            p.unlink()
            dropped.append(m.group(3))
            continue
        index.append((int(t.group(1)), int(t.group(2)), F.true_size(f), f, p.parent.name))
    write_index(outdir, index, [], 0, {})
    print(f"dropped {len(dropped)} draft(s) for now-matched functions; "
          f"{len(index)} remain", file=sys.stderr)
    for n in dropped[:8]:
        print(f"  - {n}", file=sys.stderr)
    return 0


def write_index(outdir, index, failed, applied, sigs):
    """A pick-your-next-function table, ordered by how close a draft is to usable.

    The ordering is the whole point: noise first, then statement count, then
    byte size. A short draft with no `undefined`/`CONCAT`/`WARNING` markers is
    one somebody can read in a minute and try to match; a long noisy one needs
    the disassembly open anyway."""
    index.sort(key=lambda r: (r[0], r[1], r[2]))
    clean = [r for r in index if r[0] == 0]
    lines = [
        "# Draft index",
        "",
        f"{len(index)} drafts, {len(clean)} of them clean (no decompiler-confusion",
        "markers at all). Generated by `tools/ghidra_batch.py --corpus`; see",
        "`drafts/README.md` before using any of them.",
        "",
        "`noise` counts markers that mean the decompiler did not understand",
        "something - `undefined*`, `CONCAT*`, `unaff_*`, `in_*`, `extraout_*`,",
        "`switchD`, `halt_baddata`, `code *`, `WARNING:`. **Low noise and few",
        "statements is where to start.** It is a proxy for effort, not for",
        "correctness: a noise-0 draft can still be wrong.",
        "",
        "| function | module | size | mode | noise | stmts | draft |",
        "|---|---|---:|---|---:|---:|---|",
    ]
    for noise, stmts, ts, f, sub in index:
        lines.append(f"| `{f['name']}` | {f['module']} | {ts:#x} | {f['mode']} | "
                     f"{noise} | {stmts} | [{f['name']}.c]({sub}/{f['name']}.c) |")
    if failed:
        lines += ["", f"## {len(failed)} function(s) Ghidra could not decompile", ""]
        lines += [f"- `{n}` - {why}" for n, why in failed]
    lines += ["", "---", "",
              f"Signatures pushed into Ghidra before decompiling: {applied} applied "
              f"from {len(sigs)} known.", ""]
    (outdir / "INDEX.md").write_text("\n".join(lines), encoding="utf-8")


if __name__ == "__main__":
    sys.exit(main())
