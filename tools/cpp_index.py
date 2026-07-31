"""cpp_index.py — Class-level decompilation index tool for PictoChat.

Aggregates all C++ symbols across the codebase (from src/, config symbol files,
and tsv symbol lists) and presents a structured view grouped by class.

Usage:
    python tools/cpp_index.py                      # all classes summary
    python tools/cpp_index.py --class CP15         # inspect single class
    python tools/cpp_index.py --json report.json   # export machine-readable JSON
    python tools/cpp_index.py --md report.md       # export Markdown summary
"""
import argparse
import json
import os
import pathlib
import re
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))

import demangle as DM

def load_all_symbols():
    """Load symbols from config/arm9/symbols.txt and config/arm7/symbols.txt."""
    symbols = {}  # name -> dict(module, addr, size)

    for mod, cfg_path in [("arm9", REPO / "config" / "arm9" / "symbols.txt"), ("arm7", REPO / "config" / "arm7" / "symbols.txt")]:
        if cfg_path.is_file():
            for line in cfg_path.read_text(encoding="utf-8", errors="ignore").splitlines():
                line = line.strip()
                if not line or line.startswith("#"):
                    continue
                parts = line.split()
                if len(parts) >= 2:
                    name = parts[0]
                    addr = None
                    size = 0
                    kind = "function"
                    for p in parts[1:]:
                        if p.startswith("addr:"):
                            try: addr = int(p[5:], 16)
                            except ValueError: pass
                        elif p.startswith("size:"):
                            try: size = int(p[5:], 16)
                            except ValueError: pass
                        elif p.startswith("kind:"):
                            kind = p[5:].split("(")[0]
                    if name and addr is not None:
                        symbols[name] = {"name": name, "module": mod, "addr": addr, "size": size, "kind": kind}

    return symbols


def build_class_index():
    symbols = load_all_symbols()
    classes = {}  # class_name -> dict(methods, total_size, matched_count)

    src_files = {}
    for cpu in ("arm9", "arm7"):
        cpu_dir = REPO / "src" / cpu
        if cpu_dir.is_dir():
            for path in cpu_dir.iterdir():
                if path.suffix in (".c", ".cpp"):
                    src_files[path.stem] = path

    for name, sym in symbols.items():
        if not name.startswith("_Z"):
            continue
        d = DM.demangle(name)
        if not d or not d.get("class"):
            continue

        klass = d["class"]
        if klass not in classes:
            classes[klass] = {
                "class": klass,
                "methods": [],
                "total_methods": 0,
                "matched_methods": 0,
                "total_bytes": 0,
            }

        is_matched = name in src_files
        classes[klass]["total_methods"] += 1
        classes[klass]["total_bytes"] += sym.get("size", 0)
        if is_matched:
            classes[klass]["matched_methods"] += 1

        classes[klass]["methods"].append({
            "name": name,
            "signature": DM.signature(name),
            "addr": f"0x{sym['addr']:08x}",
            "size": sym.get("size", 0),
            "matched": is_matched,
            "file": str(src_files[name].relative_to(REPO)) if is_matched else None,
        })

    return classes


def main():
    parser = argparse.ArgumentParser(description="Class-level decompilation index tool.")
    parser.add_argument("--class", dest="target_class", help="Filter by specific class name (e.g. CP15, IRQ).")
    parser.add_argument("--json", type=str, help="Export result to JSON file.")
    parser.add_argument("--md", type=str, help="Export result to Markdown file.")

    args = parser.parse_args()
    classes = build_class_index()

    if args.target_class:
        if args.target_class in classes:
            cinfo = classes[args.target_class]
            print(f"Class {cinfo['class']}: {cinfo['matched_methods']}/{cinfo['total_methods']} methods matched ({cinfo['total_bytes']} bytes)")
            for m in cinfo["methods"]:
                status = "[MATCHED]" if m["matched"] else "[UNMATCHED]"
                print(f"  {status} {m['addr']} {m['signature']}")
        else:
            print(f"Class '{args.target_class}' not found.")
        return

    print("C++ Class Summary:")
    print("-" * 60)
    for klass, cinfo in sorted(classes.items(), key=lambda x: x[1]["total_methods"], reverse=True):
        print(f"  {klass:<25} {cinfo['matched_methods']:>3}/{cinfo['total_methods']:<3} matched ({cinfo['total_bytes']:>6} bytes)")

    if args.json:
        pathlib.Path(args.json).write_text(json.dumps(classes, indent=2), encoding="utf-8")
        print(f"\nExported JSON to {args.json}")

    if args.md:
        lines = ["# C++ Class Decompilation Summary\n", "| Class | Matched / Total | Total Bytes |", "| --- | --- | --- |"]
        for klass, cinfo in sorted(classes.items(), key=lambda x: x[1]["total_methods"], reverse=True):
            lines.append(f"| `{klass}` | {cinfo['matched_methods']} / {cinfo['total_methods']} | {cinfo['total_bytes']} |")
        pathlib.Path(args.md).write_text("\n".join(lines), encoding="utf-8")
        print(f"\nExported Markdown to {args.md}")


if __name__ == "__main__":
    main()
