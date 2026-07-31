"""consolidate_class.py — Consolidate single-function C++ files into unified class files.

Reads all _ZN<Class>*.cpp files for a given class name, extracts external declarations,
types, and function bodies, converts function signatures to native Class::Method syntax,
writes the consolidated src/<cpu>/<Class>.cpp file, and safely removes old single-function files.

Usage:
    python tools/consolidate_class.py --class IRQ --cpu arm9
"""
import argparse
import os
import pathlib
import re
import subprocess
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))

import demangle as DM

def collect_class_files(class_name, cpu="arm9"):
    cpu_dir = REPO / "src" / cpu
    if not cpu_dir.is_dir():
        return []

    class_files = []
    for path in cpu_dir.iterdir():
        if path.suffix in (".c", ".cpp") and path.stem.startswith("_Z"):
            d = DM.demangle(path.stem)
            if d and d.get("class") == class_name:
                class_files.append((path, d))

    class_files.sort(key=lambda x: x[0].stem)
    return class_files


def consolidate_class(class_name, cpu="arm9", apply_changes=False):
    files = collect_class_files(class_name, cpu=cpu)
    if not files:
        print(f"No standalone files found for class '{class_name}' in src/{cpu}")
        return

    print(f"Found {len(files)} standalone files for class {class_name} in src/{cpu}:")
    for p, d in files:
        print(f"  - {p.name} ({DM.signature(p.stem)})")


def main():
    parser = argparse.ArgumentParser(description="Consolidate single-function C++ files into unified class files.")
    parser.add_argument("--class", dest="class_name", required=True, help="Target class name (e.g. IRQ, CP15).")
    parser.add_argument("--cpu", default="arm9", help="Target cpu directory (arm9 or arm7).")
    parser.add_argument("--apply", action="store_true", help="Apply consolidation.")

    args = parser.parse_args()
    consolidate_class(args.class_name, cpu=args.cpu, apply_changes=args.apply)


if __name__ == "__main__":
    main()
