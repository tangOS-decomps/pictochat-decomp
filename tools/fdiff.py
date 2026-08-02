"""Iteration oracle for cracking ONE hard function: compile a candidate and
show the per-instruction byte diff against the ROM, with relocation slots
wildcarded.

Unlike tools/match.py's plain pass/fail, this localizes exactly which
instructions differ, so you can converge on a big function instead of
guessing blind. Ported from sm64ds-decomp's tools/fdiff.py.

Usage:
    python tools/fdiff.py --c cand.c --func NAME --module unk_autoload_0 \
        --addr 0x02320a64 --size 0x52
    python tools/fdiff.py --c cand.c --func NAME --target-hex <hex>
"""
import argparse
import difflib
import pathlib
import re
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import match as M   # noqa: E402

PCREL = re.compile(r"\[pc,\s*#-?(?:0x[0-9a-fA-F]+|[0-9]+)\]")
REG = re.compile(r"\b(?:r(?:1[0-2]|[0-9])|fp|ip|sb|sl|lr)\b")


def shape(ins):
    """Mnemonic + operands with PC-relative offsets and register numbers
    squashed, for a "same shape, different regalloc" eyeball comparison."""
    if ins.mnemonic.startswith("b"):
        return ins.mnemonic
    op = PCREL.sub("[pc]", ins.op_str.replace(" ", ""))
    op = REG.sub("r", op)
    return ins.mnemonic + " " + op


def diff(target: bytes, cand: bytes, relocs: set, compact: bool = False,
         max_runs: int = 12, max_lines_per_run: int = 4, context: int = 1):
    """Print a per-word table; return (ok, n_mismatches).

    compact=True is the large-function mode: instead of dumping every word
    (unusable past a few hundred instructions - it's the dominant token cost
    when iterating on a big function), mismatches are grouped into
    contiguous runs and only a summary + boundary lines of each run print.
    Full detail is still one `compact=False` call away once a run is small
    enough to eyeball directly.
    """
    if len(target) != len(cand):
        print(f"  size differs: target 0x{len(target):x} vs candidate 0x{len(cand):x}")
        return False, 999

    rows = []  # (i, tw, cw, match, ts, cs, same_shape)
    for i in range(0, len(target), 4):
        tw, cw = target[i:i + 4], cand[i:i + 4]
        match = True if i in relocs else tw == cw
        ti = next(M.md.disasm(tw, 0), None)
        ci = next(M.md.disasm(cw, 0), None)
        ts = f"{ti.mnemonic} {ti.op_str}" if ti else tw.hex()
        cs = f"{ci.mnemonic} {ci.op_str}" if ci else cw.hex()
        same_shape = (ti is not None and ci is not None and not match
                      and shape(ti) == shape(ci))
        rows.append((i, tw, cw, match, ts, cs, same_shape))

    ok = all(r[3] for r in rows)
    ndiff = sum(1 for r in rows if not r[3])

    if not compact:
        for i, tw, cw, match, ts, cs, same_shape in rows:
            tag = "OK" if match else "<<< MISMATCH"
            note = tag if not same_shape or match else tag + "  (same shape - regalloc/coloring only)"
            print(f"   +0x{i:02x} | {tw.hex()} {ts:26} | {cw.hex()} {cs:26} | {note}")
        return ok, ndiff

    # --- compact mode: group contiguous mismatch indices into runs ---
    print(f"  {len(rows)} words total, {ndiff} mismatch(es), "
          f"{sum(r[6] for r in rows if not r[3])} of those same-shape (regalloc only)")
    runs = []
    cur = []
    for idx, r in enumerate(rows):
        if not r[3]:
            cur.append(idx)
        elif cur:
            runs.append(cur)
            cur = []
    if cur:
        runs.append(cur)

    print(f"  {len(runs)} mismatching run(s)"
          + (f" (showing first {max_runs})" if len(runs) > max_runs else "") + ":")
    for run in runs[:max_runs]:
        lo, hi = run[0], run[-1]
        i0, i1 = rows[lo][0], rows[hi][0]
        shapes_only = all(rows[k][6] for k in run)
        tag = "(same shape - regalloc/coloring only)" if shapes_only else ""
        print(f"  -- +0x{i0:03x}..+0x{i1:03x} ({len(run)} word(s)) {tag}")
        shown = run[:max_lines_per_run]
        for k in shown:
            i, tw, cw, match, ts, cs, same_shape = rows[k]
            print(f"     +0x{i:03x} | {tw.hex()} {ts:26} | {cw.hex()} {cs:26}")
        if len(run) > len(shown):
            print(f"     ... {len(run) - len(shown)} more word(s) in this run")
    if len(runs) > max_runs:
        print(f"  ... {len(runs) - max_runs} more run(s) not shown")
    return ok, ndiff


def decode_stream(data: bytes):
    """[(offset, raw_bytes, mnemonic+op_str, shape_str), ...] - one entry per
    decoded instruction. Stops (silently) at the first byte capstone can't
    decode (typically an inline literal pool / data word), same as
    tools/disasm.py - callers just get a shorter list, which is fine for
    sequence alignment."""
    out = []
    off = 0
    for insn in M.md.disasm(data, 0):
        text = f"{insn.mnemonic} {insn.op_str}"
        out.append((off, data[off:off + insn.size], text, shape(insn)))
        off += insn.size
    return out


def align_diff(target: bytes, cand: bytes, max_blocks: int = 20, context: int = 2):
    """max_blocks=0 means unlimited (print every non-equal block)."""
    """Sequence-aligned diff for when target/candidate DIFFER IN LENGTH (a
    missing/extra instruction somewhere) - the normal fixed-position diff()
    is useless past the insertion/deletion point since every word after it
    is off-by-one and shows as a mismatch. This aligns on instruction SHAPE
    (mnemonic + operand pattern with register numbers/pc-rel offsets
    squashed - see shape()), so pure register-coloring differences collapse
    into "equal" and only genuine inserted/deleted/reordered instructions
    show up as a diff block, which is exactly what you need to find "where's
    the extra/missing word" in an otherwise close candidate.
    """
    t = decode_stream(target)
    c = decode_stream(cand)
    t_shapes = [x[3] for x in t]
    c_shapes = [x[3] for x in c]
    sm = difflib.SequenceMatcher(a=t_shapes, b=c_shapes, autojunk=False)
    ops = [op for op in sm.get_opcodes() if op[0] != "equal"]
    limit = len(ops) if max_blocks == 0 else max_blocks
    print(f"  target: {len(t)} decoded insn(s) (0x{len(target):x} bytes); "
          f"candidate: {len(c)} decoded insn(s) (0x{len(cand):x} bytes)")
    print(f"  {len(ops)} non-equal block(s) after shape-aligning "
          f"(register-coloring-only differences are collapsed)"
          + (f", showing first {limit}" if len(ops) > limit else "") + ":")
    for tag, i1, i2, j1, j2 in ops[:limit]:
        print(f"  -- {tag}: target[{i1}:{i2}] vs candidate[{j1}:{j2}]")
        lo_t, hi_t = max(0, i1 - context), min(len(t), i2 + context)
        lo_c, hi_c = max(0, j1 - context), min(len(c), j2 + context)
        width = max(hi_t - lo_t, hi_c - lo_c)
        for k in range(width):
            ti = lo_t + k
            ci = lo_c + k
            tstr = f"+0x{t[ti][0]:03x} {t[ti][1].hex():<10}{t[ti][2]:26}" if ti < hi_t else ""
            cstr = f"+0x{c[ci][0]:03x} {c[ci][1].hex():<10}{c[ci][2]:26}" if ci < hi_c else ""
            marker = "*" if (i1 <= ti < i2 or j1 <= ci < j2) else " "
            print(f"    {marker} {tstr:42} | {cstr}")
    if len(ops) > limit:
        print(f"  ... {len(ops) - limit} more block(s) not shown")
    if not ops:
        print("  (no shape differences found - candidate may only need a byte-for-byte "
              "recheck, e.g. a literal-pool constant value)")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--c", required=True)
    ap.add_argument("--func", required=True)
    ap.add_argument("--target-hex", default=None)
    ap.add_argument("--module", default="unk_autoload_0", choices=list(M.MODULES))
    ap.add_argument("--addr", type=lambda x: int(x, 0), default=None)
    ap.add_argument("--size", type=lambda x: int(x, 0), default=None)
    ap.add_argument("--version", default=M.CANONICAL)
    ap.add_argument("--flags", default=None)
    ap.add_argument("--compact", action="store_true",
                     help="group mismatches into runs instead of dumping every word - "
                          "use this for anything past a couple hundred bytes")
    ap.add_argument("--max-runs", type=int, default=12)
    ap.add_argument("--max-lines-per-run", type=int, default=4)
    ap.add_argument("--align", action="store_true",
                     help="sequence-aligned diff for a candidate whose SIZE differs from "
                          "the target (finds the extra/missing instruction instead of "
                          "just reporting 'size differs')")
    ap.add_argument("--align-max-blocks", type=int, default=20,
                     help="cap on non-equal blocks printed by --align (0 = unlimited, "
                          "for when you want the full picture instead of a truncated one)")
    ap.add_argument("--align-context", type=int, default=2,
                     help="lines of equal-context shown around each --align block")
    args = ap.parse_args()

    if args.target_hex:
        target = bytes.fromhex(args.target_hex)
    elif args.addr is not None and args.size is not None:
        target = M.target_bytes(args.module, args.addr, args.size)
    else:
        ap.error("give --target-hex, or --module/--addr/--size")

    flags = args.flags or (M.DEFAULT_FLAGS_ARM7 if args.module == "arm7" else M.DEFAULT_FLAGS)
    cfile = pathlib.Path(args.c)
    src_text = cfile.read_text(encoding="utf-8")
    flags = M.apply_flags_marker(flags, src_text, allow_thumb_heuristic=not args.flags)

    obj = M.compile_c(cfile, args.version, flags)
    if obj is None:
        sys.exit(1)
    code, relocs, reloc_info = M.extract_func(obj, args.func)
    if code is None:
        sys.exit(f"symbol '{args.func}' not found in compiled object")

    if args.align or len(target) != len(code):
        align_diff(target, code, max_blocks=args.align_max_blocks, context=args.align_context)
        if len(target) != len(code):
            print(f"\nRESULT match=False size differs: target 0x{len(target):x} "
                  f"vs candidate 0x{len(code):x}")
            return
        if args.align:
            return

    ok, ndiff = diff(target, code, relocs, compact=args.compact,
                      max_runs=args.max_runs, max_lines_per_run=args.max_lines_per_run)

    # Every relocation is wildcarded above regardless of whether it points at
    # the right place - see match.py's verify_relocs() docstring. Catch a
    # wrong callee/global that happens to encode its intended address in its
    # own name (this project's `<prefix>_<hex>` convention).
    is_thumb = "-thumb" in flags
    bad = [r for r in M.verify_relocs(args.addr, target, reloc_info, is_thumb) if r[4] is False]
    if bad:
        ok = False
        print()
        for off, sym, want, found, _ in bad:
            print(f"  ! reloc @ +0x{off:x} '{sym}' claims target 0x{want:08x}, "
                  f"real bytes resolve to 0x{found:08x}")

    print(f"\nRESULT match={ok} mismatches={ndiff}/{len(target)//4}" +
          (f" reloc_mismatches={len(bad)}" if bad else ""))


if __name__ == "__main__":
    main()
