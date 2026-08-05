#!/usr/bin/env python3
"""Check that this machine can actually compile - run it on a validator box.

`tools/pr_linkcheck.py` compiles every changed src file with the pinned mwccarm
builds. The compilers are proprietary and gitignored (see
notes/setup-mwccarm.md), so a fresh clone has NONE of them and every check
fails. Worse, `match.py`'s compile_c() returns None both for "compiler not
installed" and "your C is broken", so an unprovisioned box used to report a
perfectly good source file as COMPILE-FAIL. That really happened: when the
project pin moved from dsi/* to 2.0/*, the box still had only the dsi/* set.

This tells you what is missing and proves what is present by actually
compiling a probe, so provisioning is a checklist rather than a guess:

    python tools/check_toolchain.py           # human report, exit 1 if unusable
    python tools/check_toolchain.py --json    # machine-readable

Exit status: 0 if at least the CANONICAL build works (the box can validate),
1 otherwise.
"""
import argparse
import json
import os
import pathlib
import shutil
import subprocess
import sys
import tempfile

REPO = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import match as M  # noqa: E402

# Every file mwccarm needs beside itself; a version dir with mwccarm.exe alone
# fails at runtime with a DLL error that looks nothing like "not installed".
SUPPORT = ["ELFIO.dll", "MSL_All-DLL80_x86.dll", "lmgr8c.dll",
           "mwasmarm.exe", "mwldarm.exe"]

PROBE = "int probe_fn(int a, int b) { return a + b; }\n"


def check_version(version):
    """-> dict describing one pinned build on this machine."""
    d = M.MW / version
    exe = d / "mwccarm.exe"
    r = {"version": version, "dir": str(d), "exe": exe.is_file(),
         "missing_support": [], "compiles": False, "error": None}
    if not exe.is_file():
        r["error"] = "mwccarm.exe not present"
        return r
    r["missing_support"] = [s for s in SUPPORT if not (d / s).is_file()]
    with tempfile.TemporaryDirectory() as td:
        src = pathlib.Path(td) / "probe.c"
        src.write_text(PROBE)
        obj = M.compile_c(src, version, M.DEFAULT_FLAGS_ARM7.replace(" -thumb", ""))
    if obj is None:
        r["error"] = ("compiler present but the probe did not compile"
                      + (f" (missing: {', '.join(r['missing_support'])})"
                         if r["missing_support"] else ""))
        return r
    r["compiles"] = True
    return r


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--json", action="store_true")
    a = ap.parse_args()

    launcher = os.environ.get("MWCCARM_LAUNCHER", "")
    report = {
        "repo": str(REPO),
        "toolchain_dir": str(M.MW),
        "toolchain_dir_from_env": M.MW_FROM_ENV,
        "canonical": M.CANONICAL,
        "pinned": list(M.PINNED),
        "license": (M.LICENSE.is_file()),
        "license_path": str(M.LICENSE),
        "launcher": launcher or None,
        "wine_on_path": bool(shutil.which("wine")),
        "windows": sys.platform.startswith("win"),
        "versions": [check_version(v) for v in M.PINNED],
    }
    working = [v["version"] for v in report["versions"] if v["compiles"]]
    report["working"] = working
    report["canonical_works"] = M.CANONICAL in working
    report["usable"] = bool(working)

    if a.json:
        print(json.dumps(report, indent=2))
        return 0 if report["canonical_works"] else 1

    print(f"repo            : {report['repo']}")
    print(f"toolchain dir   : {report['toolchain_dir']}"
          f"   ({'MWCCARM_DIR' if report['toolchain_dir_from_env'] else 'in-tree default'})")
    if not report["toolchain_dir_from_env"]:
        print("                  ^ in-tree and gitignored, so a clean/re-clone deletes it; "
              "on a validator box set MWCCARM_DIR to a path outside the clone")
    print(f"canonical build : {report['canonical']}")
    print(f"license.dat     : {'OK' if report['license'] else 'MISSING'}  ({report['license_path']})")
    if not report["windows"]:
        print(f"launcher        : MWCCARM_LAUNCHER={launcher or '(unset)'}"
              f"   wine on PATH: {'yes' if report['wine_on_path'] else 'NO'}")
        if not launcher:
            print("                  ^ on a non-Windows box this must be set "
                  "(e.g. MWCCARM_LAUNCHER=wine) or every compile returns None")
    print()
    for v in report["versions"]:
        if v["compiles"]:
            print(f"  OK       {v['version']}")
        else:
            print(f"  MISSING  {v['version']:14s} {v['error']}")
    print()
    if report["canonical_works"]:
        print(f"USABLE: {len(working)}/{len(M.PINNED)} pinned build(s) work, including the canonical one.")
        return 0
    if working:
        print(f"PARTIAL: {len(working)}/{len(M.PINNED)} work but the CANONICAL build "
              f"({M.CANONICAL}) does not. Validation will still run, but install the "
              f"canonical build so local and CI verdicts agree.")
        return 1
    print("UNUSABLE: no pinned mwccarm build works on this machine, so nothing can be")
    print(f"validated. Install the pinned toolchain into {M.MW}{os.sep}<version>{os.sep} -")
    print(f"each needs mwccarm.exe plus {', '.join(SUPPORT)} - and put the shared")
    print(f"license.dat at {M.LICENSE}. See notes/setup-mwccarm.md.")
    return 1


if __name__ == "__main__":
    sys.exit(main())
