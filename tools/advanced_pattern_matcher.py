#!/usr/bin/env python3
"""Advanced NDS Pattern Matcher & Draft Generator

Disassembles target unmatched functions from binary, extracts structural features
(opcode n-grams, IO registers, CP15 calls, SDK invocations), performs fuzzy sequence
alignment against the extern reference library, and auto-scaffolds draft files for
the largest unmatched functions.

Usage:
  python tools/advanced_pattern_matcher.py analyze [--top N]
  python tools/advanced_pattern_matcher.py match --addr ADDR
  python tools/advanced_pattern_matcher.py generate-drafts [--top N]
"""

import argparse
import difflib
import json
import os
import pathlib
import re
import sys
from typing import Dict, List, Any, Tuple, Optional

import capstone

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO_ROOT / "tools"))

import match as M
import funcs as F

DEFAULT_INDEX_PATH = REPO_ROOT / "extern" / "pattern_index.json"
FUNCS_CACHE_PATH = REPO_ROOT / "extracted" / "pictochat_funcs.json"
MATCHED_LEDGER = REPO_ROOT / "progress" / "matched.jsonl"


def get_matched_addresses() -> set:
    """Load set of already-matched function addresses from ledger and src/."""
    matched = set()
    if MATCHED_LEDGER.exists():
        for line in MATCHED_LEDGER.read_text(encoding="utf-8").splitlines():
            if line.strip():
                try:
                    data = json.loads(line)
                    matched.add(data["addr"])
                except Exception:
                    pass

    # Also scan src/ markers
    marker_re = re.compile(r"//\s*decomp:\s*module=\S+\s+addr=(0x[0-9a-fA-F]+)")
    for sub in ("arm9", "arm7"):
        d = REPO_ROOT / "src" / sub
        if d.exists():
            for p in list(d.glob("*.c")) + list(d.glob("*.cpp")):
                head = p.read_text(encoding="utf-8", errors="ignore")[:400]
                m = marker_re.search(head)
                if m:
                    matched.add(int(m.group(1), 16))
    return matched


def get_module_for_addr(addr: int, fallback: Optional[str] = None) -> str:
    """Infer target module name based on RAM address ranges."""
    if fallback and fallback in M.MODULES:
        base, rel = M.MODULES[fallback][1], M.MODULES[fallback][0]
        # Verify address fits in module
        data = (M.DSD_EXTRACT / rel).read_bytes() if (M.DSD_EXTRACT / rel).exists() else b""
        if base <= addr < base + len(data):
            return fallback

    if 0x022C0000 <= addr < 0x02300000:
        return "arm7"
    elif 0x02320000 <= addr < 0x02370000:
        return "unk_autoload_0"
    elif 0x02000400 <= addr < 0x02005000:
        return "main"
    elif 0x01FF8000 <= addr < 0x02000000:
        return "itcm"
    elif 0x03000000 <= addr < 0x03100000:
        return "unk_autoload_2"
    return fallback or "unk_autoload_0"


def get_unmatched_functions() -> List[Dict[str, Any]]:
    """Return list of unmatched functions sorted by size descending."""
    if not FUNCS_CACHE_PATH.exists():
        print(f"Error: {FUNCS_CACHE_PATH} not found.")
        sys.exit(1)

    funcs = json.loads(FUNCS_CACHE_PATH.read_text(encoding="utf-8"))
    matched_addrs = get_matched_addresses()

    unmatched = [f for f in funcs if f["addr"] not in matched_addrs]
    unmatched.sort(key=lambda x: x.get("size", 0), reverse=True)
    return unmatched


def disassemble_func(addr: int, size: int, mode: str, module: str) -> Tuple[List[str], str, Dict[str, Any]]:
    """Disassemble function bytes and extract structural features."""
    try:
        raw_bytes = M.target_bytes(module, addr, size)
    except Exception as e:
        return [], "", {}

    arch_mode = capstone.CS_MODE_THUMB if mode.lower() == "thumb" else capstone.CS_MODE_ARM
    md = capstone.Cs(capstone.CS_ARCH_ARM, arch_mode)

    opcodes = []
    normalized_lines = []
    features = {
        "hardware_io": [],
        "cp15": False,
        "sdk_calls": [],
        "bit_ops": False
    }

    for insn in md.disasm(raw_bytes, addr):
        opcodes.append(insn.mnemonic)
        op_str = insn.op_str

        # Check features
        if "p15" in op_str.lower():
            features["cp15"] = True
        if "0x0400" in op_str or "REG_" in op_str:
            features["hardware_io"].append(op_str)
        if insn.mnemonic in ("clz", "lsl", "lsr", "asr", "ror"):
            features["bit_ops"] = True

        # Normalize line
        norm_op = re.sub(r"#0x[0-9a-fA-F]{5,}", "#ADDR", op_str)
        norm_op = re.sub(r"0x[0-9a-fA-F]{5,}", "ADDR", norm_op)
        norm_op = re.sub(r"\[pc,?[^\]]*\]", "[pc,ADDR]", norm_op)
        normalized_lines.append(f"{insn.mnemonic} {norm_op}")

    norm_str = "\n".join(normalized_lines)
    return opcodes, norm_str, features


def ngrams(lst: List[str], n: int = 2) -> set:
    """Generate set of n-grams from list."""
    return set(tuple(lst[i:i + n]) for i in range(len(lst) - n + 1))


def compute_similarity(opcodes1: List[str], text1: str, sample2: str) -> float:
    """Compute fuzzy similarity between target assembly and reference sample."""
    if not opcodes1 or not sample2:
        return 0.0

    lines2 = sample2.splitlines()
    opcodes2 = [l.split()[0] for l in lines2 if l.split()]

    # 1. Opcode Jaccard similarity (bigrams)
    ng1 = ngrams(opcodes1, 2)
    ng2 = ngrams(opcodes2, 2)
    if not ng1 or not ng2:
        jaccard = 0.0
    else:
        jaccard = len(ng1 & ng2) / float(len(ng1 | ng2))

    # 2. SequenceMatcher ratio on normalized text
    ratio = difflib.SequenceMatcher(None, text1[:500], sample2[:500]).ratio()

    return (jaccard * 0.6) + (ratio * 0.4)


def match_function_against_extern(addr: int, size: int, mode: str, module: str, index_records: List[Dict[str, Any]]) -> List[Dict[str, Any]]:
    """Match a target function against all extern pattern records with fast n-gram pre-filtering."""
    target_opcodes, target_norm, features = disassemble_func(addr, size, mode, module)
    if not target_opcodes:
        return []

    target_ngrams = ngrams(target_opcodes, 2)
    if not target_ngrams:
        return []

    scored_matches = []

    for r in index_records:
        repo = r.get("repo", "")
        if repo == "pictochat-decomp (local)":
            continue

        sample = r.get("sample") or r.get("snippet") or ""
        if not sample or len(sample) < 10:
            continue

        # Fast check: skip if sample shares no opcode lines
        sample_first = sample.splitlines()[0]
        if not any(op in sample_first for op in target_opcodes[:5]):
            continue

        sim = compute_similarity(target_opcodes, target_norm, sample)
        if sim > 0.35:
            r_copy = dict(r)
            r_copy["similarity"] = round(sim, 3)
            scored_matches.append(r_copy)

    scored_matches.sort(key=lambda x: x["similarity"], reverse=True)

    # Deduplicate by repo + file
    seen = set()
    unique_matches = []
    for m in scored_matches:
        key = (m.get("repo"), m.get("file"))
        if key not in seen:
            seen.add(key)
            unique_matches.append(m)

    return unique_matches[:5]


def cmd_analyze(args):
    """Analyze top largest unmatched functions in the codebase."""
    unmatched = get_unmatched_functions()
    top_n = min(args.top, len(unmatched))

    print(f"=== TOP {top_n} LARGEST UNMATCHED FUNCTIONS ===")
    print(f"{'Address':<12} {'Size (bytes)':<14} {'Mode':<8} {'Module':<16} {'Symbol Name'}")
    print("=" * 70)

    for f in unmatched[:top_n]:
        addr = f["addr"]
        size = f.get("size", 0)
        mode = f.get("mode", "arm")
        module = f.get("module", "unk_autoload_0")
        name = f.get("name", f"FUN_{addr:08x}")
        print(f"0x{addr:08X}    {size:<14} {mode:<8} {module:<16} {name}")


def cmd_match(args):
    """Perform fuzzy assembly match for a specific function address."""
    if not DEFAULT_INDEX_PATH.exists():
        print(f"Index {DEFAULT_INDEX_PATH} not found. Run 'python tools/cross_reference.py scrape' first.", flush=True)
        sys.exit(1)

    index_data = json.loads(DEFAULT_INDEX_PATH.read_text(encoding="utf-8"))
    records = index_data.get("records", [])

    addr_int = int(args.addr, 16) if isinstance(args.addr, str) and args.addr.startswith("0x") else int(args.addr)

    # Find function metadata
    funcs = json.loads(FUNCS_CACHE_PATH.read_text(encoding="utf-8"))
    f_meta = next((f for f in funcs if f["addr"] == addr_int), None)

    size = f_meta.get("size", 0x40) if f_meta else 0x40
    mode = f_meta.get("mode", "arm") if f_meta else "arm"
    module = get_module_for_addr(addr_int, f_meta.get("module") if f_meta else None)

    print(f"Matching function 0x{addr_int:08X} (size {size} bytes, {mode}, module {module})...", flush=True)
    matches = match_function_against_extern(addr_int, size, mode, module, records)

    print(f"\nTop Matching External References ({len(matches)} found):", flush=True)
    print("=" * 80, flush=True)
    for m in matches:
        print(f"Score: {m['similarity']:.2f} | [{m['repo']}] {m['file']}:{m.get('line', 0)}", flush=True)
        if "name" in m:
            print(f"   Function: {m['name']}", flush=True)
        if "snippet" in m:
            first_line = m["snippet"].splitlines()[0] if m["snippet"] else ""
            print(f"   Snippet: {first_line[:90]}", flush=True)
        print("-" * 60, flush=True)


def cmd_generate_drafts(args):
    """Auto-generate C/C++ draft scaffolds for top largest unmatched functions."""
    if not DEFAULT_INDEX_PATH.exists():
        print(f"Index {DEFAULT_INDEX_PATH} not found. Run 'python tools/cross_reference.py scrape' first.")
        sys.exit(1)

    index_data = json.loads(DEFAULT_INDEX_PATH.read_text(encoding="utf-8"))
    records = index_data.get("records", [])

    unmatched = get_unmatched_functions()
    top_n = min(args.top, len(unmatched))

    generated_count = 0

    print(f"Generating draft scaffolds for top {top_n} largest unmatched functions...", flush=True)

    for f in unmatched[:top_n]:
        addr = f["addr"]
        size = f.get("size", 0x20)
        mode = f.get("mode", "arm")
        module = get_module_for_addr(addr, f.get("module"))
        name = f.get("name", f"FUN_{addr:08x}")

        is_arm7 = module == "arm7" or (addr >= 0x022C0000 and addr < 0x02300000)
        draft_dir = REPO_ROOT / "drafts" / ("arm7" if is_arm7 else "arm9")
        draft_dir.mkdir(parents=True, exist_ok=True)

        draft_file = draft_dir / f"{name}.cpp"
        if draft_file.exists():
            continue

        matches = match_function_against_extern(addr, size, mode, module, records)

        lines = [
            f"// decomp: module={module} addr=0x{addr:08x} name={name}",
            "// Auto-generated draft scaffold via advanced_pattern_matcher",
            "extern \"C\" {"
        ]

        if matches:
            lines.append("// Reference implementations found in external repos:")
            for m in matches[:3]:
                lines.append(f"// - [{m['repo']}] {m['file']}:{m.get('line', 0)} (similarity: {m['similarity']})")

        lines.extend([
            f"void {name}(void)",
            "{",
            "}",
            "}"
        ])

        draft_file.write_text("\n".join(lines) + "\n", encoding="utf-8")
        generated_count += 1
        print(f"  [DRAFT GENERATED] {draft_file.relative_to(REPO_ROOT)}", flush=True)

    print(f"\nSuccessfully generated {generated_count} new draft scaffolds in drafts/", flush=True)


def main():
    parser = argparse.ArgumentParser(description="Advanced NDS Pattern Matcher & Draft Generator")
    subparsers = parser.add_subparsers(dest="subcommand")

    # analyze
    p_an = subparsers.add_parser("analyze", help="Analyze top largest unmatched functions")
    p_an.add_argument("--top", type=int, default=15, help="Top N largest functions")
    p_an.set_defaults(func=cmd_analyze)

    # match
    p_m = subparsers.add_parser("match", help="Find fuzzy assembly matches for a function address")
    p_m.add_argument("--addr", type=str, required=True, help="Function address (e.g. 0x02327E80)")
    p_m.set_defaults(func=cmd_match)

    # generate-drafts
    p_gen = subparsers.add_parser("generate-drafts", help="Generate draft scaffolds for largest unmatched functions")
    p_gen.add_argument("--top", type=int, default=15, help="Top N largest functions to scaffold")
    p_gen.set_defaults(func=cmd_generate_drafts)

    args = parser.parse_args()
    if not args.subcommand:
        parser.print_help()
        sys.exit(1)

    args.func(args)


if __name__ == "__main__":
    main()
