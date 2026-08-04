#!/usr/bin/env python3
"""Sweep combinations of independent source edits against a target function.

Hand-testing one C phrasing at a time is the slow part of closing a near-miss:
each lever (a `volatile`, a cast, a statement order) is cheap to try alone, but
the ones that matter usually only pay off in COMBINATION - round 3j of
notes/mwccarm-codegen.md found FUN_022d5540's best candidate only by pairing two
pragmas that were each individually a regression. This runs the cartesian product
for you and ranks the results.

A sweep is a JSON spec:

    {
      "base":   "scratch/FUN_022d5a64_v49.c",
      "func":   "FUN_022d5a64",
      "addr":   "0x022d5a64",
      "size":   "0x1fc",
      "module": "arm7",
      "version": "dsi/1.3",
      "axes": [
        {"name": "first",
         "anchor": "    int first;",
         "options": {"plain":    "    int first;",
                     "volatile": "    volatile int first;"}},
        {"name": "ctx",
         "anchor": "void * volatile ctx",
         "options": {"vol":   "void * volatile ctx",
                     "plain": "void *ctx"}}
      ]
    }

Every axis replaces its `anchor` (which must appear EXACTLY ONCE in the base -
checked, so a typo fails loudly instead of silently testing the base N times, a
real bug that cost a whole round earlier in this project's history) with one of
its options. Results are ranked by (insn-count distance, block count, size
distance) and printed best-first; `--top N` limits the report.

    python tools/csweep.py sweep.json
    python tools/csweep.py sweep.json --top 5 --keep-dir scratch/_sweep

Metrics per candidate, all from the same oracles the rest of the toolchain uses
(tools/match.py to compile, tools/fdiff.py --align to score):
  insns   candidate's real instruction count vs the target's
  blocks  non-equal blocks after shape-alignment (register-coloring collapsed)
  size    candidate byte size vs the target's
  MATCH   byte-identical - stop, you are done
"""
import argparse
import itertools
import json
import pathlib
import re
import subprocess
import sys
import tempfile

REPO = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import match as M  # noqa: E402

HDR_RE = re.compile(
    r"target:\s*(\d+)\s*decoded insn\(s\)\s*\((0x[0-9a-f]+) bytes\);\s*"
    r"candidate:\s*(\d+)\s*decoded insn\(s\)\s*\((0x[0-9a-f]+) bytes\)")
BLOCK_RE = re.compile(r"(\d+)\s+non-equal block\(s\)")


def score(cfile, spec):
    """Compile+diff one candidate. Returns (matched, insns, blocks, size) or None."""
    r = subprocess.run(
        [sys.executable, str(REPO / "tools" / "fdiff.py"),
         "--c", str(cfile), "--func", spec["func"], "--addr", spec["addr"],
         "--size", spec["size"], "--module", spec["module"],
         "--version", spec["version"], "--align", "--align-max-blocks", "0"],
        capture_output=True, text=True, cwd=str(REPO))
    out = r.stdout + r.stderr
    if "RESULT match=True" in out:
        return (True, 0, 0, 0)
    m = HDR_RE.search(out)
    if not m:
        return None
    t_insn, _t_size, c_insn, c_size = m.group(1), m.group(2), m.group(3), m.group(4)
    b = BLOCK_RE.search(out)
    return (False, int(c_insn) - int(t_insn), int(b.group(1)) if b else 9999,
            int(c_size, 16) - int(spec["size"], 16))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("spec")
    ap.add_argument("--top", type=int, default=15)
    ap.add_argument("--keep-dir", default=None,
                    help="write every generated candidate here (default: temp, discarded)")
    a = ap.parse_args()

    spec = json.loads(pathlib.Path(a.spec).read_text())
    base = (REPO / spec["base"]).read_text()

    axes = spec["axes"]
    for ax in axes:
        n = base.count(ax["anchor"])
        if n != 1:
            sys.exit(f"axis {ax['name']!r}: anchor occurs {n} times in base, need exactly 1:\n"
                     f"  {ax['anchor']!r}")

    combos = list(itertools.product(*[list(ax["options"].items()) for ax in axes]))
    print(f"{len(combos)} combination(s) over {len(axes)} axis/axes")

    outdir = pathlib.Path(a.keep_dir) if a.keep_dir else pathlib.Path(tempfile.mkdtemp())
    outdir.mkdir(parents=True, exist_ok=True)

    rows = []
    for i, combo in enumerate(combos):
        text = base
        for ax, (_label, repl) in zip(axes, combo):
            text = text.replace(ax["anchor"], repl, 1)
        label = ",".join(f"{ax['name']}={lb}" for ax, (lb, _) in zip(axes, combo))
        cfile = outdir / f"cand_{i:04d}.c"
        cfile.write_text(text)
        s = score(cfile, spec)
        if s is None:
            print(f"  [{i+1}/{len(combos)}] {label}: COMPILE/DIFF FAILED")
            continue
        matched, dinsn, blocks, dsize = s
        if matched:
            print(f"\n*** MATCH *** {label}\n  {cfile}")
            return
        rows.append((abs(dinsn), blocks, abs(dsize), dinsn, dsize, label, str(cfile)))
        print(f"  [{i+1}/{len(combos)}] {label}: insn{dinsn:+d} blocks={blocks} size{dsize:+d}")

    rows.sort()
    print(f"\n=== top {min(a.top, len(rows))} ===")
    for adi, blocks, _ads, dinsn, dsize, label, path in rows[:a.top]:
        print(f"  insn{dinsn:+d} blocks={blocks:3d} size{dsize:+d}  {label}\n      {path}")


if __name__ == "__main__":
    main()
