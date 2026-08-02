#!/usr/bin/env python3
"""Sweep a pile of near-miss drafts through decomp-permuter, no manual setup
per function.

A near-miss is a draft that COMPILES but doesn't byte-match: often the logic
is already right and only register coloring / instruction ordering is off -
exactly what the permuter finishes for free. Feed it a JSONL of
{"name"|"module"+"addr", "c_source"} (from tools/m2c_draft.py output you've
hand-fixed into real C, a near-miss you found by hand, or any other source),
and this imports each one (tools/permuter/import_func.py), runs the permuter
under a time budget, and on a score-0 result independently re-verifies with
tools/match.py's own oracle before banking (tools/ledger.py) - nothing here
is trusted on the permuter's say-so.

Trimmed from sm64ds-decomp's tools/permuter/batch.py: this project doesn't
have their swarm.py template-rule pile (see tools/templates.py's much
smaller leaf-only set), so there's no `--module/--max` auto-find-regperm-
functions mode here - --seeds is the only source, which is also the one
their own docs call "the real fuel" anyway.

Usage:
    python tools/permuter/batch.py --seeds nearmiss.jsonl --secs 120
    python tools/permuter/batch.py --seeds nearmiss.jsonl --dry-run   # list the pile
"""
import argparse
import json
import pathlib
import subprocess
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(REPO / "tools"))
sys.path.insert(0, str(REPO / "tools" / "permuter"))
import funcs as F         # noqa: E402
import ledger as L        # noqa: E402
import match as M         # noqa: E402
import templates as T      # noqa: E402
import import_func as IMP  # noqa: E402
import winproc              # noqa: E402


def load_seeds(path):
    """[(ghidra_func_entry, c_source), ...] from a near-miss JSONL."""
    pile = []
    for line in pathlib.Path(path).read_text(encoding="utf-8").splitlines():
        line = line.strip()
        if not line:
            continue
        d = json.loads(line)
        addr = int(d["addr"], 0) if isinstance(d.get("addr"), str) else d.get("addr")
        f = IMP.find_func(d.get("module"), addr, d.get("name"))
        if not f:
            print(f"  (skip) function not found: {d.get('name') or hex(addr or 0)}")
            continue
        pile.append((f, d["c_source"]))
    return pile


def run_permuter(out, secs):
    """Run the permuter under a time budget; return the score-0 source.c text,
    or None. Output goes to <dir>/permuter.log (not discarded) so a compile
    error or scorer crash is diagnosable instead of looking like "no crack".

    Uses winproc.run_bounded() instead of a plain subprocess.run(timeout=)
    call: the permuter's `-j 4` spawns multiprocessing workers, each of
    which spawns its own cap_objdump.py/mwccarm.exe subprocess. On Windows,
    subprocess's own timeout-kill only terminates the direct child - none of
    that grandchild tree - so a plain timeout here silently leaves a pile of
    python.exe/mwccarm.exe processes running forever after this function
    returns. winproc wraps the launch in a Job Object so terminating it
    always takes the whole tree with it, whether it finished, timed out, or
    raised."""
    log = out / "permuter.log"
    try:
        with open(log, "w") as lf:
            winproc.run_bounded(
                [sys.executable, str(IMP.PERM_DIR / "permuter.py"), str(out),
                 "--stop-on-zero", "-j", "4"],
                secs=secs, cwd=str(IMP.PERM_DIR),
                stdout=lf, stderr=subprocess.STDOUT,
            )
    except Exception as e:
        print(f"  (permuter run error: {e}; see {log})")
        return None
    for od in sorted(out.glob("output-0-*")):
        src = od / "source.c"
        if src.exists():
            return src.read_text()
    try:
        tail = [ln for ln in log.read_text(errors="ignore").splitlines()
                if "base score" in ln or "error" in ln.lower() or "Traceback" in ln]
        if tail:
            print("  (permuter:", "; ".join(tail[-2:]).strip(), ")")
    except Exception:
        pass
    return None


def oracle_ok(src, name, module, mode, tgt, addr):
    import tempfile
    flags = T.flags_for(module, mode)
    with tempfile.TemporaryDirectory() as td:
        cf = pathlib.Path(td) / ("cand.cpp" if src.startswith("//cpp") else "cand.c")
        if src.startswith("//cpp"):
            flags = flags.replace("-lang c99", "-lang c++")
        cf.write_text(src)
        obj = M.compile_c(cf, M.CANONICAL, flags)
    if obj is None:
        return False
    code, relocs, reloc_info = M.extract_func(obj, name)
    if code is None:
        return False
    ok, _ = M.compare(tgt, code, relocs, verbose=False)
    if not ok:
        return False
    # compare() wildcards every reloc word - independently check any
    # address-named callee/global actually targets what its name claims
    # (see match.py's verify_relocs() docstring).
    bad = [r for r in M.verify_relocs(addr, tgt, reloc_info, mode == "thumb") if r[4] is False]
    return not bad


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--seeds", required=True, help="JSONL of near-misses to permute")
    ap.add_argument("--limit", type=int, default=20, help="max functions to permute")
    ap.add_argument("--secs", type=int, default=120, help="permuter budget per function")
    ap.add_argument("--dry-run", action="store_true", help="just list the pile")
    args = ap.parse_args()

    print(f"loading near-miss seeds from {args.seeds}...")
    pile = load_seeds(args.seeds)
    done = L.load_done()
    pile = [(f, src) for f, src in pile if (f["module"], f["addr"]) not in done]
    print(f"found {len(pile)} candidate function(s) not already matched/parked")
    for f, _ in pile[:args.limit]:
        print(f"  {f['module']:16} {f['name']:30} @ 0x{f['addr']:08x} (0x{f['size']:x}, {f['mode']})")
    if args.dry_run:
        return

    banked = 0
    for f, seed in pile[:args.limit]:
        print(f"\n=== permuting {f['module']} {f['name']} @ 0x{f['addr']:08x} "
             f"(budget {args.secs}s) ===")
        tgt = F.target_bytes(f)
        out, name, addr, size, nrel = IMP.setup_dir(f, seed)
        src = run_permuter(out, args.secs)
        if not src:
            print("  no score-0 found in budget")
            continue
        if oracle_ok(src, name, f["module"], f["mode"], tgt, addr):
            st = L.bank({"addr": addr, "name": name, "size": size,
                        "module": f["module"], "versions": ["permuter"]}, src)
            banked += st == "banked"
            print(f"  CRACKED + oracle-verified -> {st} {name}")
        else:
            print("  permuter reported 0 but the oracle disagreed (skipped) - "
                 "likely a reloc-wildcarding mismatch between the two; investigate by hand")
    print(f"\nbanked {banked}/{min(len(pile), args.limit)} via permuter")


if __name__ == "__main__":
    main()
