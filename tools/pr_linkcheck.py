"""PR-scoped compile+verify: for each src file a PR adds/modifies, resolve its
symbol from the file's own `// decomp: module=... addr=... name=...` header,
compile the committed source with the canonical mwccarm version, and
byte-compare (relocation slots wildcarded) against the extracted binary.

WHY THIS EXISTS / WHAT IT DOES NOT DO
--------------------------------------
Ported from sm64ds-decomp's tools/pr_linkcheck.py, adapted for this repo's
layout: src/ is split by CPU (arm9/arm7), ARM9 spans four segments (main,
itcm, unk_autoload_0, unk_autoload_2), and the header comment -- not the
filename -- is the reliable symbol name (some files are named
`<mangled-name>_<addr>.cpp`, not `<mangled-name>.cpp`).

Unlike the sm64ds-decomp version, this CANNOT check relocation *destinations*:
that needs config/**/relocs.txt, which doesn't exist yet for this title
(`dsd init` doesn't complete here -- see config/README.md). So a function can
compile byte-identical with a relocation slot pointed at the WRONG callee/
global and this tool will still call it VERIFIED. It only proves the
instruction words and reloc *positions* match, not reloc *targets*. Revisit
once relocs.txt exists (tools/relocs.py would need porting too).

Usage:
  python tools/pr_linkcheck.py                          # local branch vs origin/main
  python tools/pr_linkcheck.py --base main               # vs a different base ref
  python tools/pr_linkcheck.py --pr 12                    # a GitHub PR (needs gh)
  python tools/pr_linkcheck.py --files src/arm9/a.c src/arm7/b.cpp
  python tools/pr_linkcheck.py --json out.json --md out.md --fail   # CI mode
"""
import argparse
import glob
import io
import json
import pathlib
import re
import subprocess
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import match as M  # noqa: E402
from elftools.elf.elffile import ELFFile  # noqa: E402

_HEADER_RE = re.compile(
    r"^//\s*decomp:\s*module=(\S+)\s+addr=0x([0-9a-fA-F]+)\s+name=(\S+)", re.MULTILINE)
_SYM_LINE_RE = re.compile(
    r"^name=(\S+)\s+module=(\S+)\s+addr=0x([0-9a-fA-F]+)\s+size=0x([0-9a-fA-F]+)")


def build_symbol_index():
    """symbol name -> [(addr, size, module), ...] from every generated symbols.txt.

    These are Ghidra-derived boundaries (tools/gen_symbols.py), not a matching
    ledger -- every changed file's declared symbol must appear here or its size
    (needed for the byte-compare) can't be resolved."""
    idx = {}
    for sf in glob.glob(str(REPO / "config" / "*" / "symbols.txt")):
        for line in open(sf, encoding="utf-8"):
            m = _SYM_LINE_RE.match(line.strip())
            if m:
                name, module, addr, size = m.groups()
                idx.setdefault(name, []).append((int(addr, 16), int(size, 16), module))
    return idx


def changed_src_files(args):
    if args.files:
        paths = args.files
    elif args.pr:
        out = subprocess.run(
            ["gh", "pr", "view", str(args.pr), "--json", "files",
             "-q", ".files[].path"],
            cwd=REPO, capture_output=True, text=True, check=True).stdout
        paths = out.splitlines()
    else:
        out = subprocess.run(
            ["git", "diff", "--name-only", "--diff-filter=AM", f"{args.base}...HEAD"],
            cwd=REPO, capture_output=True, text=True, check=True).stdout
        paths = out.splitlines()
    keep = []
    for p in paths:
        p = p.strip()
        if p.startswith("src/") and (p.endswith(".c") or p.endswith(".cpp")):
            keep.append(p)
    return keep


def emitted_func_symbols(obj: bytes):
    """Every STT_FUNC symbol name a compiled object defines. Needed because this
    repo's C++ file headers name the address (`FUN_02320728`), not the mangled
    symbol a class method actually links as -- unlike sm64ds-decomp, where "the
    filename IS the mangled symbol". So a header-named lookup can miss even
    though the file compiled a real, matching function under its true name."""
    elf = ELFFile(io.BytesIO(obj))
    symtab = elf.get_section_by_name(".symtab")
    if symtab is None:
        return []
    return [s.name for s in symtab.iter_symbols()
            if s["st_info"]["type"] == "STT_FUNC" and s.name
            and not s.name.startswith("$")  # ARM/Thumb mapping symbols ($t/$a/$d), not real functions
            and s["st_size"] > 0]


def resolve_flags(cfile: pathlib.Path, src_text: str, module: str) -> list[str]:
    """Mirrors match.py main()'s flag selection: module picks the base ARM7/ARM9
    set, then //cpp switches the language and a `// flags: ` line or bare `asm`
    keyword can override -thumb, same as a human running match.py by hand would.

    Returns a LIST to try, not one string: match.py's own docstring says "not
    every function will be Thumb (some hot paths may be -noThumb) - override
    per-function ... if a candidate ... comes out the wrong size", but plenty of
    already-matched files here predate the `// flags: ` convention and carry no
    such override. Rather than only ever guess Thumb and call anything else a
    failure, try the no-Thumb variant too when nothing pins it explicitly."""
    flags = M.DEFAULT_FLAGS_ARM7 if module == "arm7" else M.DEFAULT_FLAGS
    if src_text.startswith("//cpp") and "-lang c99" in flags:
        flags = flags.replace("-lang c99", "-lang c++")
    if "// flags: " in src_text:
        # Delegate to match.py's apply_flags_marker() instead of reimplementing
        # it. The old local copy treated the marker as EITHER an opt-level
        # override OR a -noThumb strip, so a marker carrying BOTH (e.g.
        # `// flags: -O4,s -noThumb`, which FUN_022d5a64 needs) silently kept
        # the default -O4,p and reported a real match as NO-REPRO.
        # apply_flags_marker applies every token structurally - notably it
        # REPLACES the base -O token rather than appending a second one, which
        # mwccarm mis-handles (see notes/tooling.md).
        return [M.apply_flags_marker(flags, src_text, allow_thumb_heuristic=False)]
    if re.search(r"\basm\b", src_text) and "-thumb" in flags:
        # match.py's own heuristic here is a preference, not a certainty: at
        # least one real file (FUN_02332d10, a bare SWI trampoline) documents
        # that the literal word "asm" triggers this strip but the function
        # actually needs -thumb KEPT. Try the heuristic's guess first, then
        # the opposite, instead of failing outright when it guesses wrong.
        return [flags.replace(" -thumb", ""), flags]
    if " -thumb" in flags:
        return [flags, flags.replace(" -thumb", "")]
    return [flags]


def check_file(path: str, idx: dict):
    cfile = REPO / path
    try:
        src_text = cfile.read_text(encoding="utf-8")
    except OSError as e:
        return {"file": path, "symbol": None, "verdict": "UNRESOLVED",
                "detail": f"cannot read file: {e}"}

    header = _HEADER_RE.search(src_text)
    if not header:
        return {"file": path, "symbol": None, "verdict": "UNRESOLVED",
                "detail": "no `// decomp: module=... addr=... name=...` header"}
    module, addr, name = header.group(1), int(header.group(2), 16), header.group(3)

    if "// NONMATCHING:" in src_text:
        # Parked by tools/nonmatching.py: a logic-correct decompilation that is
        # deliberately NOT byte-exact. tools/progress.py counts these
        # separately; failing a PR because one does not reproduce would just be
        # re-reporting what the file already declares about itself.
        return {"file": path, "symbol": name, "verdict": "PARKED",
                "detail": "parked `// NONMATCHING:` - not expected to reproduce byte-for-byte"}

    if name not in idx:
        # Not fatal -- Ghidra's boundary table isn't the size source of truth
        # (see below), just a sanity check that this isn't a typo'd/hallucinated
        # symbol name with no basis in the analysis at all.
        return {"file": path, "symbol": name, "verdict": "UNRESOLVED",
                "detail": f"'{name}' not in config/*/symbols.txt (regenerate with tools/gen_symbols.py?)"}

    flags_variants = resolve_flags(cfile, src_text, module)

    # Sweep mwccarm versions rather than trust a single M.CANONICAL: unlike
    # sm64ds-decomp (whose canonical pin is proven across 100+ functions), this
    # repo's own match.py says its CANONICAL is "still just a starting guess -
    # not yet verified by any real match". Different already-matched functions
    # here may have been confirmed under different dsi/ builds, so a fixed
    # version under-checks real PRs. Same versions match.py --trio sweeps.
    # Crossed with every flags variant (see resolve_flags -- typically just
    # Thumb-vs-ARM) since files predating `// flags: ` carry no explicit pin.
    best = None  # (ndiff, version, flags, resolved_name, code, relocs, target, ok, detail_extra)
    any_compiled = False
    found = False
    for flags in flags_variants:
        if found:
            break
        for version in M.PINNED:
            obj = M.compile_c(cfile, version, flags)
            if obj is None:
                continue
            any_compiled = True

            code, relocs, _reloc_info = M.extract_func(obj, name)
            if code is None:
                # The header's name is descriptive (address-based), not
                # necessarily the real link symbol -- true for every C++ class
                # method in this repo's convention. Try every function the
                # object actually emits and see which byte-matches at the addr.
                for cand_name in emitted_func_symbols(obj):
                    if cand_name == name:
                        continue
                    cand_code, cand_relocs, _ = M.extract_func(obj, cand_name)
                    if cand_code is None:
                        continue
                    try:
                        cand_target = M.target_bytes(module, addr, len(cand_code))
                    except SystemExit:
                        continue
                    ok, ndiff = M.compare(cand_target, cand_code, cand_relocs, verbose=False)
                    extra = f"header names '{name}' but the object links as '{cand_name}'"
                    if best is None or ndiff < best[0]:
                        best = (ndiff, version, flags, cand_name, cand_code, cand_relocs, cand_target, ok, extra)
                    if ok:
                        found = True
                        break
                if found:
                    break
                continue

            try:
                target = M.target_bytes(module, addr, len(code))
            except SystemExit as e:
                return {"file": path, "symbol": name, "verdict": "UNRESOLVED", "detail": str(e)}
            ok, ndiff = M.compare(target, code, relocs, verbose=False)
            if best is None or ndiff < best[0]:
                best = (ndiff, version, flags, name, code, relocs, target, ok, "")
            if ok:
                found = True
                break

    if not any_compiled:
        return {"file": path, "symbol": name, "verdict": "COMPILE-FAIL",
                "detail": f"mwccarm failed to compile this file under every swept version ({', '.join(M.PINNED)})"}
    if best is None:
        return {"file": path, "symbol": name, "verdict": "COMPILE-FAIL",
                "detail": "compiled, but no emitted symbol matched the header name or the target address"}

    ndiff, version, flags, resolved_name, code, relocs, target, ok, extra = best
    verdict = "VERIFIED" if ok else "NO-REPRO"
    detail_bits = [extra] if extra else []
    if not ok:
        detail_bits.append(f"{ndiff} word(s) differ from the extracted binary (closest: {version}, `{flags}`)")
    return {"file": path, "symbol": resolved_name, "verdict": verdict,
            "detail": "; ".join(detail_bits), "addr": f"0x{addr:08x}", "module": module}


_LABEL = {
    "VERIFIED":     "✅ verified (compile + byte-identical; reloc *targets* not checked)",
    "NO-REPRO":     "❌ near-miss (does NOT reproduce the binary)",
    "COMPILE-FAIL": "❌ compile failed",
    "UNRESOLVED":   "🔶 unresolved (no header / not in symbols.txt)",
    "PARKED":       "⏸️ parked NONMATCHING (logic-correct, not byte-exact by declaration)",
}
_FAIL = {"NO-REPRO", "COMPILE-FAIL"}


def render_md(reports, bad):
    n = len(reports)
    out = []
    if bad:
        kinds = ", ".join(sorted({r["verdict"] for r in reports if r["verdict"] in _FAIL}))
        out.append(f"**{len(bad)} of {n} changed file(s) do not compile/match** ({kinds}).")
    else:
        n_ver = sum(1 for r in reports if r["verdict"] == "VERIFIED")
        n_park = sum(1 for r in reports if r["verdict"] == "PARKED")
        n_unres = sum(1 for r in reports if r["verdict"] == "UNRESOLVED")
        bits = [f"{n_ver} verified byte-for-byte"]
        if n_park:
            bits.append(f"{n_park} parked NONMATCHING (not expected to reproduce)")
        if n_unres:
            bits.append(f"{n_unres} unresolved")
        out.append(f"**{n} changed file(s): " + ", ".join(bits) + ".**")
    out.append("")
    out.append("_Relocation **destinations** are not yet verified for this repo "
                "(no config/**/relocs.txt) -- only instruction words and reloc "
                "**positions**. See tools/pr_linkcheck.py docstring._")
    out += ["", "| File | Symbol | Result | Detail |", "|---|---|---|---|"]
    for r in reports:
        out.append(f"| `{r['file']}` | `{r['symbol'] or '?'}` | "
                    f"{_LABEL.get(r['verdict'], r['verdict'])} | {r['detail']} |")
    return "\n".join(out) + "\n"


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--base", default="origin/main", help="base ref for git diff")
    ap.add_argument("--pr", type=int, default=None, help="GitHub PR number (uses gh)")
    ap.add_argument("--files", nargs="*", help="explicit file list instead of a diff")
    ap.add_argument("--json", default=None)
    ap.add_argument("--md", default=None, help="write a markdown report (for PR comments)")
    ap.add_argument("--fail", action="store_true",
                    help="exit 1 if any file fails to compile or match")
    args = ap.parse_args()

    idx = build_symbol_index()
    files = changed_src_files(args)
    if not files:
        print("no changed src/*.c|*.cpp files to check")
        return

    print(f"link-checking {len(files)} changed src file(s) ...\n")
    reports, bad = [], []
    for path in files:
        rep = check_file(path, idx)
        reports.append(rep)
        mark = {"VERIFIED": "ok     ", "NO-REPRO": "NOREPRO", "COMPILE-FAIL": "FAIL   ",
                "UNRESOLVED": "?      "}.get(rep["verdict"], rep["verdict"])
        print(f"  {mark} {path}  ({rep['symbol'] or '?'})" + (f" -- {rep['detail']}" if rep['detail'] else ""))
        if rep["verdict"] in _FAIL:
            bad.append((path, rep["verdict"]))

    if args.json:
        pathlib.Path(args.json).write_text(json.dumps(reports, indent=1))
    if args.md:
        pathlib.Path(args.md).write_text(render_md(reports, bad), encoding="utf-8")
    if bad:
        print("\nvalidation FAILED: " + "; ".join(f"{p} [{v}]" for p, v in bad))
        if args.fail:
            sys.exit(1)


if __name__ == "__main__":
    main()
