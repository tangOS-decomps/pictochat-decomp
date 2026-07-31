"""Match a single function: compile candidate C with mwccarm and compare the
result to the function's bytes in the real PictoChat binary, relocation-aware.

Ported from sm64ds-decomp's tools/match.py, adapted for this project's targets
(assets/pictochat.nds instead of a game ROM) and its multi-segment ARM9 layout
(see notes/pictochat-layout.md - the "main" module is a tiny 3.2KB crt0 stub;
the actual application code lives in the "unk_autoload_0" segment at 0x02320000).

Almost every real function pools an absolute address (a global, a callee),
which the compiler emits as a relocation slot of zeroes plus a reloc entry,
while the binary has the final linked address there. So a correct match is:
every instruction word identical AND every reloc slot lined up - not a raw
byte-for-byte compare.

Usage:
    python tools/match.py --c src/arm9/some_func.c --func some_func \
        --addr 0x02320a84 --size 0x10 --module unk_autoload_0 \
        --version 1.2/sp2p3

Without --version, uses the canonical pinned version (see DEFAULT below).
"""
import argparse
import pathlib
import re
import subprocess
import tempfile
import os

from elftools.elf.elffile import ELFFile
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM

REPO = pathlib.Path(__file__).resolve().parent.parent
MW = REPO / "tools" / "mwccarm"
LICENSE = MW / "license.dat"
DSD_EXTRACT = REPO / "extracted" / "dsd"

# Module name -> (bin path relative to extracted/dsd, base RAM address).
# See notes/pictochat-layout.md for how these were derived (dsd's real ROM
# parsing, cross-checked against the firmware investigation's 0x02320000 find).
MODULES = {
    "main": ("arm9/arm9.bin", 0x02000400),
    "itcm": ("arm9/itcm.bin", 0x01FF8000),
    "unk_autoload_0": ("arm9/unk_autoload_0.bin", 0x02320000),
    "unk_autoload_2": ("arm9/unk_autoload_2.bin", 0x03000000),
    "arm7": ("arm7/arm7.bin", 0x022C0000),
}

# Flags follow sm64ds-decomp's for the same compiler family. NOT yet confirmed
# for this title - see notes/setup-mwccarm.md. PictoChat is a DSi system
# title (2008/2009), not a 2004 NTR-SDK game like SM64DS, so the *version*
# most likely to match is one of the dsi/ builds below, not the NTR 1.2/2.0
# line sm64ds-decomp pinned for their game. Sweep DSI_SWEEP first.
# -thumb confirmed necessary by the first real match (FUN_022c8268, ARM7,
# dsi/1.3 - see src/arm7/FUN_022c8268.c and notes/matching-style.md). Without
# it mwccarm defaults to ARM-mode output even for tiny leaf functions that
# the real binary has as Thumb. Not every function will be Thumb (some hot
# paths may be -noThumb) - override per-function with --flags if a candidate
# that otherwise looks right comes out the wrong size.
DEFAULT_FLAGS = "-O4,p -enum int -lang c99 -char signed -interworking -thumb -proc arm946e -gccext,on -msgstyle gcc"
DEFAULT_FLAGS_ARM7 = "-O4,p -enum int -lang c99 -char signed -interworking -thumb -proc arm7tdmi -gccext,on -msgstyle gcc"
DSI_SWEEP = ["dsi/1.1", "dsi/1.1p1", "dsi/1.2", "dsi/1.2p1", "dsi/1.2p2",
             "dsi/1.3", "dsi/1.3p1", "dsi/1.6sp1", "dsi/1.6sp2"]
NTR_SWEEP = ["1.2/base", "1.2/sp2", "1.2/sp2p3", "1.2/sp3", "1.2/sp4",
             "2.0/base", "2.0/sp1", "2.0/sp1p2", "2.0/sp2", "2.0/sp2p2", "2.0/sp2p3", "2.0/sp2p4"]
SWEEP = DSI_SWEEP + NTR_SWEEP
PINNED = DSI_SWEEP  # until a real match narrows it down further
# All dsi/ builds launch and self-report as "Freescale C/C++ for Embedded ARM"
# (Metrowerks' CodeWarrior division was acquired by Freescale in 2005).
# dsi/1.1 is copyright 2007; dsi/1.2 through dsi/1.6sp2 are copyright 2009.
# The DSi launched Nov 2008 (Japan) / Apr 2009 (Americas/Europe), so a 2009
# build fits a launch-window system title like PictoChat better than the 2007
# one. Still just a starting guess - not yet verified by any real match.
CANONICAL = "dsi/1.3"

md = Cs(CS_ARCH_ARM, CS_MODE_ARM)


def target_bytes(module: str, addr: int, size: int) -> bytes:
    rel_path, base = MODULES[module]
    data = (DSD_EXTRACT / rel_path).read_bytes()
    off = addr - base
    if off < 0 or off + size > len(data):
        raise SystemExit(f"address 0x{addr:08x} size 0x{size:x} out of range for "
                          f"module {module} (base 0x{base:08x}, size 0x{len(data):x})")
    return data[off:off + size]


def compile_c(cfile: pathlib.Path, version: str, flags: str) -> bytes | None:
    exe = MW / version / "mwccarm.exe"
    if not exe.is_file():
        print(f"  ! no compiler at {version}")
        return None
    # Cross-run the Windows compiler under an emulator when asked: the PR-validator
    # sandbox runs this in a Linux container and sets MWCCARM_LAUNCHER=wine so the
    # PE is invoked via Wine. Unset on native Windows -> exe is run directly, so this
    # is a no-op for every existing caller. Ported from sm64ds-decomp's match.py.
    launcher = os.environ.get("MWCCARM_LAUNCHER", "").split()
    with tempfile.TemporaryDirectory() as td:
        out_o = pathlib.Path(td) / "out.o"
        env = dict(os.environ, LM_LICENSE_FILE=str(LICENSE))
        cmd = [*launcher, str(exe), *flags.split(), "-c", str(cfile), "-o", str(out_o)]
        try:
            r = subprocess.run(cmd, capture_output=True, text=True, env=env, timeout=90)
        except subprocess.TimeoutExpired:
            print(f"  ! compile timed out ({version})")
            return None
        if r.returncode != 0 or not out_o.is_file():
            print(f"  ! compile failed ({version}): {r.stderr.strip()[:300]}")
            return None
        return out_o.read_bytes()


def extract_func(obj: bytes, func: str):
    import io
    elf = ELFFile(io.BytesIO(obj))
    symtab = elf.get_section_by_name(".symtab")
    sym = next((s for s in symtab.iter_symbols() if s.name == func), None)
    if sym is None:
        return None, None
    sec = elf.get_section(sym["st_shndx"])
    start, size = sym["st_value"], sym["st_size"]
    code = sec.data()[start:start + size]
    relocs = set()
    rel = elf.get_section_by_name(".rel" + sec.name) or elf.get_section_by_name(".rela" + sec.name)
    if rel is not None:
        for r in rel.iter_relocations():
            o = r["r_offset"] - start
            if 0 <= o < size:
                # Relocations are 4 bytes wide (BL/data-pointer) but not always
                # 4-byte aligned within the function (a Thumb BL can start at
                # a 2-mod-4 offset) - wildcard every compare() word the
                # relocation's own [o, o+4) span touches, not just the one
                # o rounds down to, or the far half of a straddling reloc
                # gets real-compared and spuriously mismatches.
                relocs.add(o & ~3)
                relocs.add((o + 3) & ~3)
    return code, relocs


def compare(target: bytes, cand: bytes, relocs: set, verbose: bool = True):
    if len(target) != len(cand):
        if verbose:
            print(f"  size differs: target 0x{len(target):x} vs candidate 0x{len(cand):x}")
        return False, 999
    ok = True
    ndiff = 0
    for i in range(0, len(target), 4):
        tw = target[i:i + 4]
        cw = cand[i:i + 4]
        if i in relocs:
            tag = "reloc (wildcard)"
            match = True
        else:
            match = tw == cw
            tag = "OK" if match else "<<< MISMATCH"
        if not match:
            ok = False
            ndiff += 1
        if verbose:
            ti = next(md.disasm(tw, 0), None)
            ci = next(md.disasm(cw, 0), None)
            ts = f"{ti.mnemonic} {ti.op_str}" if ti else tw.hex()
            cs = f"{ci.mnemonic} {ci.op_str}" if ci else cw.hex()
            print(f"   +0x{i:02x} | {tw.hex()} {ts:24} | {cw.hex()} {cs:24} | {tag}")
    return ok, ndiff


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--c", required=True)
    ap.add_argument("--func", required=True)
    ap.add_argument("--addr", required=True, type=lambda x: int(x, 0))
    ap.add_argument("--size", required=True, type=lambda x: int(x, 0))
    ap.add_argument("--module", default="unk_autoload_0", choices=list(MODULES))
    ap.add_argument("--version", default=None, help="check a single version")
    ap.add_argument("--versions", default=None, help="comma list to sweep")
    ap.add_argument("--trio", action="store_true", help="sweep the dsi/ builds (most likely for this title)")
    ap.add_argument("--all", action="store_true", help="sweep every known version")
    ap.add_argument("--brief", action="store_true", help="terse: per-version pass/fail")
    ap.add_argument("--flags", default=None)
    args = ap.parse_args()

    flags = args.flags or (DEFAULT_FLAGS_ARM7 if args.module == "arm7" else DEFAULT_FLAGS)
    cfile = pathlib.Path(args.c)
    try:
        src_text = cfile.read_text(encoding="utf-8")
        if src_text.startswith("//cpp") and "-lang c99" in flags:
            flags = flags.replace("-lang c99", "-lang c++")
        if "// flags: " in src_text:
            extra = src_text.split("// flags: ")[1].split("\n")[0].strip()
            if "-arm" in extra or "-noThumb" in extra:
                flags = flags.replace(" -thumb", "")
            else:
                flags += " " + extra
        elif not args.flags and re.search(r"\basm\b", src_text) and "-thumb" in flags:
            flags = flags.replace(" -thumb", "")
    except OSError:
        pass

    tgt = target_bytes(args.module, args.addr, args.size)
    hexstr = tgt.hex()
    shown = hexstr if (not args.brief or len(hexstr) <= 128) else f"{hexstr[:128]}... ({len(tgt)} bytes)"
    print(f"TARGET {args.func} @ 0x{args.addr:08x} size 0x{args.size:x} [{args.module}]  bytes: {shown}")

    if args.version:
        versions = [args.version]
    elif args.versions:
        versions = [v.strip() for v in args.versions.split(",") if v.strip()]
    elif args.all:
        versions = SWEEP
    elif args.trio:
        versions = PINNED
    else:
        versions = [CANONICAL]

    matched = []
    closest = None
    for v in versions:
        obj = compile_c(cfile, v, flags)
        if obj is None:
            continue
        code, relocs = extract_func(obj, args.func)
        if code is None:
            print(f"  {v}: symbol '{args.func}' not found in object")
            continue
        if not args.brief:
            print(f"\n=== mwccarm {v} ===")
        ok, ndiff = compare(tgt, code, relocs, verbose=not args.brief)
        if ok:
            matched.append(v)
            if args.brief:
                print(f"  {v}: MATCH")
        else:
            if args.brief:
                print(f"  {v}: {ndiff} word(s) differ")
            if closest is None or ndiff < closest[0]:
                closest = (ndiff, v, code, relocs)

    if args.brief and not matched and closest is not None:
        print(f"\n--- closest: {closest[1]} ({closest[0]} differ) ---")
        compare(tgt, closest[2], closest[3], verbose=True)

    print("\n" + "=" * 40)
    print("MATCHING VERSIONS:", ", ".join(matched) if matched else "none")


if __name__ == "__main__":
    main()
