"""Batch-verify that mangled C++ functions still byte-match.

Reads all _Z... files in src/arm9 and src/arm7 and re-runs match.py for each,
printing a pass/fail summary.

Usage:
    python tools/verify_mangled.py            # verify all mangled C++ funcs
    python tools/verify_mangled.py _ZN3IRQ    # verify only names matching a substring
"""
import pathlib
import subprocess
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent

filt = sys.argv[1] if len(sys.argv) > 1 else ""

mangled_files = []
for cpu in ("arm9", "arm7"):
    cpu_dir = REPO / "src" / cpu
    if cpu_dir.is_dir():
        for p in cpu_dir.iterdir():
            if p.suffix in (".c", ".cpp") and p.stem.startswith("_Z") and filt in p.stem:
                mangled_files.append((cpu, p))

mangled_files.sort(key=lambda x: x[1].name)
npass = nfail = 0
fails = []

print(f"Verifying {len(mangled_files)} mangled C++ functions...\n")

for cpu, p in mangled_files:
    name = p.stem
    mod = "arm7" if cpu == "arm7" else "unk_autoload_0"
    cmd = [
        sys.executable, str(REPO / "tools" / "match.py"),
        "--c", str(p), "--func", name,
    ]
    r = subprocess.run(cmd, capture_output=True, text=True)
    ok = r.returncode == 0 and "MATCHING" in r.stdout.upper()
    if ok:
        npass += 1
        print(f"PASS {name}")
    else:
        nfail += 1
        fails.append(name)
        print(f"FAIL {name}")
        print("    " + (r.stdout.strip().replace("\n", "\n    ")[-500:]))

print(f"\n{npass} pass, {nfail} fail (of {len(mangled_files)})")
if fails:
    print("FAILED:", ", ".join(fails))
    sys.exit(1)
