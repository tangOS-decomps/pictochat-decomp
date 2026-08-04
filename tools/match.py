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
CW20_SWEEP = ["2.0/base", "2.0/sp1", "2.0/sp1p2", "2.0/sp1p5", "2.0/sp1p6",
              "2.0/sp1p7", "2.0/sp2", "2.0/sp2p2", "2.0/sp2p3", "2.0/sp2p4"]
NTR_SWEEP = ["1.2/base", "1.2/sp2", "1.2/sp2p3", "1.2/sp3", "1.2/sp4"] + CW20_SWEEP
# Recovered via tools/recover_cw2004.py (see sm64ds-decomp notes/mwccarm-codegen.md
# 6ai) - a genuinely different, older compiler core than the 1.2/2.0 line above,
# not just different flags. Not this title's canonical build (PictoChat is DSi-era,
# this is a 2004 NTR-era core) but cheap to include: costs nothing extra per sweep
# and has real precedent for reproducing prologue/materialization shapes the 1.2/2.0
# line cannot from any source phrasing.
CW2004_SWEEP = ["2004/b56"]
SWEEP = DSI_SWEEP + NTR_SWEEP + CW2004_SWEEP
PINNED = CW20_SWEEP

# ---------------------------------------------------------------------------
# THE TOOLCHAIN IS 2.0/*, NOT dsi/*  (settled 2026-08-04 - do not re-litigate
# without new byte evidence; see notes/setup-mwccarm.md for the full record)
#
# The dsi/* pin that stood here until now was never verified by a match - it
# was a plausibility argument from build dates (PictoChat is a DSi title, so a
# DSi-era compiler "must" have built it). That reasoning is wrong: a single ROM
# is built by ONE toolchain, so the question is settled by byte evidence, not
# by which product name looks apt.
#
# Evidence. Of the whole banked corpus, exactly four functions DISCRIMINATE
# between the two families (everything else compiles byte-identically under
# both, so it votes for neither):
#     FUN_022ce658   matches 2.0/* only - structurally wrong under dsi/*
#     FUN_022d3bd4   matches 2.0/* only - structurally wrong under dsi/*
#     FUN_022d5a64   matches 2.0/* only - dsi/* cannot emit its frame shape
#     FUN_022ce5b4   matched dsi/* as first written, but ALSO matches 2.0/*
#                    once `#pragma opt_strength_reduction off` stops 2.0 from
#                    turning its loop index into a pointer induction variable
# So 2.0/* explains all four; dsi/* explains one and is structurally incapable
# of three. All ten 2.0/* builds behave identically on every discriminating
# function, so the family is pinned but the point release is not - 2.0/base is
# chosen as the representative.
# ---------------------------------------------------------------------------
CANONICAL = "2.0/base"

md = Cs(CS_ARCH_ARM, CS_MODE_ARM)


def target_bytes(module: str, addr: int, size: int) -> bytes:
    rel_path, base = MODULES[module]
    data = (DSD_EXTRACT / rel_path).read_bytes()
    off = addr - base
    if off < 0 or off + size > len(data):
        raise SystemExit(f"address 0x{addr:08x} size 0x{size:x} out of range for "
                          f"module {module} (base 0x{base:08x}, size 0x{len(data):x})")
    return data[off:off + size]


def apply_flags_marker(flags: str, src_text: str, allow_thumb_heuristic: bool = True) -> str:
    """Apply a source file's `//cpp` and `// flags: ...` overrides to a base
    flags string. Shared by match.py/fdiff.py/nonmatching.py so a banked
    file's flags are reproduced identically by every tool that recompiles it.

    `// flags: ` tokens are applied structurally, not just appended:
      * `-arm` / `-noThumb` strips `-thumb` (ARM-mode candidate).
      * `-O<n>,<x>` REPLACES the base flags' own `-O<n>,<x>` (e.g. swapping
        `-O4,p` for `-O4,s` - see notes/tooling.md's "pop{pc} fold" section).
        Appending a second `-O4,...` after the first, rather than replacing
        it, silently produces nonsense output from mwccarm (confirmed
        empirically - this bit a real match attempt before being fixed).
      * anything else is appended verbatim, same as before.
    """
    if src_text.startswith("//cpp") and "-lang c99" in flags:
        flags = flags.replace("-lang c99", "-lang c++")
    if "// flags: " in src_text:
        extra = src_text.split("// flags: ")[1].split("\n")[0].strip()
        for tok in extra.split():
            m = re.match(r"^-O\d", tok)
            if m:
                flags = re.sub(r"-O\d[\w,]*", tok, flags)
            elif tok in ("-arm", "-noThumb"):
                flags = flags.replace(" -thumb", "")
            else:
                flags += " " + tok
    elif allow_thumb_heuristic and re.search(r"\basm\b", src_text) and "-thumb" in flags:
        flags = flags.replace(" -thumb", "")
    return flags


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
        return None, None, None
    sec = elf.get_section(sym["st_shndx"])
    start, size = sym["st_value"], sym["st_size"]
    code = sec.data()[start:start + size]
    relocs = set()
    reloc_info = []
    rel = elf.get_section_by_name(".rel" + sec.name) or elf.get_section_by_name(".rela" + sec.name)
    if rel is not None:
        rsymtab = elf.get_section(rel["sh_link"])
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
                rsym = rsymtab.get_symbol(r["r_info_sym"])
                reloc_info.append({"offset": o, "type": r["r_info_type"], "sym": rsym.name})
    return code, relocs, reloc_info


# This project's convention: an extern callee/global that doesn't have a real
# recovered symbol name yet is still named after its own real address
# (FUN_<hex>, func_<hex>, G_<hex>, ...) - see notes/matching-style.md. That
# means for any relocation whose symbol matches this pattern, the *intended*
# real target address is recoverable straight from the candidate's own source,
# even though compare()'s per-word check can't see it (relocations are always
# wildcarded there - see extract_func()'s docstring above). verify_relocs()
# closes that gap: it decodes what the REAL ROM bytes at that slot actually
# resolve to (a literal pool word for a data reference, a resolved branch
# target for a call) and checks it against the address the symbol name claims.
# Without this, a candidate could call/reference a completely wrong
# address-named symbol and still "match" on ndiff=0, because every instruction
# word touching that reference is unconditionally wildcarded either way.
SYM_ADDR_RE = re.compile(r"_([0-9a-fA-F]{8})$")
R_ARM_ABS32 = 2
BRANCH_MNEMONICS = {"bl", "blx", "b", "bx"}
md_thumb = Cs(CS_ARCH_ARM, 0x10)  # CS_MODE_THUMB


def sym_target_addr(name: str):
    m = SYM_ADDR_RE.search(name)
    return int(m.group(1), 16) if m else None


def verify_relocs(func_addr: int, target_code: bytes, reloc_info: list, is_thumb: bool):
    """[(offset, sym, expected_addr, found_addr_or_None, ok_or_None), ...] for
    every relocation whose symbol name encodes a real address. ok is None
    (unverified, not a failure) when the real bytes don't decode as a
    recognizable data word or branch - e.g. an unusual relocation type this
    hasn't been taught yet; never silently treated as a pass."""
    import struct
    out = []
    for info in reloc_info:
        want = sym_target_addr(info["sym"])
        if want is None:
            continue
        off, rtype = info["offset"], info["type"]
        if off + 4 > len(target_code):
            out.append((off, info["sym"], want, None, None))
            continue
        if rtype == R_ARM_ABS32:
            found = struct.unpack_from("<I", target_code, off)[0]
            # A Thumb function's address stored as a data value (a function
            # pointer, not a branch target) legitimately has bit 0 set - the
            # ARM/Thumb interworking "call this in Thumb state" tag (real
            # example: G_023c10c4 = FUN_02332598 in FUN_02332660.c). A branch
            # instruction's resolved target (the other arm below) never has
            # this ambiguity - capstone already resolves it to the true byte
            # address either way - so only tolerate +1 here.
            out.append((off, info["sym"], want, found, found in (want, want | 1)))
            continue
        cs = md_thumb if is_thumb else md
        insn = next(cs.disasm(target_code[off:off + 4], func_addr + off), None)
        if insn is None or insn.mnemonic not in BRANCH_MNEMONICS or "#0x" not in insn.op_str:
            out.append((off, info["sym"], want, None, None))
            continue
        found = int(insn.op_str.rsplit("#", 1)[-1], 16)
        out.append((off, info["sym"], want, found, found == want))
    return out


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
        flags = apply_flags_marker(flags, src_text, allow_thumb_heuristic=not args.flags)
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

    is_thumb = "-thumb" in flags
    matched = []
    closest = None
    for v in versions:
        obj = compile_c(cfile, v, flags)
        if obj is None:
            continue
        code, relocs, reloc_info = extract_func(obj, args.func)
        if code is None:
            print(f"  {v}: symbol '{args.func}' not found in object")
            continue
        if not args.brief:
            print(f"\n=== mwccarm {v} ===")
        ok, ndiff = compare(tgt, code, relocs, verbose=not args.brief)
        reloc_checks = verify_relocs(args.addr, tgt, reloc_info, is_thumb)
        bad_relocs = [r for r in reloc_checks if r[4] is False]
        if bad_relocs:
            ok = False
            for off, sym, want, found, _ in bad_relocs:
                print(f"  ! reloc @ +0x{off:x} '{sym}' claims target 0x{want:08x}, "
                      f"real bytes resolve to 0x{found:08x}" if found is not None else
                      f"  ! reloc @ +0x{off:x} '{sym}' claims target 0x{want:08x}, "
                      f"real bytes don't decode as a data word or branch")
        if ok:
            matched.append(v)
            if args.brief:
                print(f"  {v}: MATCH")
        else:
            if args.brief:
                print(f"  {v}: {ndiff} word(s) differ" +
                      (f", {len(bad_relocs)} reloc target(s) wrong" if bad_relocs else ""))
            if closest is None or ndiff < closest[0]:
                closest = (ndiff, v, code, relocs)

    if args.brief and not matched and closest is not None:
        print(f"\n--- closest: {closest[1]} ({closest[0]} differ) ---")
        compare(tgt, closest[2], closest[3], verbose=True)

    print("\n" + "=" * 40)
    print("MATCHING VERSIONS:", ", ".join(matched) if matched else "none")


if __name__ == "__main__":
    main()
