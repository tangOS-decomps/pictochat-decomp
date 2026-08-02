"""Disassemble a region of an extracted PictoChat binary to ARM/Thumb assembly.

Quick scratch disassembler for eyeballing functions before matching them (see
tools/match.py) or reading them in Ghidra. Operates on extracted/dsd/ (see
tools/extract_pictochat.py). Knows this project's module layout so you pass a
module name instead of a raw file path - see notes/pictochat-layout.md for why
"unk_autoload_0" is the module that holds almost everything interesting.

Usage:
    # Disassemble 0x40 bytes of the main application module at 0x02320a00
    python tools/disasm.py --module unk_autoload_0 --addr 0x02320a00 --length 0x40

    # ARM7 is Thumb by default at its entry; pass --arm for ARM-mode regions
    python tools/disasm.py --module arm7 --addr 0x022c0100 --length 0x40 --thumb
"""
import argparse
import pathlib
import sys

try:
    from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB
    from capstone.arm import ARM_OP_MEM, ARM_REG_PC
except ImportError:
    sys.exit("capstone not installed. Run: pip install capstone")

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
from match import MODULES, DSD_EXTRACT  # noqa: E402


def auto_int(x: str) -> int:
    return int(x, 0)


def resolve_pc_rel(insn):
    """True if insn is a `ldr rX, [pc, #N]`-style pc-relative load."""
    for op in insn.operands:
        if op.type == ARM_OP_MEM and op.mem.base == ARM_REG_PC:
            return True
    return False


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--module", default="unk_autoload_0", choices=list(MODULES))
    ap.add_argument("--addr", type=auto_int, required=True, help="RAM address to start at")
    ap.add_argument("--length", type=auto_int, default=None,
                     help="bytes to disassemble (default 0x100, or see --to-next)")
    ap.add_argument("--thumb", action="store_true", help="decode as Thumb instead of ARM")
    ap.add_argument("--no-pools", action="store_true",
                     help="don't resolve/dereference pc-relative loads (ldr rX,[pc,#N])")
    ap.add_argument("--to-next", action="store_true",
                     help="disassemble up to the next known function's start address "
                          "(from extracted/pictochat_funcs.json via tools/funcs.py) instead of "
                          "a fixed --length - covers this function's own trailing literal pool, "
                          "which Ghidra's cached size routinely excludes (see notes/tooling.md)")
    args = ap.parse_args()

    rel_path, base = MODULES[args.module]
    data = (DSD_EXTRACT / rel_path).read_bytes()
    off = args.addr - base
    if off < 0 or off >= len(data):
        sys.exit(f"address 0x{args.addr:08x} out of range for module {args.module} "
                  f"(base 0x{base:08x}, size 0x{len(data):x})")

    length = args.length
    if args.to_next:
        import funcs as F  # noqa: E402
        cpu = "arm7" if args.module == "arm7" else "arm9"
        addrs = sorted(f["addr"] for f in F.load_funcs()
                        if f["cpu"] == cpu and f["addr"] > args.addr)
        nxt = next((a for a in addrs if F.module_for(cpu, a) == args.module), None)
        if nxt is None:
            sys.exit("--to-next: no later function found in the same module")
        length = nxt - args.addr
        print(f"; --to-next: next function at 0x{nxt:08X}, disassembling 0x{length:x} bytes")
    elif length is None:
        length = 0x100
    chunk = data[off:off + length]

    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB if args.thumb else CS_MODE_ARM)
    md.detail = not args.no_pools

    for insn in md.disasm(chunk, args.addr):
        raw = insn.bytes.hex()
        line = f"{insn.address:08X}  {raw:<8}  {insn.mnemonic:<7} {insn.op_str}"
        if not args.no_pools and resolve_pc_rel(insn):
            # ARM: pc reads as insn.address+8, word-aligned. Thumb: +4, word-aligned.
            pc = (insn.address + (8 if insn.size == 4 else 4)) & ~3
            for op in insn.operands:
                if op.type == ARM_OP_MEM and op.mem.base == ARM_REG_PC:
                    pool_addr = pc + op.mem.disp
                    break
            pool_off = pool_addr - base
            if 0 <= pool_off + 4 <= len(data):
                val = int.from_bytes(data[pool_off:pool_off + 4], "little")
                line += f"   ; [0x{pool_addr:08X}] = 0x{val:08X}"
            else:
                line += f"   ; [0x{pool_addr:08X}] = <out of range>"
        print(line)


if __name__ == "__main__":
    main()
