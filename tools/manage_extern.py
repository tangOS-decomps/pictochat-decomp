#!/usr/bin/env python3
"""Manage external NDS decompilation reference repositories in extern/

Usage:
  python tools/manage_extern.py list
  python tools/manage_extern.py clone <name|all> [--depth DEPTH]
  python tools/manage_extern.py update <name|all>
  python tools/manage_extern.py deinit <name|all>
  python tools/manage_extern.py status
"""

import argparse
import configparser
import os
import pathlib
import subprocess
import sys

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent
GITMODULES_PATH = REPO_ROOT / ".gitmodules"
EXTERN_DIR = REPO_ROOT / "extern"


def parse_gitmodules():
    """Parse .gitmodules file and return dictionary of submodule info."""
    if not GITMODULES_PATH.exists():
        return {}

    config = configparser.ConfigParser()
    config.read(GITMODULES_PATH)

    submodules = {}
    for section in config.sections():
        if section.startswith('submodule '):
            name = section.split('"')[1] if '"' in section else section[10:]
            path = config.get(section, "path", fallback="")
            url = config.get(section, "url", fallback="")
            short_name = pathlib.Path(path).name
            submodules[short_name] = {
                "name": name,
                "path": REPO_ROOT / path,
                "rel_path": path,
                "url": url
            }
    return submodules


def is_cloned(submodule_info):
    """Check if submodule path exists and is non-empty."""
    path = submodule_info["path"]
    if not path.exists():
        return False
    # Check if directory contains files other than .git if any
    items = [item for item in path.iterdir() if item.name != ".git"]
    return len(items) > 0


def cmd_list(args):
    """List all registered external repositories and their checkout status."""
    submodules = parse_gitmodules()
    if not submodules:
        print("No submodules found in .gitmodules")
        return

    print(f"{'Repository':<20} {'Status':<15} {'URL'}")
    print("=" * 70)
    for name, info in sorted(submodules.items()):
        status = "Cloned" if is_cloned(info) else "Not Cloned"
        print(f"{name:<20} {status:<15} {info['url']}")


def cmd_clone(args):
    """Clone/checkout one or all submodules."""
    submodules = parse_gitmodules()
    target = args.name.lower()

    targets = list(submodules.keys()) if target == "all" else [target]

    for name in targets:
        if name not in submodules:
            print(f"Error: Unknown extern repository '{name}'. Available: {', '.join(submodules.keys())}")
            continue

        info = submodules[name]
        rel_path = info["rel_path"]
        print(f"--> Initializing and cloning submodule {name} ({rel_path})...")

        cmd = ["git", "submodule", "update", "--init"]
        if args.depth > 0:
            cmd.extend(["--depth", str(args.depth)])
        cmd.append(rel_path)

        res = subprocess.run(cmd, cwd=REPO_ROOT)
        if res.returncode != 0:
            print(f"Submodule update returned {res.returncode}. Attempting direct clone into {rel_path}...")
            clone_cmd = ["git", "clone"]
            if args.depth > 0:
                clone_cmd.extend(["--depth", str(args.depth)])
            clone_cmd.extend([info["url"], str(info["path"])])
            res = subprocess.run(clone_cmd, cwd=REPO_ROOT)

        if res.returncode == 0:
            print(f"Successfully checked out {name}")
        else:
            print(f"Failed to clone {name} (exit code {res.returncode})")


def cmd_deinit(args):
    """De-initialize submodule files."""
    submodules = parse_gitmodules()
    target = args.name.lower()

    targets = list(submodules.keys()) if target == "all" else [target]

    for name in targets:
        if name not in submodules:
            print(f"Error: Unknown extern repository '{name}'")
            continue

        info = submodules[name]
        rel_path = info["rel_path"]
        print(f"--> De-initializing submodule {name} ({rel_path})...")

        cmd = ["git", "submodule", "deinit", "-f", rel_path]
        subprocess.run(cmd, cwd=REPO_ROOT)


def cmd_update(args):
    """Update submodules from remote."""
    submodules = parse_gitmodules()
    target = args.name.lower()

    targets = list(submodules.keys()) if target == "all" else [target]

    for name in targets:
        if name not in submodules:
            print(f"Error: Unknown extern repository '{name}'")
            continue

        info = submodules[name]
        rel_path = info["rel_path"]
        print(f"--> Updating submodule {name}...")
        cmd = ["git", "submodule", "update", "--remote", rel_path]
        subprocess.run(cmd, cwd=REPO_ROOT)


def cmd_status(args):
    """Display git submodule status."""
    subprocess.run(["git", "submodule", "status"], cwd=REPO_ROOT)


def main():
    parser = argparse.ArgumentParser(description="Manage external NDS decompilation reference repos")
    subparsers = parser.add_subparsers(dest="subcommand", help="Subcommand to execute")

    # list
    p_list = subparsers.add_parser("list", help="List registered extern repositories")
    p_list.set_defaults(func=cmd_list)

    # clone
    p_clone = subparsers.add_parser("clone", help="Clone/checkout an extern repository")
    p_clone.add_argument("name", help="Repository name or 'all'")
    p_clone.add_argument("--depth", type=int, default=1, help="Shallow clone depth (default: 1)")
    p_clone.set_defaults(func=cmd_clone)

    # deinit
    p_deinit = subparsers.add_parser("deinit", help="De-initialize an extern repository")
    p_deinit.add_argument("name", help="Repository name or 'all'")
    p_deinit.set_defaults(func=cmd_deinit)

    # update
    p_update = subparsers.add_parser("update", help="Update extern repository from remote")
    p_update.add_argument("name", help="Repository name or 'all'")
    p_update.set_defaults(func=cmd_update)

    # status
    p_status = subparsers.add_parser("status", help="Show submodule status")
    p_status.set_defaults(func=cmd_status)

    args = parser.parse_args()
    if not args.subcommand:
        parser.print_help()
        sys.exit(1)

    args.func(args)


if __name__ == "__main__":
    main()
