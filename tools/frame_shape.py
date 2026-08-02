"""Prologue/epilogue shape probe: what register-save set and stack-frame size
does a function actually use, read straight off raw bytes (target ROM or a
compiled candidate) - no full match/fdiff run needed.

Why this exists: on a large function, mwccarm's `-O4` register allocator's
behavior (which locals live in registers vs get spilled to the stack) is
driven by how much stack frame + how many callee-saved registers the
function ends up needing. If a hand-written candidate's C shape implies
fewer live temporaries than the real function, the compiler picks a smaller
frame and a different push-set, and the *entire* body gets colored
differently - not a few isolated instructions, but a function-wide mismatch
that shows up in fdiff.py as hundreds of scattered word diffs with no
obvious single cause. Diagnosing that by eye (reading a huge fdiff dump and
guessing) is exactly the kind of grind this project's tooling exists to
avoid.

This tool reads the answer directly instead of inferring it by iteration:
the ROM's own prologue (`push {...}` / `stmdb sp!, {...}` then `sub sp, sp,
#N`) tells you up front how many words of register-save + frame the target
actually has, before you write a single line of candidate C. Compare that
number against your candidate's own compiled prologue (--candidate) to know
immediately whether you're even in the right ballpark, instead of
discovering a frame-size mismatch after burning many fdiff iterations on
symptoms.

Usage:
    # Target (ROM) shape:
    python tools/frame_shape.py --module arm7 --addr 0x022ce8b0 --size 0x1194

    # Candidate shape (compiles it, extracts the same function, same probe):
    python tools/frame_shape.py --c candidate.c --func FUN_022ce8b0 \
        --module arm7 --addr 0x022ce8b0 --size 0x1194

    # Side-by-side (both in one call):
    python tools/frame_shape.py --c candidate.c --func FUN_022ce8b0 \
        --module arm7 --addr 0x022ce8b0 --size 0x1194 --compare
"""
import argparse
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import match as M  # noqa: E402

from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB  # noqa: E402

ARM_REGS = ["r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "sb", "sl",
            "fp", "ip", "sp", "lr", "pc"]


def probe(code: bytes, thumb: bool, max_insns: int = 16):
    """Scan the first few instructions for a push/stmdb (register-save set)
    and a following sub sp,sp,#N (extra frame). Returns
    (pushed_regs: list[str], frame_bytes: int, insns_scanned: int)."""
    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB if thumb else CS_MODE_ARM)
    md.detail = True
    pushed, frame = [], 0
    n = 0
    for insn in md.disasm(code[:max_insns * 4], 0):
        n += 1
        mnem = insn.mnemonic
        if mnem in ("push", "stmdb", "stmfd"):
            ops = [o.strip() for o in insn.op_str.split("{")[-1].rstrip("}").split(",")]
            pushed = [o.strip() for o in ops if o.strip()]
        elif mnem == "sub" and pushed and "sp" in insn.op_str.split(",")[0]:
            imm = insn.op_str.rsplit("#", 1)[-1]
            try:
                frame = int(imm, 0)
            except ValueError:
                pass
            break
        elif pushed:
            # first non-frame-setup instruction after the push - prologue's over
            break
        if n >= max_insns:
            break
    return pushed, frame, n


def report(label: str, code: bytes, thumb: bool):
    pushed, frame, n = probe(code, thumb)
    total = len(pushed) * 4 + frame
    print(f"{label}: pushed {{{', '.join(pushed) or '(none)'}}} "
          f"({len(pushed)} reg{'s' if len(pushed) != 1 else ''} = 0x{len(pushed) * 4:x} bytes)"
          f" + sub sp,#0x{frame:x}  => total stack depth 0x{total:x} bytes"
          f"  [scanned {n} insn(s)]")
    return pushed, frame


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--module", default="unk_autoload_0", choices=list(M.MODULES))
    ap.add_argument("--addr", type=lambda x: int(x, 0), required=True)
    ap.add_argument("--size", type=lambda x: int(x, 0), required=True)
    ap.add_argument("--thumb", action="store_true", help="target is Thumb mode")
    ap.add_argument("--c", default=None, help="candidate C file to compile and compare")
    ap.add_argument("--func", default=None, help="function name in the candidate (required with --c)")
    ap.add_argument("--version", default=M.CANONICAL)
    ap.add_argument("--flags", default=None)
    ap.add_argument("--compare", action="store_true", help="also print a match/mismatch verdict")
    args = ap.parse_args()

    target = M.target_bytes(args.module, args.addr, args.size)
    t_pushed, t_frame = report("TARGET   ", target, args.thumb)

    if args.c:
        if not args.func:
            ap.error("--func is required with --c")
        flags = args.flags or (M.DEFAULT_FLAGS_ARM7 if args.module == "arm7" else M.DEFAULT_FLAGS)
        obj = M.compile_c(pathlib.Path(args.c), args.version, flags)
        if obj is None:
            sys.exit(1)
        code, _, _ = M.extract_func(obj, args.func)
        if code is None:
            sys.exit(f"symbol '{args.func}' not found in compiled object")
        c_pushed, c_frame = report("CANDIDATE", code, "-thumb" in flags and "-noThumb" not in flags)
        if args.compare:
            same = t_pushed == c_pushed and t_frame == c_frame
            print(f"\n{'MATCH' if same else 'MISMATCH'}: "
                  f"{'frame shapes agree' if same else 'candidate needs to imply more/fewer live locals to reach the target shape'}")


if __name__ == "__main__":
    main()
