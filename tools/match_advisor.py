#!/usr/bin/env python3
"""Compile a draft, diff it against the ROM, and say what to CHANGE IN THE C.

tools/m2c_draft.py and tools/ghidra_draft.py produce reading aids, not matching
candidates; tools/fdiff.py shows you where two instruction streams differ. The
gap between those - "the diff says these four words differ, so what do I edit?"
- has been closed by hand every time, and the same handful of causes keep
recurring. This encodes them.

Each check below is a signature that was actually diagnosed by hand on this
ROM, with the function it came from cited in the hint, so a suggestion can be
checked against a worked precedent rather than taken on faith. It is an
ADVISOR: every hint is a hypothesis to test with tools/match.py, not a fact.

    python tools/match_advisor.py --c scratch/draft.c
    python tools/match_advisor.py --c draft.c --version 2.0/sp2   # override pin

Coordinates come from the file's own `// decomp:` marker and the function
table, so the size is funcs.true_size() (pool-inclusive) rather than Ghidra's
truncated boundary - which is itself one of the recurring causes.
"""
import argparse
import collections
import difflib
import pathlib
import re
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import match as M      # noqa: E402
import funcs as F      # noqa: E402
import templates as T  # noqa: E402
import ledger as L     # noqa: E402
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB  # noqa: E402

REG = re.compile(r"\b(r\d+|sb|sl|fp|ip|lr|sp)\b")
SP_OFF = re.compile(r"\[sp,\s*#(0x[0-9a-fA-F]+|\d+)\]")


BRANCH = ("bl", "blx")


def norm(i):
    """Instruction with register names, sp-offsets and branch targets abstracted
    away, so an alignment ignores pure colour/slot/relocation churn and lines up
    real structure.

    Order matters: the sp-offset pattern must be applied BEFORE registers are
    renamed, or REG rewrites the `sp` inside `[sp,#N]` first and the offset is
    never recognised. Branch targets are blanked because a freshly compiled
    object leaves call sites unrelocated (offset 0) while the ROM has real
    displacements - a difference that means nothing, and which match.py
    wildcards for exactly that reason."""
    if i.mnemonic in BRANCH:
        return i.mnemonic + " T"
    ops = SP_OFF.sub("[sp,#S]", i.op_str)
    return i.mnemonic + " " + REG.sub("R", ops)


def disasm(code, mode):
    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB if mode == "thumb" else CS_MODE_ARM)
    return list(md.disasm(code, 0))


RET = ("bx", "pop", "ldm", "ldmia")


def trim_pool(ins):
    """Drop the trailing literal pool. capstone happily decodes pool WORDS as
    instructions, and they then read as bogus differences (the target's pool
    holds real addresses; a fresh object leaves them as reloc placeholders).
    Cut after the last return-ish instruction."""
    last = max((k for k, i in enumerate(ins)
                if i.mnemonic in RET or (i.mnemonic.startswith("pop"))), default=len(ins) - 1)
    return ins[:last + 1]


def advise(tgt_ins, cand_ins, tgt, cand, relocs, f, matched_versions):
    hints = []
    tgt_ins, cand_ins = trim_pool(tgt_ins), trim_pool(cand_ins)
    tn = [norm(i) for i in tgt_ins]
    cn = [norm(i) for i in cand_ins]
    sm = difflib.SequenceMatcher(a=tn, b=cn, autojunk=False)
    ops = sm.get_opcodes()
    diffs = [o for o in ops if o[0] != "equal"]

    # --- whole-file shape -------------------------------------------------
    if len(cand) != len(tgt):
        d = len(cand) - len(tgt)
        hints.append(("SIZE", f"candidate is {abs(d)} byte(s) {'longer' if d>0 else 'shorter'} "
                      f"than the target ({len(cand):#x} vs {len(tgt):#x}). If every "
                      "instruction already lines up, suspect the SIZE, not the C: "
                      "funcs.true_size() extends past Ghidra's boundary to cover the "
                      "function's own literal pool (FUN_022d5a64 lost several sessions "
                      "to this)."))

    # --- everything left is register colour and/or stack-slot numbering ----
    # norm() deliberately abstracts BOTH away so the alignment tracks real
    # structure, which means these never show up as non-equal blocks. Walk the
    # aligned-equal regions and compare the RAW text to find them.
    slot_diffs = reg_diffs = 0
    for tag, i1, i2, j1, j2 in ops:
        if tag != "equal":
            continue
        for a, b in zip(tgt_ins[i1:i2], cand_ins[j1:j2]):
            if a.op_str == b.op_str:
                continue
            ta, tb = SP_OFF.search(a.op_str), SP_OFF.search(b.op_str)
            if ta and tb and ta.group(1) != tb.group(1):
                slot_diffs += 1
            else:
                reg_diffs += 1
    if slot_diffs:
        hints.append(("SLOTS", f"{slot_diffs} "
                      f"difference(s) are stack-SLOT numbers (same instruction, different "
                      f"[sp,#N])" + (f", {reg_diffs} are register colour" if reg_diffs else "")
                      + (" - and the instruction stream is otherwise EXACT" if not diffs else "")
                      + ". Declaration order drives slot assignment: run "
                      "tools/declorder_search.py. Note fdiff collapses register renames "
                      "but NOT slot renumbering, so one wrong order inflates the count "
                      "across the whole function (FUN_022d5540)."))
    elif reg_diffs:
        hints.append(("COLOR", f"the instruction stream is exact; {reg_diffs} difference(s) "
                      "are pure register colour. Declaration order sets callee-saved "
                      "assignment - swap the declarations of the two competing locals, one "
                      "pair at a time (that closed FUN_022d5a64's last mile)."))

    # --- an instruction that merely MOVED --------------------------------
    inserted = [cn[j] for tag, _, _, j1, j2 in diffs if tag == "insert" for j in range(j1, j2)]
    deleted = [tn[i] for tag, i1, i2, _, _ in diffs if tag == "delete" for i in range(i1, i2)]
    moved = collections.Counter(inserted) & collections.Counter(deleted)
    if moved:
        what = ", ".join(sorted(moved))
        hints.append(("SCHEDULE", f"{sum(moved.values())} instruction(s) are present in BOTH "
                      f"streams but at different positions ({what}) - a scheduling difference, "
                      "not a missing or extra operation. Move the corresponding STATEMENT in "
                      "the C rather than changing what it computes; statement order and "
                      "recompute-vs-reuse both shift it (FUN_022d5540's tailStruct recompute)."))

    # --- truncation pair present in target, absent in candidate ------------
    def has_trunc(ins):
        return any(a.mnemonic in ("lsl", "lsls") and "#0x10" in a.op_str
                   and b.mnemonic in ("lsr", "lsrs") and "#0x10" in b.op_str
                   for a, b in zip(ins, ins[1:]))
    if has_trunc(tgt_ins) and not has_trunc(cand_ins):
        hints.append(("WIDTH", "the target truncates a value explicitly (lsl #16 ; lsr #16) "
                      "where the candidate does not. A u16 local never needs that, so the "
                      "real source's variable is WIDER (int/unsigned) and narrows on "
                      "assignment into a u16. Widen the local that feeds those stores "
                      "(this was `cur` in FUN_022d5540)."))
    if has_trunc(cand_ins) and not has_trunc(tgt_ins):
        hints.append(("WIDTH", "the candidate truncates (lsl #16 ; lsr #16) where the target "
                      "does not - a narrowing the real source does not perform. Often a "
                      "`(unsigned short)` cast on a value the ROM just stores with strh, or "
                      "a u32 parameter that should be u16 (FUN_022d5a64's `index`: as u32 "
                      "the narrowing got CSE-hoisted into its own spill slot)."))

    # --- compare-against-1 vs compare-against-0 ----------------------------
    t1 = sum(1 for i in tgt_ins if i.mnemonic == "cmp" and re.search(r",\s*#1$", i.op_str))
    c1 = sum(1 for i in cand_ins if i.mnemonic == "cmp" and re.search(r",\s*#1$", i.op_str))
    if t1 > c1:
        hints.append(("CMP1", f"target has {t1} `cmp rX,#1` where the candidate has {c1}. "
                      "mwcc emits that for an explicit `== 1`, and `cmp rX,#0` for a bare "
                      "truthiness test - so write `if (flag == 1)`, not `if (flag)` "
                      "(FUN_022d5a64's first-iteration flag)."))

    # --- predicated select with swapped arms -------------------------------
    def sel_pairs(ins):
        return [(a.op_str, b.op_str) for a, b in zip(ins, ins[1:])
                if a.mnemonic in ("moveq", "movne") and b.mnemonic in ("moveq", "movne")
                and a.mnemonic != b.mnemonic]
    ts, cs = sel_pairs(tgt_ins), sel_pairs(cand_ins)
    if ts and cs and len(ts) == len(cs) and any(t != c for t, c in zip(ts, cs)):
        hints.append(("TERNARY", "a predicated select (moveq/movne pair) has its arms in the "
                      "other order. Flip the ternary's operands AND its test together - "
                      "`flag == 0 ? a : b` instead of `flag != 0 ? b : a`. Same construct "
                      "appears in FUN_022d5540/5870/5a64 and needed this in each."))

    # --- masking style ------------------------------------------------------
    if any(i.mnemonic == "ands" for i in cand_ins) and not any(i.mnemonic == "ands" for i in tgt_ins) \
            and any(i.mnemonic in ("lsrs", "lsls") for i in tgt_ins):
        hints.append(("MASK", "candidate emits `ands` where the target uses a shift pair with "
                      "flags (`lsl`/`lsrs`). The ROM tests the SHIFTED value, not the masked "
                      "one - test the result variable (`if (chunkLen == 0)`) rather than the "
                      "mask expression (`if ((hdr & 0xff) == 0)`)."))

    # --- relocations --------------------------------------------------------
    syms = [r for r in relocs if r.get("sym")]
    lits = [i for i in cand_ins if i.mnemonic == "ldr" and "[pc" in i.op_str]
    if len(syms) > len([i for i in tgt_ins if i.mnemonic in ("bl", "blx")]) + 1:
        hints.append(("RELOC", f"the object emits {len(syms)} relocation(s): "
                      f"{', '.join(sorted({r['sym'] for r in syms}))}. Byte comparison "
                      "WILDCARDS reloc slots, so a spurious one still 'matches' while "
                      "linking to the wrong symbol. If the ROM loads a bare constant, write "
                      "it as a literal `(int *)0x...`, not as `&G_<addr>` (FUN_0232d250)."))

    # --- frame shape --------------------------------------------------------
    def frame(ins):
        push = next((i for i in ins[:3] if i.mnemonic == "push"), None)
        sub = next((i for i in ins[:4] if i.mnemonic == "sub" and "sp" in i.op_str), None)
        return (push.op_str if push else None), (sub.op_str if sub else None)
    tf, cf = frame(tgt_ins), frame(cand_ins)
    if tf != cf:
        hints.append(("FRAME", f"frame differs - target push={tf[0]} sub={tf[1]}; "
                      f"candidate push={cf[0]} sub={cf[1]}. Frame shape responds to the "
                      "OPT LEVEL and to per-function pragmas far more than to phrasing: "
                      "sweep -O4,s vs -O4,p, then `#pragma opt_common_subs off` and "
                      "`#pragma opt_loop_invariants off` (both are honoured; the CLI "
                      "-opt equivalents are inert at -O4)."))

    if matched_versions and M.CANONICAL not in matched_versions:
        hints.append(("VERSION", f"does not match the pinned {M.CANONICAL} but DOES match "
                      f"{', '.join(matched_versions)}. Investigate before banking - the pin "
                      "is evidence-backed (notes/setup-mwccarm.md)."))
    return hints


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--c", required=True)
    ap.add_argument("--version", default=None, help=f"default: {M.CANONICAL}")
    ap.add_argument("--sweep", action="store_true", help="also report which pinned builds match")
    a = ap.parse_args()

    cfile = pathlib.Path(a.c)
    src = cfile.read_text(encoding="utf-8", errors="ignore")
    m = L.MARKER_RE.search(src[:600])
    if not m:
        sys.exit("no `// decomp: module=... addr=0x... name=...` marker in the draft")
    module, addr, name = m.group(1), int(m.group(2), 16), m.group(3)
    f = next((x for x in F.load_funcs()
              if x.get("module") == module and x["addr"] == addr), None)
    if f is None:
        sys.exit(f"{name} @ {addr:#x} not in the function table")

    size = F.true_size(f)
    version = a.version or M.CANONICAL
    flags = M.apply_flags_marker(T.flags_for(module, f["mode"]), src, allow_thumb_heuristic=False)
    obj = M.compile_c(cfile, version, flags)
    if obj is None:
        sys.exit(f"{name}: did not compile under {version} (flags: {flags})")
    code, relocs, info = M.extract_func(obj, name)
    if code is None:
        sys.exit(f"{name}: compiled, but the object defines no such symbol")
    tgt = M.target_bytes(module, addr, size)

    ok, ndiff = M.compare(tgt, code, relocs, verbose=False)
    print(f"{name}  {module}  {addr:#010x}  size {size:#x} "
          f"(Ghidra says {f['size']:#x})  {version}")
    if ok:
        print("\nMATCH - byte-identical. Nothing to advise.")
        return 0

    matched = []
    if a.sweep:
        for v in M.PINNED:
            o = M.compile_c(cfile, v, flags)
            if not o:
                continue
            c2, r2, _ = M.extract_func(o, name)
            if c2 is not None and len(c2) == len(tgt) and M.compare(tgt, c2, r2, verbose=False)[0]:
                matched.append(v)

    hints = advise(disasm(tgt, f["mode"]), disasm(code, f["mode"]),
                   tgt, code, info, f, matched)
    print(f"{ndiff} differing word(s), {len(code):#x} vs {len(tgt):#x} bytes\n")
    if not hints:
        print("No known signature fired. Fall back to reading the two linear")
        print("disassemblies side by side - that is what found every rule above:")
        print(f"  python tools/disasm.py --module {module} --addr {addr:#x} --length {size:#x}")
        print(f"  python tools/fdiff.py --c {a.c} --func {name} --addr {addr:#x} "
              f"--size {size:#x} --module {module} --version {version} --align")
        return 1
    for tag, text in hints:
        print(f"[{tag}] {text}\n")
    return 1


if __name__ == "__main__":
    sys.exit(main())
