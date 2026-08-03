#!/usr/bin/env python3
"""NDS Decompilation Pattern Scraper & Cross-Referencing Tool Suite

This tool scrapes external Nintendo DS decompilation repositories (and local reference files)
for common patterns, function signatures, assembly snippets, and hardware/SDK idioms.
It builds a cross-reference database allowing any NDS decomp project to find matching
code, assembly patterns, and SDK routines.

Usage:
  python tools/cross_reference.py scrape [--extern-dir DIR] [--output INDEX_FILE]
  python tools/cross_reference.py search [--name NAME] [--asm QUERY] [--category CAT] [--repo REPO]
  python tools/cross_reference.py cross-match [--funcs-file JSON_FILE] [--min-score SCORE]
  python tools/cross_reference.py notes QUERY [--context N]
  python tools/cross_reference.py info

For "I have a weird instruction sequence in the target ROM, what C produces it":
  1. `notes` first - search other decomp projects' own hand-written codegen-lever
     docs (e.g. sm64ds-decomp/notes/mwccarm-codegen.md) for the idiom by name/keyword.
     Someone on the same toolchain may have already solved and documented it.
  2. `search --category <cat>` - grep extern repos' matched C source for the raw
     idiom itself (shift-truncation pairs, movne/moveq conditional selects, hand-
     written "// to match this compiler quirk" comments, volatile-for-codegen use).
     See config/extern_config.json's assembly_categories for the full list.
"""

import argparse
import hashlib
import json
import os
import pathlib
import re
import sys
from typing import Dict, List, Any, Optional

# Windows' console defaults to cp1252, which can't encode a lot of what real decomp
# repos' docs/comments contain (->, checkmarks, etc.) - crashes mid-print otherwise.
# reconfigure() is a no-op cost-wise and safe on every platform (Python 3.7+).
for _stream in (sys.stdout, sys.stderr):
    if hasattr(_stream, "reconfigure"):
        _stream.reconfigure(encoding="utf-8", errors="replace")

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent
DEFAULT_CONFIG_PATH = REPO_ROOT / "config" / "extern_config.json"
DEFAULT_INDEX_PATH = REPO_ROOT / "extern" / "pattern_index.json"
OUR_FUNCS_CACHE = REPO_ROOT / "extracted" / "pictochat_funcs.json"


class PatternScraper:
    def __init__(self, config: Dict[str, Any]):
        self.config = config
        self.sdk_prefixes = config.get("sdk_prefixes", [])
        self.msl_symbols = config.get("msl_symbols", [])
        self.categories = config.get("assembly_categories", {})
        self.extensions = set(config.get("file_extensions", [".c", ".cpp", ".h", ".hpp", ".s", ".asm", ".inc"]))

    def normalize_asm(self, asm_text: str) -> str:
        """Normalize assembly code for opcode sequence fingerprinting."""
        lines = []
        for line in asm_text.splitlines():
            # strip comments
            line = re.sub(r"/\*.*?\*/", "", line)
            line = re.sub(r"//.*$", "", line)
            line = re.sub(r"@.*$", "", line)
            line = re.sub(r";.*$", "", line)
            line = line.strip()
            if not line or line.startswith(".") or line.endswith(":"):
                continue

            # Replace large hex / addresses with #ADDR
            line = re.sub(r"#0x[0-9a-fA-F]{5,}", "#ADDR", line)
            line = re.sub(r"0x[0-9a-fA-F]{5,}", "ADDR", line)
            # Replace PC-relative literals
            line = re.sub(r"\[pc,?[^\]]*\]", "[pc,ADDR]", line)

            lines.append(line)
        return "\n".join(lines)

    def extract_patterns_from_file(self, file_path: pathlib.Path, repo_name: str) -> List[Dict[str, Any]]:
        """Parse a single source file and return extracted symbols and assembly patterns."""
        try:
            content = file_path.read_text(encoding="utf-8", errors="ignore")
        except Exception:
            return []

        rel_path = str(file_path.relative_to(REPO_ROOT)) if file_path.is_relative_to(REPO_ROOT) else str(file_path)
        records = []
        ext = file_path.suffix.lower()

        # 1. Function definitions & SDK symbols in C/C++
        if ext in (".c", ".cpp", ".h", ".hpp"):
            # C Function pattern matching. No leading "(?:word\s+)+" return-type group -
            # it's unnecessary (the name capture below already anchors on \w+ right before
            # the paren) and was a real ReDoS: on any `extern void f(void);`-style
            # declaration-only line (no trailing `{`), that nested quantifier forces
            # catastrophic backtracking while trying every split before failing. Real repos
            # (khdays-decomp) ship thousands of exactly this file shape (asm_stubs/calls/*.c,
            # pure extern-declaration lists) - confirmed hanging for 90+s on a single 9.5KB
            # file before this fix.
            func_regex = re.compile(
                r"(\b(?:[A-Z0-9_]+_)?\w+)\s*\(([^;{]*)\)\s*\{"
            )
            for m in func_regex.finditer(content):
                func_name = m.group(1)
                # Ignore control flow / C keywords mistaken for funcs
                if func_name in ("if", "while", "for", "switch", "return", "sizeof", "else"):
                    continue

                is_sdk = any(func_name.startswith(p) for p in self.sdk_prefixes)
                is_msl = func_name in self.msl_symbols

                records.append({
                    "type": "function",
                    "name": func_name,
                    "file": rel_path,
                    "repo": repo_name,
                    "is_sdk": is_sdk,
                    "is_msl": is_msl,
                    "line": content[:m.start()].count("\n") + 1,
                    "snippet": content[m.start():min(m.start() + 200, len(content))].strip()
                })

            # Check special assembly categories inside C files (inline asm or pragma asm)
            for cat_name, cat_info in self.categories.items():
                pattern = re.compile(cat_info["regex"], re.IGNORECASE)
                for m in pattern.finditer(content):
                    line_no = content[:m.start()].count("\n") + 1
                    records.append({
                        "type": "category_match",
                        "category": cat_name,
                        "category_desc": cat_info.get("description", ""),
                        "file": rel_path,
                        "repo": repo_name,
                        "line": line_no,
                        "match": m.group(0),
                        "snippet": content[max(0, m.start() - 40):min(len(content), m.end() + 60)].strip()
                    })

        # 2. Assembly files (.s, .asm, .inc)
        elif ext in (".s", ".asm", ".inc"):
            # Extract assembly labels/functions (ignore local labels like .L or _020...)
            label_regex = re.compile(r"^(arm_func\s+|thumb_func\s+|\.global\s+)?([a-zA-Z_][a-zA-Z0-9_]*):", re.MULTILINE)
            for m in label_regex.finditer(content):
                label_name = m.group(2)
                if label_name.startswith(".") or label_name.startswith("_0"):
                    continue
                line_no = content[:m.start()].count("\n") + 1
                is_sdk = any(label_name.startswith(p) for p in self.sdk_prefixes)
                is_msl = label_name in self.msl_symbols

                records.append({
                    "type": "asm_label",
                    "name": label_name,
                    "file": rel_path,
                    "repo": repo_name,
                    "is_sdk": is_sdk,
                    "is_msl": is_msl,
                    "line": line_no
                })

            # Check categories in assembly
            for cat_name, cat_info in self.categories.items():
                pattern = re.compile(cat_info["regex"], re.IGNORECASE)
                for m in pattern.finditer(content):
                    line_no = content[:m.start()].count("\n") + 1
                    records.append({
                        "type": "category_match",
                        "category": cat_name,
                        "category_desc": cat_info.get("description", ""),
                        "file": rel_path,
                        "repo": repo_name,
                        "line": line_no,
                        "match": m.group(0),
                        "snippet": content[max(0, m.start() - 40):min(len(content), m.end() + 60)].strip()
                    })

            # Fingerprint assembly file blocks
            norm_asm = self.normalize_asm(content)
            if norm_asm:
                asm_hash = hashlib.sha256(norm_asm.encode("utf-8")).hexdigest()[:16]
                records.append({
                    "type": "asm_fingerprint",
                    "hash": asm_hash,
                    "file": rel_path,
                    "repo": repo_name,
                    "sample": norm_asm[:300]
                })

        return records


def run_scrape(config_path: pathlib.Path, index_path: pathlib.Path):
    """Scrape extern/ directory and local reference paths to build pattern index."""
    if not config_path.exists():
        print(f"Error: Config file {config_path} not found.")
        sys.exit(1)

    config = json.loads(config_path.read_text(encoding="utf-8"))
    scraper = PatternScraper(config)

    extern_dir = REPO_ROOT / "extern"
    search_dirs = [extern_dir]

    # Also search local reference folders if present
    for extra_dir in ["src", "asm", "drafts"]:
        p = REPO_ROOT / extra_dir
        if p.exists():
            search_dirs.append(p)

    all_records = []
    scanned_files = 0
    scanned_repos = set()

    print(f"Scraping NDS patterns across: {[str(d) for d in search_dirs]}...")

    SKIP_DIRS = {".git", ".github", ".devcontainer", "build", "tools", "bin", "node_modules", ".venv", "venv", "nonmatchings", "nonmatching"}

    for root_dir in search_dirs:
        if not root_dir.exists():
            continue

        for path in root_dir.rglob("*"):
            if any(part in SKIP_DIRS for part in path.parts):
                continue

            if path.is_file() and path.suffix.lower() in scraper.extensions:
                # Determine repo name
                if root_dir == extern_dir and path.is_relative_to(extern_dir):
                    rel = path.relative_to(extern_dir)
                    repo_name = rel.parts[0] if len(rel.parts) > 1 else "extern"
                else:
                    repo_name = "pictochat-decomp (local)"

                scanned_repos.add(repo_name)
                scanned_files += 1
                if scanned_files % 500 == 0:
                    print(f"Scanned {scanned_files} files ({len(all_records)} records extracted so far)...", flush=True)

                records = scraper.extract_patterns_from_file(path, repo_name)
                all_records.extend(records)

    index_data = {
        "scanned_files": scanned_files,
        "scanned_repos": sorted(list(scanned_repos)),
        "total_records": len(all_records),
        "records": all_records
    }

    index_path.parent.mkdir(parents=True, exist_ok=True)
    index_path.write_text(json.dumps(index_data, indent=2), encoding="utf-8")
    print(f"Pattern index built successfully! Scanned {scanned_files} files across {len(scanned_repos)} repos. Extracted {len(all_records)} records -> {index_path}")


def run_search(index_path: pathlib.Path, name: Optional[str], asm: Optional[str], category: Optional[str], repo: Optional[str]):
    """Search pattern database by symbol name, assembly query, or category."""
    if not index_path.exists():
        print(f"Index file {index_path} not found. Run 'python tools/cross_reference.py scrape' first.")
        sys.exit(1)

    index_data = json.loads(index_path.read_text(encoding="utf-8"))
    records = index_data.get("records", [])

    results = []
    for r in records:
        if repo and repo.lower() not in r.get("repo", "").lower():
            continue

        if name and name.lower() in r.get("name", "").lower():
            results.append(r)
            continue

        if category and category.lower() in r.get("category", "").lower():
            results.append(r)
            continue

        if asm:
            match_str = r.get("snippet", "") + " " + r.get("sample", "") + " " + r.get("match", "")
            if asm.lower() in match_str.lower():
                results.append(r)
                continue

    print(f"Found {len(results)} matching records:")
    print("=" * 80)
    for r in results[:50]:  # Limit output
        rtype = r.get("type")
        rname = r.get("name") or r.get("category") or r.get("hash", "N/A")
        rrepo = r.get("repo", "unknown")
        rfile = r.get("file", "unknown")
        rline = r.get("line", 0)
        # Prefer the actual regex match text (precise) over the wider context window,
        # whose "first line" is often blank or unrelated to what actually matched -
        # collapse whichever we show onto one line so it's a useful single-line preview.
        preview = r.get("match") or r.get("snippet") or r.get("sample") or ""
        preview = " ".join(preview.split())

        print(f"[{rrepo}] {rtype} '{rname}' in {rfile}:{rline}")
        if preview:
            print(f"   Snippet: {preview[:160]}")
    if len(results) > 50:
        print(f"... and {len(results) - 50} more results.")


def run_cross_match(index_path: pathlib.Path, funcs_file: pathlib.Path):
    """Cross-match local unverified functions against the extern pattern library."""
    if not index_path.exists():
        print(f"Index file {index_path} not found. Run 'python tools/cross_reference.py scrape' first.")
        sys.exit(1)

    index_data = json.loads(index_path.read_text(encoding="utf-8"))
    extern_records = index_data.get("records", [])

    # Map symbol names specifically from EXTERNAL repos
    extern_symbols = {}
    extern_categories = {}
    extern_repo_count = set()

    for r in extern_records:
        repo = r.get("repo", "")
        if repo and repo != "pictochat-decomp (local)":
            extern_repo_count.add(repo)
            if "name" in r:
                extern_symbols[r["name"]] = r
            if "category" in r:
                cat = r["category"]
                if cat not in extern_categories:
                    extern_categories[cat] = []
                extern_categories[cat].append(r)

    print(f"Loaded pattern database with {len(extern_symbols)} external symbols across {len(extern_repo_count)} repos ({', '.join(sorted(extern_repo_count))})")

    # Display external SDK & MSL matched symbols
    sdk_matches = [r for r in extern_symbols.values() if r.get("is_sdk") or r.get("is_msl")]
    print(f"Indexed External SDK/MSL Symbols Available for Reference: {len(sdk_matches)}")

    if funcs_file.exists():
        our_funcs = json.loads(funcs_file.read_text(encoding="utf-8"))
        print(f"Loaded {len(our_funcs)} local functions from {funcs_file.name}")

        matches = []
        for f in our_funcs:
            fname = f.get("name", "")
            if fname in extern_symbols:
                ext_info = extern_symbols[fname]
                matches.append((fname, f, ext_info))

        print(f"\nExternal Symbol Matches Found: {len(matches)}")
        print("=" * 80)
        for fname, our_f, ext_info in matches[:30]:
            print(f"Match: {fname}")
            print(f"  Local Address: 0x{our_f.get('addr', 0):X} | Size: {our_f.get('size', 0)} bytes")
            print(f"  Extern Repo: [{ext_info['repo']}] {ext_info['file']}:{ext_info.get('line', 0)}")
            print("-" * 50)

    else:
        print(f"Note: Local functions cache {funcs_file} not found. Generating matches from local drafts/asm instead.")

    # Show category distribution across external reference projects
    print("\nExternal Reference Assembly Idioms & Hardware Patterns Available:")
    print("=" * 80)
    for cat, items in extern_categories.items():
        print(f"  Category '{cat}': {len(items)} reference implementations across {len(set(x['repo'] for x in items))} repos")


def run_notes(extern_dir: pathlib.Path, query: str, context: int):
    """Full-text search across every markdown/doc file in extern/ repos.

    This is the highest-signal search available: several extern decomp projects
    (sm64ds-decomp most notably) keep a hand-written catalogue of mwccarm codegen
    quirks and the specific C phrasing that reproduces each one - a human already
    did the "why does this weird instruction sequence appear" work and wrote it
    down. This searches that prose directly instead of re-deriving it from raw
    source/asm.
    """
    if not extern_dir.exists():
        print(f"{extern_dir} does not exist.")
        return

    doc_exts = {".md", ".txt", ".rst"}
    skip_dirs = {".git", "node_modules", "build"}
    q = query.lower()
    hits = 0

    for path in sorted(extern_dir.rglob("*")):
        if any(part in skip_dirs for part in path.parts):
            continue
        if not (path.is_file() and path.suffix.lower() in doc_exts):
            continue
        try:
            text = path.read_text(encoding="utf-8", errors="ignore")
        except Exception:
            continue

        lines = text.splitlines()
        for i, line in enumerate(lines):
            if q in line.lower():
                hits += 1
                rel = path.relative_to(extern_dir)
                repo = rel.parts[0] if len(rel.parts) > 1 else "extern"
                lo = max(0, i - context)
                hi = min(len(lines), i + context + 1)
                print(f"\n[{repo}] {rel}:{i + 1}")
                for j in range(lo, hi):
                    marker = ">>" if j == i else "  "
                    print(f"   {marker} {lines[j]}")

    print(f"\n{'=' * 80}\n{hits} matching line(s) for '{query}' across markdown/doc files in {extern_dir}")
    if hits == 0:
        print("(Run 'python tools/manage_extern.py clone all' first if repos aren't checked out yet.)")


def run_info(index_path: pathlib.Path):
    """Print information and statistics about the pattern index."""
    if not index_path.exists():
        print(f"Index file {index_path} not found. Run 'python tools/cross_reference.py scrape' first.")
        return

    index_data = json.loads(index_path.read_text(encoding="utf-8"))
    print("NDS Decompilation Pattern Index Information:")
    print("=" * 60)
    print(f"Total Scanned Repos: {len(index_data.get('scanned_repos', []))}")
    for repo in index_data.get("scanned_repos", []):
        print(f"  - {repo}")
    print(f"Total Scanned Files: {index_data.get('scanned_files', 0)}")
    print(f"Total Extracted Records: {index_data.get('total_records', 0)}")


def main():
    parser = argparse.ArgumentParser(description="NDS Decomp Pattern Scraper & Cross-Referencing Tool")
    subparsers = parser.add_subparsers(dest="subcommand")

    # scrape
    p_scrape = subparsers.add_parser("scrape", help="Scrape extern repos and build pattern index")
    p_scrape.add_argument("--config", type=pathlib.Path, default=DEFAULT_CONFIG_PATH, help="Config path")
    p_scrape.add_argument("--output", type=pathlib.Path, default=DEFAULT_INDEX_PATH, help="Output index path")

    # search
    p_search = subparsers.add_parser("search", help="Search pattern index")
    p_search.add_argument("--name", type=str, help="Search by symbol/function name")
    p_search.add_argument("--asm", type=str, help="Search by assembly snippet/opcode pattern")
    p_search.add_argument("--category", type=str, help="Search by assembly category (cp15, hardware_io, etc.)")
    p_search.add_argument("--repo", type=str, help="Filter by repo name")
    p_search.add_argument("--index", type=pathlib.Path, default=DEFAULT_INDEX_PATH, help="Index path")

    # cross-match
    p_match = subparsers.add_parser("cross-match", help="Cross-match local functions against extern library")
    p_match.add_argument("--funcs-file", type=pathlib.Path, default=OUR_FUNCS_CACHE, help="Path to local funcs JSON")
    p_match.add_argument("--index", type=pathlib.Path, default=DEFAULT_INDEX_PATH, help="Index path")

    # info
    p_info = subparsers.add_parser("info", help="Display pattern index stats")
    p_info.add_argument("--index", type=pathlib.Path, default=DEFAULT_INDEX_PATH, help="Index path")

    # notes
    p_notes = subparsers.add_parser(
        "notes",
        help="Full-text search extern repos' own markdown/codegen-lever docs (highest-signal: "
             "other decomp projects' hand-written notes on exactly this toolchain's quirks)",
    )
    p_notes.add_argument("query", help="Substring to search for (case-insensitive)")
    p_notes.add_argument("--extern-dir", type=pathlib.Path, default=REPO_ROOT / "extern", help="extern/ dir")
    p_notes.add_argument("--context", type=int, default=2, help="Lines of context around each hit")

    args = parser.parse_args()

    if args.subcommand == "scrape":
        run_scrape(args.config, args.output)
    elif args.subcommand == "search":
        run_search(args.index, args.name, args.asm, args.category, args.repo)
    elif args.subcommand == "cross-match":
        run_cross_match(args.index, args.funcs_file)
    elif args.subcommand == "info":
        run_info(args.index)
    elif args.subcommand == "notes":
        run_notes(args.extern_dir, args.query, args.context)
    else:
        parser.print_help()


if __name__ == "__main__":
    main()
