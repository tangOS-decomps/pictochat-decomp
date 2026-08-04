#!/usr/bin/env python3
"""Set up a decomp-permuter working directory for one unmatched function.

Given a function (by module+addr or name), this resolves its ROM bytes, size,
and mode from extracted/pictochat_funcs.json (tools/funcs.py), then writes a
permuter dir:

    <out>/target.o          raw ROM bytes of the function (cap_objdump reads raw)
    <out>/target.o.relocs   reloc offsets to wildcard (bl targets, pool-addr words)
    <out>/compile.sh        -> tools/permuter/mwccarm_compile.sh (our canonical build)
    <out>/flags.txt         this function's compile flags (module + arm/thumb aware)
    <out>/cc.txt            direct-compile sidecar (skips bash per candidate - faster)
    <out>/base.c            the seed C (an m2c/hand draft, or a near-miss to polish)
    <out>/settings.toml     compiler_type=mwcc, func_name, objdump_command=cap_objdump

Then run:
    python vendor/decomp-permuter/permuter.py <out> --stop-on-zero -j 4

Ported from sm64ds-decomp's tools/permuter/import_func.py, swapping their
modules.py/sweep.py (a fully-populated dsd config/ tree) for tools/funcs.py
(the Ghidra cache this project uses instead - see notes/pictochat-layout.md),
and baking --thumb into objdump_command per-function since this project mixes
ARM and Thumb in the same binary.

Usage:
    python tools/permuter/import_func.py --module unk_autoload_0 --addr 0x02320a64 --base seed.c
    python tools/permuter/import_func.py --name FUN_02320a64 --base seed.c
"""
import argparse
import json
import pathlib
import subprocess
import sys
import tempfile

REPO = pathlib.Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(REPO / "tools"))
import funcs as F        # noqa: E402
import match as M        # noqa: E402
import templates as T     # noqa: E402
import ledger as L       # noqa: E402

PERM_DIR = REPO / "vendor" / "decomp-permuter"
WRAPPER = REPO / "tools" / "permuter" / "mwccarm_compile.sh"
CAP = REPO / "tools" / "permuter" / "cap_objdump.py"
# Direct compile (no bash): git-bash startup is slow per-candidate on Windows;
# calling mwccarm.exe directly is much faster. The permuter's compiler.py
# reads cc.txt when present (see notes/permuter-setup.md's Windows-compat list).
MWCC = REPO / "tools" / "mwccarm" / M.CANONICAL / "mwccarm.exe"
LICENSE = REPO / "tools" / "mwccarm" / "license.dat"


def find_func(module, addr, name):
    """Return the matching entry from funcs.load_funcs(), or None."""
    for f in F.load_funcs():
        if f["module"] is None:
            continue
        if module and f["module"] != module:
            continue
        if (addr is not None and f["addr"] == addr) or (name and f["name"] == name):
            return f
    return None


def to_posix(p):
    """Absolute path in /c/... form, for the bash-run compile.sh."""
    s = str(pathlib.Path(p).resolve())
    if len(s) > 1 and s[1] == ":":
        s = "/" + s[0].lower() + s[2:].replace("\\", "/")
    return s


def to_win(p):
    """Absolute path in C:/... form, for objdump_command (run by native
    Windows Python via the permuter's subprocess, which can't open /c/... paths)."""
    return str(pathlib.Path(p).resolve()).replace("\\", "/")


def _expand_perm_macros(src_text):
    """Resolve PERM_GENERAL/PERM_RANDOMIZE/etc. to one concrete (seed=0) candidate,
    using decomp-permuter's own parser - the same code path permuter.py itself uses
    to generate a compilable candidate from a seed containing those macros."""
    perm_root = str(PERM_DIR)
    added = perm_root not in sys.path
    if added:
        sys.path.insert(0, perm_root)
    try:
        from src.perm.parse import perm_parse
        from src.perm.perm import EvalState
        return perm_parse(src_text).evaluate(0, EvalState())
    finally:
        if added:
            sys.path.remove(perm_root)


def candidate_reloc_offsets(base_c_path, flags):
    """Compile the seed and read its .rel.text offsets - the authoritative
    set of reloc slots to wildcard (data-pool relocs included; the compiled
    object is the source of truth, same as tools/match.py's oracle).

    A seed containing PERM_ macros (PERM_GENERAL, PERM_RANDOMIZE, ...) is not
    valid C on its own - mwccarm can't compile it, so a naive attempt silently
    fails and this used to fall back to an empty reloc list. That's a real bug:
    an empty list means those slots are compared strictly instead of wildcarded,
    which can never match (their bytes depend on link-time addresses) - putting
    an unreachable floor above 0 on every score. Expand PERM_ macros to one
    concrete candidate (decomp-permuter's own parser, seed=0) before falling
    back to a compile failure."""
    from elftools.elf.elffile import ELFFile
    import io
    with tempfile.NamedTemporaryFile(suffix=".o", delete=False) as f:
        obj = f.name
    try:
        env = __import__("os").environ.copy()
        env["LM_LICENSE_FILE"] = str(LICENSE)
        cfile = pathlib.Path(base_c_path)
        src_text = cfile.read_text(encoding="utf-8", errors="ignore")
        cpp = src_text.startswith("//cpp")
        f2 = flags.replace("-lang c99", "-lang c++") if cpp else flags

        def try_compile(text):
            with tempfile.NamedTemporaryFile(
                suffix=".cpp" if cpp else ".c", mode="w", delete=False, encoding="utf-8"
            ) as tf:
                tf.write(text)
                src_path = tf.name
            try:
                subprocess.check_call([str(MWCC), *f2.split(), "-c", "-o", obj, src_path],
                                      env=env, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
            finally:
                try:
                    __import__("os").remove(src_path)
                except OSError:
                    pass

        try:
            try_compile(src_text)
        except subprocess.CalledProcessError:
            if "PERM_" not in src_text:
                raise
            try_compile(_expand_perm_macros(src_text))

        with open(obj, "rb") as f:
            elf = ELFFile(io.BytesIO(f.read()))
            rel = elf.get_section_by_name(".rel.text") or elf.get_section_by_name(".rela.text")
            return sorted(r["r_offset"] for r in rel.iter_relocations()) if rel else []
    except Exception:
        return None
    finally:
        try:
            __import__("os").remove(obj)
        except OSError:
            pass


def setup_dir(f, base_src, out=None):
    """Write a permuter working dir for Ghidra-cache entry `f`, seeded with
    the C text `base_src`. Returns (out_path, name, addr, size, n_relocs).

    The symbol name is normally f["name"] (the Ghidra cache, FUN_xxxxxxxx
    until renamed). If base_src carries its own `// decomp:` marker (see
    tools/ledger.py) - e.g. seeding from an already-matched/renamed file to
    test the pipeline, or from a near-miss harvested elsewhere - trust ITS
    name instead, since the Ghidra cache is stale for anything renamed since
    it was last exported."""
    addr, size, module, mode = f["addr"], f["size"], f["module"], f["mode"]
    m = L.MARKER_RE.search(base_src[:400])
    name = m.group(3) if m else f["name"]
    tgt = F.target_bytes(f)
    # flags_for() only applies module+arm/thumb defaults - it never reads the
    # seed's own `// flags: ...` marker (e.g. `-O4,s` opt-level overrides),
    # unlike match.py/fdiff.py which both apply it via apply_flags_marker().
    # Without this, any seed that needs a non-default opt level (every hard
    # function iterated on this session) silently gets imported at -O4,p -
    # a real, different compiler configuration, not just a cosmetic gap -
    # invalidating whatever the permuter subsequently searches. Apply the
    # same marker logic here so the permuter tests the actual seed's flags.
    flags = M.apply_flags_marker(T.flags_for(module, mode), base_src, allow_thumb_heuristic=False)

    out = pathlib.Path(out) if out else (PERM_DIR / "work" / name)
    out.mkdir(parents=True, exist_ok=True)

    (out / "flags.txt").write_text(flags)
    (out / "compile.sh").write_text(
        f'#!/bin/bash\nexec "{to_posix(WRAPPER)}" "$@"\n')
    (out / "compile.sh").chmod(0o755)
    (out / "cc.txt").write_text(json.dumps(
        {"cmd": [to_win(MWCC), *flags.split(), "-c"], "license": to_win(LICENSE)}))
    (out / "base.c").write_text(base_src)
    (out / "target.o").write_bytes(tgt)

    reloc_offs = candidate_reloc_offsets(out / "base.c", flags)
    if reloc_offs is None:
        reloc_offs = []
    (out / "target.o.relocs").write_text("".join(f"0x{o:x}\n" for o in reloc_offs))

    objdump_cmd = f"python {to_win(CAP)}" + (" --thumb" if mode == "thumb" else "")
    (out / "settings.toml").write_text(
        f'compiler_type = "mwcc"\n'
        f'func_name = "{name}"\n'
        f'objdump_command = "{objdump_cmd}"\n')
    return out, name, addr, size, len(reloc_offs)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--module", default=None, choices=list(M.MODULES))
    ap.add_argument("--addr", type=lambda x: int(x, 0), default=None)
    ap.add_argument("--name", default=None)
    ap.add_argument("--base", default=None, help="seed C file (the draft to permute)")
    ap.add_argument("--out", default=None, help="output dir (default vendor/.../work/<name>)")
    args = ap.parse_args()
    if args.addr is None and not args.name:
        ap.error("give --addr (with --module) or --name")

    found = find_func(args.module, args.addr, args.name)
    if not found:
        print("function not found", file=sys.stderr)
        sys.exit(1)
    base_src = (pathlib.Path(args.base).read_text() if args.base
                else f"// seed: replace with a draft of {found['name']}\nvoid {found['name']}(void) {{}}\n")
    out, name, addr, size, nrel = setup_dir(found, base_src, args.out)
    print(f"imported {found['module']} {name} @ 0x{addr:08x} (size 0x{size:x}, "
         f"{found['mode']}, {nrel} relocs) -> {out}")
    print(f"run: python {to_posix(PERM_DIR / 'permuter.py')} "
         f"{to_posix(out)} --stop-on-zero -j 4")


if __name__ == "__main__":
    main()
