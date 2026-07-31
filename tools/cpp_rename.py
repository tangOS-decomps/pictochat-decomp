"""cpp_rename.py — Rename func_ADDR files to demangled C++ symbol names safely.

Renames single-function `func_ADDR.c|cpp` files to demangled `_ZN...` symbol names
when the symbol is verified/known, using `git mv` to preserve git history.

Usage:
    python tools/cpp_rename.py --dry-run          # preview proposed renames
    python tools/cpp_rename.py --apply            # apply renames + git mv
    python tools/cpp_rename.py --addr 0x020b00e8  # rename specific function
"""
import argparse
import os
import pathlib
import subprocess
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))

import demangle as DM

def load_verified_symbols():
    """Load map of addr -> symbol_name from config/arm9/symbols.txt and config/arm7/symbols.txt."""
    symbol_map = {}  # addr_hex_str -> new_symbol_name

    for config_path in [REPO / "config" / "arm9" / "symbols.txt", REPO / "config" / "arm7" / "symbols.txt"]:
        if config_path.is_file():
            for line in config_path.read_text(encoding="utf-8", errors="ignore").splitlines():
                line = line.strip()
                if not line or line.startswith("#"):
                    continue
                parts = line.split()
                if len(parts) >= 2:
                    name = parts[0]
                    if name.startswith("_Z"):
                        for p in parts[1:]:
                            if p.startswith("addr:"):
                                try:
                                    addr = int(p[5:], 16)
                                    symbol_map[f"0x{addr:08x}"] = name
                                except ValueError:
                                    pass

    v_tsv = REPO / "symbols" / "verified.tsv"
    if v_tsv.is_file():
        for line in v_tsv.read_text(encoding="utf-8", errors="ignore").splitlines():
            parts = line.strip().split("\t")
            if len(parts) >= 2:
                addr_str, name = parts[0], parts[1]
                if name.startswith("_Z"):
                    try:
                        addr = int(addr_str, 16) if addr_str.startswith("0x") else int(addr_str)
                        symbol_map[f"0x{addr:08x}"] = name
                    except ValueError:
                        pass

    return symbol_map


def find_renamable_files(target_addr=None):
    verified_map = load_verified_symbols()
    renames = []

    src_dir = REPO / "src"
    if not src_dir.is_dir():
        return renames

    for cpu_dir in (src_dir / "arm9", src_dir / "arm7"):
        if not cpu_dir.is_dir():
            continue
        for path in cpu_dir.iterdir():
            if path.suffix not in (".c", ".cpp"):
                continue

            stem = path.stem
            addr_key = None

            # Handle func_0232xxxx, FUN_0232xxxx, or _0232xxxx formats
            parts = stem.split("_")
            if len(parts) >= 2:
                last_part = parts[-1]
                if len(last_part) == 8 and all(c in "0123456789abcdefABCDEF" for c in last_part):
                    addr_key = f"0x{last_part.lower()}"

            if not addr_key:
                continue

            if target_addr and addr_key.lower() != target_addr.lower():
                continue

            if addr_key in verified_map:
                new_sym = verified_map[addr_key]
                ext = ".cpp" if path.suffix == ".cpp" or new_sym.startswith("_Z") else ".c"
                new_filename = f"{new_sym}{ext}"
                new_path = cpu_dir / new_filename

                if new_path != path:
                    renames.append({
                        "src_path": path,
                        "new_name": new_sym,
                        "new_path": new_path,
                        "addr": addr_key,
                    })

    return renames


def apply_renames(renames, dry_run=True):
    if not renames:
        print("No files ready to be renamed.")
        return

    print(f"{'[DRY RUN] Proposing' if dry_run else 'Applying'} {len(renames)} renames:\n")

    for r in renames:
        src_rel = r["src_path"].relative_to(REPO)
        dst_rel = r["new_path"].relative_to(REPO)
        sig = DM.signature(r["new_name"]) or r["new_name"]
        print(f"  {src_rel}  ->  {dst_rel}")
        print(f"    Demangled: {sig}")

        if not dry_run:
            try:
                subprocess.run(["git", "mv", str(r["src_path"]), str(r["new_path"])], check=True, cwd=REPO)
            except Exception as e:
                print(f"    [!] Error running git mv: {e}")
                # Fallback to os.rename
                os.rename(r["src_path"], r["new_path"])

    print(f"\nCompleted {'(dry-run only)' if dry_run else 'apply'}.")


def main():
    parser = argparse.ArgumentParser(description="Rename func_ADDR files to demangled C++ symbol names.")
    parser.add_argument("--dry-run", action="store_true", help="Preview proposed renames without applying.")
    parser.add_argument("--apply", action="store_true", help="Apply renames with git mv.")
    parser.add_argument("--addr", type=str, help="Target specific function address (e.g. 0x023320ac).")

    args = parser.parse_args()

    if not args.apply and not args.dry_run:
        args.dry_run = True

    renames = find_renamable_files(target_addr=args.addr)
    apply_renames(renames, dry_run=args.dry_run)


if __name__ == "__main__":
    main()
