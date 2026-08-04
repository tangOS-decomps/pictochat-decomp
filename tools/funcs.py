"""Function inventory + module resolution for this project.

Single source of truth for "what functions are there and which module do they
belong to": extracted/pictochat_funcs.json (a Ghidra dump - see
notes/ghidra-setup.md). Unlike sm64ds-decomp's modules.py/sweep.py (which read
a fully-populated config/**/symbols.txt from dsd), our dsd init never
completes for this ROM (see notes/pictochat-layout.md - it terminates early on
this title's unusually small main module), so everything here reads the
Ghidra cache instead. Regenerate it if it goes stale.
"""
import json
import pathlib
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
from match import MODULES, DSD_EXTRACT  # noqa: E402

FUNCS_CACHE = REPO / "extracted" / "pictochat_funcs.json"

_MODULE_RANGES = None


def _module_ranges():
    """cpu -> [(module_name, base, size), ...], built from MODULES + the
    actual extracted binary sizes on disk."""
    global _MODULE_RANGES
    if _MODULE_RANGES is not None:
        return _MODULE_RANGES
    ranges = {"arm9": [], "arm7": []}
    for name, (relpath, base) in MODULES.items():
        p = DSD_EXTRACT / relpath
        if not p.is_file():
            continue
        cpu = "arm7" if name == "arm7" else "arm9"
        ranges[cpu].append((name, base, p.stat().st_size))
    _MODULE_RANGES = ranges
    return ranges


def module_for(cpu, addr):
    """Module name (a key of match.MODULES) containing addr, or None."""
    for name, base, size in _module_ranges().get(cpu, []):
        if base <= addr < base + size:
            return name
    return None


def src_dir_for(module):
    """This project splits src/ by CPU (arm9/arm7), not by module - all four
    ARM9 modules (main/itcm/unk_autoload_0/unk_autoload_2) share src/arm9/."""
    return REPO / "src" / ("arm7" if module == "arm7" else "arm9")


def load_funcs():
    """All Ghidra-known functions: [{cpu,name,addr,size,mode,bytes,module}, ...].

    `module` is resolved here from addr via the module table - the raw cache
    only records `cpu` (arm9/arm7), not which of arm9's four segments a
    function lives in.
    """
    if not FUNCS_CACHE.is_file():
        sys.exit(f"{FUNCS_CACHE} not found - see notes/ghidra-setup.md to (re)export it")
    out = []
    for f in json.loads(FUNCS_CACHE.read_text()):
        f = dict(f)
        f["module"] = module_for(f["cpu"], f["addr"])
        out.append(f)
    return out


def target_bytes(f):
    return bytes.fromhex(f["bytes"])


def true_size(f, all_funcs=None):
    """Size of `f` INCLUDING its own trailing literal pool, in bytes.

    Ghidra's cached `size` comes from code-flow analysis, not a symbol table
    (this ROM has none), so it stops at the last reachable instruction and
    EXCLUDES the pool words the compiler emits immediately after. mwccarm puts
    those words inside the function it built them for, so a candidate compiled
    from C is longer than the cached size and can never compare equal - the
    mismatch looks like a codegen bug and is not one. This bit three of this
    project's hardest functions for several sessions each
    (notes/mwccarm-codegen.md 3m/3n) and affects ~40% of the corpus.

    Rather than blindly extending to the next function's start (which
    over-extends when unrelated data or an unlisted function sits in the gap -
    FUN_02321d14's gap is 0xa0 bytes but only 4 of them are its pool), this
    decodes `f` and extends only far enough to cover the highest pool word its
    OWN pc-relative loads actually reference. If nothing is referenced past the
    cached end, the cached size is returned unchanged.
    """
    size = f["size"]
    data = bytes.fromhex(f["bytes"])
    if len(data) < size:
        return size
    end = size
    if f.get("mode") == "arm":
        for off in range(0, size - 3, 4):
            w = int.from_bytes(data[off:off + 4], "little")
            # LDR rX,[pc,#imm12]: cond!=0xf, I=0 P=1 U=? B=0 W=0 L=1, Rn=pc
            if (w & 0x0F7F0000) != 0x051F0000:
                continue
            imm = w & 0xFFF
            if not (w & 0x00800000):          # U clear -> subtract
                imm = -imm
            pool = off + 8 + imm
            if pool >= end:
                end = pool + 4
    else:
        for off in range(0, size - 1, 2):
            h = int.from_bytes(data[off:off + 2], "little")
            # Thumb LDR (literal), encoding T1: 01001 Rd imm8
            if (h & 0xF800) != 0x4800:
                continue
            pool = ((off + 4) & ~3) + (h & 0xFF) * 4
            if pool >= end:
                end = pool + 4
    return end
