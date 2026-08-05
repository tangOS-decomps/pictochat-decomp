"""Free template tier: auto-generate + self-verify candidate C for trivial
functions (empty stubs, constant/argument returns, field get/set, bitfields
and bit-test/bitop patterns, global getters/setters/swaps, small struct
copies, multi-field const initializers, ...) - no hand-writing or LLM needed.

Ported from sm64ds-decomp's tools/swarm.py: every leaf rule (the ones taking
just (name, ins, bytes), needing no relocs/symbol table) except the object-
construction ones under "reloc-aware rules" there that need callee-name
resolution via config/relocs.txt, which this project doesn't have (see
notes/pictochat-layout.md) - and the C++-ABI rules (vtable/ctor/dtor chains,
virtual/PMF calls), tuned to SM64DS's own class layouts.

Every candidate is compiled with mwccarm and byte-diffed against the ROM
before being reported or banked, exactly like a hand-written match - a rule
misfiring just means "no candidate", never a wrong one.

Mode-aware: this project's code is mostly Thumb (unlike sm64ds-decomp's
mostly-ARM), so each rule is tried against the target's OWN encoding (the
"mode" field in extracted/pictochat_funcs.json, from Ghidra), decoding with
the matching capstone mode and compiling with/without -thumb to match.

Usage:
    python tools/templates.py                          # dry-run, report candidates
    python tools/templates.py --apply                  # bank verified wins (tools/ledger.py)
    python tools/templates.py --module unk_autoload_0 --max 0x20
    python tools/templates.py --verbose                 # print each candidate's C
"""
import argparse
import pathlib
import re
import sys
import tempfile

from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB

REPO = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import match as M   # noqa: E402
import funcs as F    # noqa: E402
import ledger as L   # noqa: E402

MD = {"arm": Cs(CS_ARCH_ARM, CS_MODE_ARM), "thumb": Cs(CS_ARCH_ARM, CS_MODE_THUMB)}


def squash(op_str):
    return op_str.replace(" ", "")


def imm(op_str):
    m = re.search(r"#(-?0x[0-9a-fA-F]+|-?\d+)", op_str)
    return int(m.group(1), 0) if m else None


def cfunc(name, ret, params, body):
    return f"{ret} {name}({params})\n{{\n" + (f"    {body}\n" if body else "") + "}\n"


def is_ret(i):
    return i.mnemonic == "bx" and squash(i.op_str) == "lr"


def _mn(i):
    """Mnemonic with a Thumb flags-setting suffix stripped (movs->mov,
    adds->add, ...) so one rule covers both ARM- and Thumb-encoded shapes."""
    m = i.mnemonic
    base = m[:-1]
    return base if m.endswith("s") and base in (
        "mov", "add", "sub", "and", "orr", "eor", "mul", "mvn", "bic",
        "lsr", "lsl", "asr", "ror") else m


LOADS = {
    "ldr": ("int", 4), "ldrb": ("unsigned char", 1), "ldrsb": ("signed char", 1),
    "ldrh": ("unsigned short", 2), "ldrsh": ("short", 2),
}
# unsigned load types -- needed so `>>` emits a logical shift (lsr), not
# arithmetic (asr), matching how a real bitfield-extraction reads.
UWORD = {"ldr": ("unsigned int", 4), "ldrb": ("unsigned char", 1), "ldrh": ("unsigned short", 2)}
STORES = {"str": ("int", 4), "strb": ("char", 1), "strh": ("short", 2)}
ARITH = {"add": "+", "sub": "-", "orr": "|", "and": "&", "eor": "^", "mul": "*"}

IMM = r"#(-?0x[0-9a-fA-F]+|-?\d+)"
PCLD_RE = re.compile(r"(r\d+),\[pc.*\]")
MEM_RE = re.compile(r"^r0,\[r0(?:,#(-?0x[0-9a-fA-F]+|-?\d+))?\]$")
ST_RE = re.compile(r"^r1,\[r0(?:,#(-?0x[0-9a-fA-F]+|-?\d+))?\]$")
GG_RE = re.compile(r"^r0,\[r0(?:,#(0x[0-9a-fA-F]+|\d+))?\]$")


# --------------------------------------------------------------------- rules
# Each rule: (name, insns, raw_bytes) -> (c_source, rule_label) or None.
def rule_empty(name, ins, b):
    if len(ins) == 1 and is_ret(ins[0]):
        return cfunc(name, "void", "void", ""), "empty"
    return None


def rule_ret_const(name, ins, b):
    if len(ins) == 2 and is_ret(ins[1]):
        i, s, mn = ins[0], squash(ins[0].op_str), _mn(ins[0])
        if mn == "mov" and s.startswith("r0,#"):
            n = imm(s)
            if n is not None:
                return cfunc(name, "int", "void", f"return {n};"), "ret_const"
        if mn == "mvn" and s.startswith("r0,#"):
            n = imm(s)
            if n is not None:
                return cfunc(name, "int", "void", f"return {~n};"), "ret_const_mvn"
    return None


def rule_ret_arg(name, ins, b):
    if len(ins) == 2 and is_ret(ins[1]) and _mn(ins[0]) == "mov":
        m = re.fullmatch(r"r0,r([1-3])", squash(ins[0].op_str))
        if m:
            n = int(m.group(1))
            params = ", ".join(f"int a{k}" for k in range(n + 1))
            return cfunc(name, "int", params, f"return a{n};"), "ret_arg"
    return None


def rule_load(name, ins, b):
    if len(ins) == 2 and is_ret(ins[1]) and ins[0].mnemonic in LOADS:
        m = MEM_RE.match(squash(ins[0].op_str))
        if m:
            ptype, esize = LOADS[ins[0].mnemonic]
            off = int(m.group(1), 0) if m.group(1) else 0
            if off % esize == 0:
                return cfunc(name, "int", f"{ptype} *p", f"return p[{off // esize}];"), "load_field"
    return None


def rule_store(name, ins, b):
    if len(ins) == 2 and is_ret(ins[1]) and ins[0].mnemonic in STORES:
        m = ST_RE.match(squash(ins[0].op_str))
        if m:
            ptype, esize = STORES[ins[0].mnemonic]
            off = int(m.group(1), 0) if m.group(1) else 0
            if off % esize == 0:
                return cfunc(name, "void", f"{ptype} *p, int v",
                              f"p[{off // esize}] = v;"), "store_field"
    return None


def rule_arith(name, ins, b):
    if len(ins) == 2 and is_ret(ins[1]) and _mn(ins[0]) in ARITH:
        if re.fullmatch(r"r0,r0,r1", squash(ins[0].op_str)):
            return cfunc(name, "int", "int a, int b",
                          f"return a {ARITH[_mn(ins[0])]} b;"), "arith2"
    return None


def rule_global_getter(name, ins, b):
    # ldr r0,[pc,#x] ; <load> r0,[r0,#off] ; bx lr ; .word G -> a global field.
    # The .word is G's absolute address: a relocation the oracle wildcards.
    if (len(ins) >= 3 and ins[0].mnemonic == "ldr"
            and squash(ins[0].op_str).startswith("r0,[pc")
            and ins[1].mnemonic in LOADS and is_ret(ins[2])):
        m = GG_RE.match(squash(ins[1].op_str))
        if m:
            ptype, esize = LOADS[ins[1].mnemonic]
            off = int(m.group(1), 0) if m.group(1) else 0
            if off % esize == 0:
                src = (f"extern {ptype} G[];\n"
                       f"int {name}(void)\n{{\n    return G[{off // esize}];\n}}\n")
                return src, "global_getter"
    return None


def rule_load_mask(name, ins, b):
    # <load> r0,[r0(,#off)] ; and r0,r0,#imm ; bx lr -> return field & imm
    if (len(ins) == 3 and ins[0].mnemonic in LOADS and _mn(ins[1]) == "and"
            and is_ret(ins[2])):
        m = MEM_RE.match(squash(ins[0].op_str))
        a = re.fullmatch(r"r0,r0," + IMM, squash(ins[1].op_str))
        if m and a:
            ptype, esize = LOADS[ins[0].mnemonic]
            off = int(m.group(1), 0) if m.group(1) else 0
            if off % esize == 0:
                return cfunc(name, "int", f"{ptype} *p",
                              f"return p[{off // esize}] & {int(a.group(1), 0)};"), "load_mask"
    return None


def rule_bitfield(name, ins, b):
    # <load> r0,[r0(,#off)] ; lsr r0,r0,#sh ; and r0,r0,#mask ; bx lr
    if (len(ins) == 4 and ins[0].mnemonic in UWORD and _mn(ins[1]) == "lsr"
            and _mn(ins[2]) == "and" and is_ret(ins[3])):
        m = MEM_RE.match(squash(ins[0].op_str))
        sh = re.fullmatch(r"r0,r0," + IMM, squash(ins[1].op_str))
        mk = re.fullmatch(r"r0,r0," + IMM, squash(ins[2].op_str))
        if m and sh and mk:
            ptype, esize = UWORD[ins[0].mnemonic]
            off = int(m.group(1), 0) if m.group(1) else 0
            if off % esize == 0:
                return cfunc(name, "int", f"{ptype} *p",
                              f"return (p[{off // esize}] >> {int(sh.group(1), 0)}) & "
                              f"{int(mk.group(1), 0)};"), "bitfield"
    return None


def rule_store_const(name, ins, b):
    # mov rX,#imm ; <store> rX,[rBase(,#off)] ; bx lr -> base r0..r3 = the (n+1)th pointer arg
    if len(ins) == 3 and _mn(ins[0]) == "mov" and ins[1].mnemonic in STORES and is_ret(ins[2]):
        mv = re.fullmatch(r"(r\d+)," + IMM, squash(ins[0].op_str))
        if mv:
            st = re.fullmatch(mv.group(1) + r",\[(r[0-3])(?:," + IMM + r")?\]", squash(ins[1].op_str))
            if st:
                ptype, esize = STORES[ins[1].mnemonic]
                off = int(st.group(2), 0) if st.group(2) else 0
                argn = int(st.group(1)[1])
                if off % esize == 0:
                    params = [f"int a{i}" for i in range(argn)] + [f"{ptype} *p"]
                    return cfunc(name, "void", ", ".join(params),
                                  f"p[{off // esize}] = {int(mv.group(2), 0)};"), "store_const"
    return None


def rule_store_const_ret(name, ins, b):
    # mov rV,#k ; <store> rV,[r0(,#off)] ; mov r0,#ret ; bx lr -> p[idx] = k; return ret;
    if (len(ins) == 4 and _mn(ins[0]) == "mov" and ins[1].mnemonic in STORES
            and _mn(ins[2]) == "mov" and is_ret(ins[3])):
        mv = re.fullmatch(r"(r\d+)," + IMM, squash(ins[0].op_str))
        rt = re.fullmatch(r"r0," + IMM, squash(ins[2].op_str))
        if mv and rt:
            st = re.fullmatch(mv.group(1) + r",\[r0(?:," + IMM + r")?\]", squash(ins[1].op_str))
            if st:
                ptype, esize = STORES[ins[1].mnemonic]
                off = int(st.group(1), 0) if st.group(1) else 0
                if off % esize == 0:
                    return cfunc(name, "int", f"{ptype} *p",
                                  f"p[{off // esize}] = {int(mv.group(2), 0)}; "
                                  f"return {int(rt.group(1), 0)};"), "store_const_ret"
    return None


def rule_add_imm(name, ins, b):
    # add/sub r0,r0,#imm ; bx lr -> return arg +/- imm (e.g. &this->field)
    if len(ins) == 2 and _mn(ins[0]) in ("add", "sub") and is_ret(ins[1]):
        m = re.fullmatch(r"r0,r0," + IMM, squash(ins[0].op_str))
        if m:
            sign = "+" if _mn(ins[0]) == "add" else "-"
            return cfunc(name, "int", "int p", f"return p {sign} {int(m.group(1), 0)};"), "add_imm"
    return None


def rule_cmp_eq(name, ins, b):
    # <load> r0,[r0(,#off)] ; cmp r0,#k ; moveq r0,#a ; movne r0,#bv ; bx lr
    #   -> return p[i] ==/!= k     (ARM-only: Thumb1 has no conditional mov)
    if (len(ins) == 5 and ins[0].mnemonic in LOADS and ins[1].mnemonic == "cmp"
            and ins[2].mnemonic == "moveq" and ins[3].mnemonic == "movne" and is_ret(ins[4])):
        m = MEM_RE.match(squash(ins[0].op_str))
        c = re.fullmatch(r"r0," + IMM, squash(ins[1].op_str))
        eq = re.fullmatch(r"r0," + IMM, squash(ins[2].op_str))
        ne = re.fullmatch(r"r0," + IMM, squash(ins[3].op_str))
        if m and c and eq and ne:
            ptype, esize = LOADS[ins[0].mnemonic]
            off = int(m.group(1), 0) if m.group(1) else 0
            eqv, nev = int(eq.group(1), 0), int(ne.group(1), 0)
            if off % esize == 0 and {eqv, nev} == {0, 1}:
                op = "==" if eqv == 1 else "!="
                return cfunc(name, "int", f"{ptype} *p",
                              f"return p[{off // esize}] {op} {int(c.group(1), 0)};"), "cmp_eq"
    return None


def rule_bit_test(name, ins, b):
    # <load> r0,[r0(,#off)] ; ands r0,r0,#mask ; moveq r0,#a ; movne r0,#bv ; bx lr
    #   -> ARM-only, same reason as rule_cmp_eq
    if (len(ins) == 5 and ins[0].mnemonic in LOADS and ins[1].mnemonic == "ands"
            and ins[2].mnemonic == "moveq" and ins[3].mnemonic == "movne" and is_ret(ins[4])):
        m = MEM_RE.match(squash(ins[0].op_str))
        a = re.fullmatch(r"r0,r0," + IMM, squash(ins[1].op_str))
        eq = re.fullmatch(r"r0," + IMM, squash(ins[2].op_str))
        ne = re.fullmatch(r"r0," + IMM, squash(ins[3].op_str))
        if m and a and eq and ne:
            ptype, esize = LOADS[ins[0].mnemonic]
            off = int(m.group(1), 0) if m.group(1) else 0
            eqv, nev = int(eq.group(1), 0), int(ne.group(1), 0)
            if off % esize == 0 and {eqv, nev} == {0, 1}:
                op = "==" if eqv == 1 else "!="
                return cfunc(name, "int", f"{ptype} *p",
                              f"return (p[{off // esize}] & {int(a.group(1), 0)}) {op} 0;"), "bit_test"
    return None


def rule_field_bitop(name, ins, b):
    # add rB,r0,#off ; ldr rV,[rB] ; orr|bic rV,rV,#imm ; str rV,[rB] ; bx lr
    if (len(ins) == 5 and _mn(ins[0]) == "add" and ins[1].mnemonic == "ldr"
            and _mn(ins[2]) in ("orr", "bic") and ins[3].mnemonic == "str" and is_ret(ins[4])):
        a = re.fullmatch(r"(r\d+),r0," + IMM, squash(ins[0].op_str))
        if a:
            rB = a.group(1)
            ld = re.fullmatch(r"(r\d+),\[" + rB + r"\]", squash(ins[1].op_str))
            op = re.fullmatch(r"(r\d+),(r\d+)," + IMM, squash(ins[2].op_str))
            stm = re.fullmatch(r"(r\d+),\[" + rB + r"\]", squash(ins[3].op_str))
            off = int(a.group(2), 0)
            if ld and op and stm and off % 4 == 0:
                imm_ = int(op.group(3), 0)
                idx = off // 4
                body = f"p[{idx}] |= {imm_};" if _mn(ins[2]) == "orr" else f"p[{idx}] &= ~{imm_};"
                return cfunc(name, "void", "int *p", body), "field_bitop"
    return None


def rule_struct_copy(name, ins, b):
    # K pairs of ldr rT,[BASE,#o] ; str rT,[OTHER,#o] (bases r0/r1, consistent) ; bx lr
    if len(ins) < 3 or len(ins) % 2 == 0:
        return None
    if not is_ret(ins[-1]):
        return None
    lbase = sbase = None
    pairs = []
    for k in range(0, len(ins) - 1, 2):
        ld, st = ins[k], ins[k + 1]
        if ld.mnemonic != "ldr" or st.mnemonic != "str":
            return None
        lm = re.fullmatch(r"(r\d+),\[(r[01])(?:," + IMM + r")?\]", squash(ld.op_str))
        sm = re.fullmatch(r"(r\d+),\[(r[01])(?:," + IMM + r")?\]", squash(st.op_str))
        if not (lm and sm and lm.group(1) == sm.group(1)):
            return None
        if lbase is None:
            lbase, sbase = lm.group(2), sm.group(2)
        if (lm.group(2), sm.group(2)) != (lbase, sbase) or lbase == sbase:
            return None
        soff = int(lm.group(3), 0) if lm.group(3) else 0
        doff = int(sm.group(3), 0) if sm.group(3) else 0
        if soff % 4 or doff % 4:
            return None
        pairs.append((doff // 4, soff // 4))
    nm = {"r0": "a", "r1": "b"}
    src, dst = nm[lbase], nm[sbase]
    body = " ".join(f"{dst}[{d}] = {src}[{s}];" for d, s in pairs)
    return cfunc(name, "void", "int *a, int *b", body), "struct_copy"


def rule_set_fields(name, ins, b):
    # [mov rVi,#ki | add rT,rB,#big]* with <store> rVi,[rB(,#off)] ; [mov r0,#ret] ; bx lr
    #   -> a run of `field = const` stores at mixed widths/values
    if len(ins) < 3:
        return None
    bxj = next((j for j in range(1, len(ins)) if is_ret(ins[j])), None)
    if bxj is None:
        return None
    end, ret = bxj, None
    if _mn(ins[bxj - 1]) == "mov":
        rm = re.fullmatch(r"r0," + IMM, squash(ins[bxj - 1].op_str))
        if rm:
            end, ret = bxj - 1, int(rm.group(1), 0)
    base, regval, fields = {"r0": 0}, {}, []
    for ii in ins[:end]:
        s = squash(ii.op_str)
        mn = _mn(ii)
        if mn == "mov":
            mm = re.fullmatch(r"(r\d+)," + IMM, s)
            if not mm or mm.group(1) == "r0":
                return None
            regval[mm.group(1)] = int(mm.group(2), 0)
        elif mn == "add":
            am = re.fullmatch(r"(r\d+),(r\d+)," + IMM, s)
            if not am or am.group(2) not in base:
                return None
            base[am.group(1)] = base[am.group(2)] + int(am.group(3), 0)
        elif ii.mnemonic in STORES:
            sm = re.fullmatch(r"(r\d+),\[(r\d+)(?:," + IMM + r")?\]", s)
            if not sm or sm.group(1) not in regval or sm.group(2) not in base:
                return None
            _, esize = STORES[ii.mnemonic]
            off = base[sm.group(2)] + (int(sm.group(3), 0) if sm.group(3) else 0)
            if off % esize:
                return None
            fields.append((off, esize, regval[sm.group(1)]))
        else:
            return None
    if not fields:
        return None
    ty = {4: "int", 2: "short", 1: "char"}
    lines = "".join(f"    *({ty[es]} *)(p + {off:#x}) = {val};\n" for off, es, val in fields)
    rettype = "void" if ret is None else "int"
    body = lines + ("" if ret is None else f"    return {ret};\n")
    return (f"{rettype} {name}(char *p)\n{{\n{body}}}\n"), "set_fields"


def rule_pool_const(name, ins, b):
    # ldr r0,[pc,#..] ; bx lr ; .word N  (size 12) - must load into r0 and
    # return (not a thunk).
    if len(b) >= 12 and ins and ins[0].mnemonic == "ldr":
        s0 = squash(ins[0].op_str)
        if s0.startswith("r0,[pc") and any(is_ret(i) for i in ins[:3]):
            word = int.from_bytes(b[8:12], "little")
            signed = word - (1 << 32) if word >= (1 << 31) else word
            return cfunc(name, "int", "void", f"return {signed};"), "pool_const"
    return None


def rule_global_setter(name, ins, b):
    # ldr rB,[pc..] ; <store> r0,[rB(,#off)] ; bx lr ; .word G -> GLOBAL.field = arg
    if len(ins) >= 3 and ins[0].mnemonic == "ldr" and ins[1].mnemonic in STORES and is_ret(ins[2]):
        ld = PCLD_RE.fullmatch(squash(ins[0].op_str))
        if ld:
            st = re.fullmatch(r"r0,\[" + ld.group(1) + r"(?:," + IMM + r")?\]", squash(ins[1].op_str))
            if st:
                ptype, esize = STORES[ins[1].mnemonic]
                off = int(st.group(1), 0) if st.group(1) else 0
                if off % esize == 0:
                    return (f"extern {ptype} G[];\n"
                            f"void {name}(int v) {{ G[{off // esize}] = v; }}\n"), "global_setter"
    return None


def rule_global_store_const(name, ins, b):
    # ldr rB,[pc] ; mov rV,#imm ; <store> rV,[rB(,#off)] ; bx lr ; .word G
    if (len(ins) >= 4 and ins[0].mnemonic == "ldr" and _mn(ins[1]) == "mov"
            and ins[2].mnemonic in STORES and is_ret(ins[3])):
        ld = PCLD_RE.fullmatch(squash(ins[0].op_str))
        mv = re.fullmatch(r"(r\d+)," + IMM, squash(ins[1].op_str))
        if ld and mv:
            st = re.fullmatch(mv.group(1) + r",\[" + ld.group(1) + r"(?:," + IMM + r")?\]",
                              squash(ins[2].op_str))
            if st:
                ptype, esize = STORES[ins[2].mnemonic]
                off = int(st.group(1), 0) if st.group(1) else 0
                if off % esize == 0:
                    return (f"extern {ptype} G[];\n"
                            f"void {name}(void) {{ G[{off // esize}] = "
                            f"{int(mv.group(2), 0)}; }}\n"), "global_store_const"
    return None


def rule_global_index(name, ins, b):
    # ldr rB,[pc] ; <load> r0,[rB,r0(,lsl #k)] ; bx lr ; .word G -> return G[i]
    if len(ins) >= 3 and ins[0].mnemonic == "ldr" and ins[1].mnemonic in LOADS and is_ret(ins[2]):
        ld = PCLD_RE.fullmatch(squash(ins[0].op_str))
        if ld:
            idx = re.fullmatch(r"r0,\[" + ld.group(1) + r",r0(?:,lsl" + IMM + r")?\]",
                               squash(ins[1].op_str))
            if idx:
                ptype, _ = LOADS[ins[1].mnemonic]
                return (f"extern {ptype} G[];\n"
                        f"int {name}(int i) {{ return G[i]; }}\n"), "global_index"
    return None


def rule_global_deref(name, ins, b):
    # ldr rB,[pc] ; ldr rP,[rB] ; [add rP,rP,#big] ; <load> r0,[rP(,#off)] ; bx lr ; .word &G
    # G is a global pointer; returns G[idx].
    if len(ins) < 4 or ins[0].mnemonic != "ldr" or ins[1].mnemonic != "ldr":
        return None
    b0 = PCLD_RE.fullmatch(squash(ins[0].op_str))
    if not b0:
        return None
    ldp = re.fullmatch(r"(r\d+),\[" + b0.group(1) + r"\]", squash(ins[1].op_str))
    if not ldp:
        return None
    rP = ldp.group(1)
    base_off, i = 0, 2
    if i < len(ins) and _mn(ins[i]) == "add":
        a = re.fullmatch(rP + r"," + rP + r"," + IMM, squash(ins[i].op_str))
        if not a:
            return None
        base_off = int(a.group(1), 0)
        i += 1
    if i + 1 >= len(ins) or ins[i].mnemonic not in LOADS:
        return None
    if not is_ret(ins[i + 1]):
        return None
    m = re.fullmatch(r"r0,\[" + rP + r"(?:," + IMM + r")?\]", squash(ins[i].op_str))
    if not m:
        return None
    ptype, esize = LOADS[ins[i].mnemonic]
    off = base_off + (int(m.group(1), 0) if m.group(1) else 0)
    if off % esize:
        return None
    return (f"extern {ptype} *G;\n"
            f"int {name}(void) {{ return G[{off // esize}]; }}\n"), "global_deref"


def rule_global_field_bitop(name, ins, b):
    # ldr rB,[pc] ; <load> rV,[rB,#off] ; orr|bic rV,rV,#imm ; <store> rV,[rB,#off] ; bx lr
    if (len(ins) >= 5 and ins[0].mnemonic == "ldr" and ins[1].mnemonic in LOADS
            and _mn(ins[2]) in ("orr", "bic") and ins[3].mnemonic in STORES and is_ret(ins[4])):
        ld0 = PCLD_RE.fullmatch(squash(ins[0].op_str))
        if ld0:
            rB = ld0.group(1)
            lm = re.fullmatch(r"(r\d+),\[" + rB + r"(?:," + IMM + r")?\]", squash(ins[1].op_str))
            op = re.fullmatch(r"(r\d+),(r\d+)," + IMM, squash(ins[2].op_str))
            sm = re.fullmatch(r"(r\d+),\[" + rB + r"(?:," + IMM + r")?\]", squash(ins[3].op_str))
            if lm and op and sm:
                ltype, lesz = LOADS[ins[1].mnemonic]
                _, sesz = STORES[ins[3].mnemonic]
                off = int(lm.group(2), 0) if lm.group(2) else 0
                soff = int(sm.group(2), 0) if sm.group(2) else 0
                if lesz == sesz and off == soff and off % lesz == 0:
                    imm_ = int(op.group(3), 0)
                    idx = off // lesz
                    lval = f"*({ltype}*)G" if idx == 0 else f"*({ltype}*)(G+{idx})"
                    body = f"{lval} |= {imm_};" if _mn(ins[2]) == "orr" else f"{lval} &= ~{imm_};"
                    return (f"extern {ltype} G[];\nvoid {name}(void) {{ {body} }}\n"), "global_field_bitop"
    return None


def rule_global_bit_test(name, ins, b):
    # ldr rB,[pc] ; <load> r0,[rB] ; ands r0,r0,#mask ; movne r0,#a ; moveq r0,#bv ; bx ; .word &G
    #   -> ARM-only, same reason as rule_cmp_eq
    if (len(ins) >= 6 and ins[0].mnemonic == "ldr" and ins[1].mnemonic in LOADS
            and ins[2].mnemonic == "ands" and ins[3].mnemonic == "movne"
            and ins[4].mnemonic == "moveq" and is_ret(ins[5])):
        b0 = PCLD_RE.fullmatch(squash(ins[0].op_str))
        if b0:
            ld = re.fullmatch(r"r0,\[" + b0.group(1) + r"\]", squash(ins[1].op_str))
            a = re.fullmatch(r"r0,r0," + IMM, squash(ins[2].op_str))
            ne = re.fullmatch(r"r0," + IMM, squash(ins[3].op_str))
            eq = re.fullmatch(r"r0," + IMM, squash(ins[4].op_str))
            if ld and a and ne and eq:
                ptype = UWORD.get(ins[1].mnemonic, (LOADS[ins[1].mnemonic][0],))[0]
                nev, eqv = int(ne.group(1), 0), int(eq.group(1), 0)
                if {nev, eqv} == {0, 1}:
                    op = "!=" if nev == 1 else "=="
                    return (f"extern {ptype} G;\n"
                            f"int {name}(void) {{ return (G & {int(a.group(1), 0)}) {op} 0; }}\n"), \
                        "global_bit_test"
    return None


def rule_two_global_setters(name, ins, b):
    # ldr rB,[pc] ; ldr rC,[pc] ; <store> r0,[rB] ; <store> r1,[rC] ; bx lr ; .word A ; .word B
    if (len(ins) >= 5 and ins[0].mnemonic == "ldr" and ins[1].mnemonic == "ldr"
            and ins[2].mnemonic in STORES and ins[3].mnemonic in STORES and is_ret(ins[4])):
        b0 = PCLD_RE.fullmatch(squash(ins[0].op_str))
        b1 = PCLD_RE.fullmatch(squash(ins[1].op_str))
        if b0 and b1:
            s0 = re.fullmatch(r"r0,\[" + b0.group(1) + r"\]", squash(ins[2].op_str))
            s1 = re.fullmatch(r"r1,\[" + b1.group(1) + r"\]", squash(ins[3].op_str))
            if s0 and s1:
                pt0, _ = STORES[ins[2].mnemonic]
                pt1, _ = STORES[ins[3].mnemonic]
                return (f"extern {pt0} A[]; extern {pt1} B[];\n"
                        f"void {name}(int a, int b) {{ A[0] = a; B[0] = b; }}\n"), "two_global_setters"
    return None


def rule_two_global_store_const(name, ins, b):
    # ldr rB,[pc] ; mov rV,#k ; ldr rC,[pc] ; <store> rV,[rB] ; <store> rV,[rC] ; bx lr ; .word A,B
    if (len(ins) >= 6 and ins[0].mnemonic == "ldr" and _mn(ins[1]) == "mov"
            and ins[2].mnemonic == "ldr" and ins[3].mnemonic in STORES
            and ins[4].mnemonic == ins[3].mnemonic and is_ret(ins[5])):
        b0 = PCLD_RE.fullmatch(squash(ins[0].op_str))
        mv = re.fullmatch(r"(r\d+)," + IMM, squash(ins[1].op_str))
        b1 = PCLD_RE.fullmatch(squash(ins[2].op_str))
        if b0 and mv and b1:
            s0 = re.fullmatch(mv.group(1) + r",\[" + b0.group(1) + r"\]", squash(ins[3].op_str))
            s1 = re.fullmatch(mv.group(1) + r",\[" + b1.group(1) + r"\]", squash(ins[4].op_str))
            if s0 and s1:
                ptype, _ = STORES[ins[3].mnemonic]
                k = int(mv.group(2), 0)
                return (f"extern {ptype} A, B;\n"
                        f"void {name}(void) {{ A = {k}; B = {k}; }}\n"), "two_global_store_const"
    return None


def rule_global_swap(name, ins, b):
    # ldr rB,[pc] ; ldr rO,[rB] ; str r0,[rB] ; mov r0,rO ; bx lr ; .word &G
    #   -> old = G; G = arg; return old
    if (len(ins) >= 5 and ins[0].mnemonic == "ldr" and ins[1].mnemonic == "ldr"
            and ins[2].mnemonic == "str" and _mn(ins[3]) == "mov" and is_ret(ins[4])):
        b0 = PCLD_RE.fullmatch(squash(ins[0].op_str))
        if b0:
            lo = re.fullmatch(r"(r\d+),\[" + b0.group(1) + r"\]", squash(ins[1].op_str))
            st = re.fullmatch(r"r0,\[" + b0.group(1) + r"\]", squash(ins[2].op_str))
            if lo and st and re.fullmatch(r"r0," + lo.group(1), squash(ins[3].op_str)):
                return ("extern int G;\n"
                        f"int {name}(int v) {{ int old = G; G = v; return old; }}\n"), "global_swap"
    return None


def rule_setbit_byidx(name, ins, b):
    # ldr rB,[pc] ; mov rV,#1 ; ldr rW,[rB,#off] ; orr r0,rW,rV,lsl r0 ; str r0,[rB,#off] ; bx lr
    if (len(ins) >= 6 and ins[0].mnemonic == "ldr" and _mn(ins[1]) == "mov"
            and ins[2].mnemonic == "ldr" and _mn(ins[3]) == "orr"
            and ins[4].mnemonic == "str" and is_ret(ins[5])):
        ld = PCLD_RE.fullmatch(squash(ins[0].op_str))
        mv = re.fullmatch(r"(r\d+),#1", squash(ins[1].op_str))
        if ld and mv:
            lw = re.fullmatch(r"(r\d+),\[" + ld.group(1) + r"(?:," + IMM + r")?\]", squash(ins[2].op_str))
            orr = re.fullmatch(r"r0,(r\d+)," + mv.group(1) + r",lslr0", squash(ins[3].op_str))
            st = re.fullmatch(r"r0,\[" + ld.group(1) + r"(?:," + IMM + r")?\]", squash(ins[4].op_str))
            if lw and orr and st:
                off = int(lw.group(2), 0) if lw.group(2) else 0
                if off % 4 == 0:
                    return ("extern int G[];\n"
                            f"void {name}(int n) {{ G[{off // 4}] |= 1 << n; }}\n"), "setbit_byidx"
    return None


def rule_testbit_byidx(name, ins, b):
    # ldr rB,[pc] ; mov rV,#1 ; ldr rW,[rB,#off] ; and r0,rW,rV,lsl r0 ; bx lr
    if (len(ins) >= 5 and ins[0].mnemonic == "ldr" and _mn(ins[1]) == "mov"
            and ins[2].mnemonic == "ldr" and _mn(ins[3]) == "and" and is_ret(ins[4])):
        ld = PCLD_RE.fullmatch(squash(ins[0].op_str))
        mv = re.fullmatch(r"(r\d+),#1", squash(ins[1].op_str))
        if ld and mv:
            lw = re.fullmatch(r"(r\d+),\[" + ld.group(1) + r"(?:," + IMM + r")?\]", squash(ins[2].op_str))
            a = re.fullmatch(r"r0,(r\d+)," + mv.group(1) + r",lslr0", squash(ins[3].op_str))
            if lw and a:
                off = int(lw.group(2), 0) if lw.group(2) else 0
                if off % 4 == 0:
                    return ("extern int G[];\n"
                            f"int {name}(int n) {{ return G[{off // 4}] & (1 << n); }}\n"), "testbit_byidx"
    return None


def rule_two_indexed_store(name, ins, b):
    # ldr rB,[pc] ; ldr rC,[pc] ; str r1,[rB,r0,lsl #2] ; strb r2,[rC,r0] ; bx lr ; .word A ; .word B
    if (len(ins) >= 5 and ins[0].mnemonic == "ldr" and ins[1].mnemonic == "ldr"
            and ins[2].mnemonic == "str" and ins[3].mnemonic == "strb" and is_ret(ins[4])):
        b0 = re.fullmatch(r"(r\d+|ip|sb|sl|fp),\[pc.*\]", squash(ins[0].op_str))
        b1 = re.fullmatch(r"(r\d+|ip|sb|sl|fp),\[pc.*\]", squash(ins[1].op_str))
        if b0 and b1 \
                and re.fullmatch(r"r1,\[" + b0.group(1) + r",r0,lsl#2\]", squash(ins[2].op_str)) \
                and re.fullmatch(r"r2,\[" + b1.group(1) + r",r0\]", squash(ins[3].op_str)):
            return ("extern int A[]; extern unsigned char B[];\n"
                    f"void {name}(int i, int v1, int v2) {{ A[i] = v1; B[i] = v2; }}\n"), "two_indexed_store"
    return None


def rule_store_global_addr(name, ins, b):
    # ldr rX,[pc] ; str rX,[r0(,#off)] ; bx lr ; .word G -> p[idx] = &global
    if len(ins) >= 3 and ins[0].mnemonic == "ldr" and ins[1].mnemonic == "str" and is_ret(ins[2]):
        ld = PCLD_RE.fullmatch(squash(ins[0].op_str))
        if ld:
            st = re.fullmatch(ld.group(1) + r",\[r0(?:," + IMM + r")?\]", squash(ins[1].op_str))
            if st:
                off = int(st.group(1), 0) if st.group(1) else 0
                if off % 4 == 0:
                    return ("extern int G[];\n"
                            f"void {name}(int *p) {{ p[{off // 4}] = (int)G; }}\n"), "store_global_addr"
    return None


def rule_global_struct_copy(name, ins, b):
    # ldr rB,[pc]; (ldr rXi,[rB,#i*4]) xN ; (str rXi,[r0,#base+i*4]) xN ; bx lr ; .word &G
    #   -> *(struct{int w[N];}*)(p + base) = G
    if len(ins) < 4 or ins[0].mnemonic != "ldr":
        return None
    b0 = PCLD_RE.fullmatch(squash(ins[0].op_str))
    if not b0:
        return None
    rB = b0.group(1)
    end = next((j for j in range(1, len(ins)) if is_ret(ins[j])), None)
    if end is None:
        return None
    mid = ins[1:end]
    if len(mid) < 2 or len(mid) % 2:
        return None
    n = len(mid) // 2
    srcreg = {}
    for k, ld in enumerate(mid[:n]):
        lm = re.fullmatch(r"(r\d+),\[" + rB + r"(?:," + IMM + r")?\]", squash(ld.op_str))
        if ld.mnemonic != "ldr" or not lm:
            return None
        soff = int(lm.group(2), 0) if lm.group(2) else 0
        if soff % 4 or soff // 4 != k:
            return None
        srcreg[lm.group(1)] = k
    base = None
    for k, stt in enumerate(mid[n:]):
        sm = re.fullmatch(r"(r\d+),\[r0(?:," + IMM + r")?\]", squash(stt.op_str))
        if stt.mnemonic != "str" or not sm or srcreg.get(sm.group(1)) != k:
            return None
        doff = int(sm.group(2), 0) if sm.group(2) else 0
        if base is None:
            base = doff
        if base % 4 or doff != base + 4 * k:
            return None
    return (f"struct S {{ int w[{n}]; }};\nextern struct S G;\n"
            f"void {name}(char *p) {{ *(struct S *)(p + {base:#x}) = G; }}\n"), "global_struct_copy"


def rule_zero_then_global_copy(name, ins, b):
    # mov rZ,#0; ldr rB,[pc]; <store> rZ,[r0,#A]; ldr rX,[rB]; ldr rY,[rB,#4];
    #   str rX,[r0,#D]; str rY,[r0,#D+4]; bx lr -> *(p+A)=0; *(struct{int,int}*)(p+D)=G;
    if len(ins) < 8 or _mn(ins[0]) != "mov" or ins[1].mnemonic != "ldr":
        return None
    mz = re.fullmatch(r"(r\d+),#0", squash(ins[0].op_str))
    bp = PCLD_RE.fullmatch(squash(ins[1].op_str))
    if not mz or not bp or mz.group(1) == "r0":
        return None
    z, rB = mz.group(1), bp.group(1)
    sz = re.fullmatch(z + r",\[r0," + IMM + r"\]", squash(ins[2].op_str))
    if ins[2].mnemonic not in STORES or not sz:
        return None
    _, zes = STORES[ins[2].mnemonic]
    zoff = int(sz.group(1), 0)
    lx = re.fullmatch(r"(r\d+),\[" + rB + r"\]", squash(ins[3].op_str))
    ly = re.fullmatch(r"(r\d+),\[" + rB + r",#4\]", squash(ins[4].op_str))
    if ins[3].mnemonic != "ldr" or ins[4].mnemonic != "ldr" or not lx or not ly:
        return None
    sx = re.fullmatch(lx.group(1) + r",\[r0," + IMM + r"\]", squash(ins[5].op_str))
    sy = re.fullmatch(ly.group(1) + r",\[r0," + IMM + r"\]", squash(ins[6].op_str))
    if ins[5].mnemonic != "str" or ins[6].mnemonic != "str" or not sx or not sy or not is_ret(ins[7]):
        return None
    d0, d1 = int(sx.group(1), 0), int(sy.group(1), 0)
    ty = {4: "int", 2: "short", 1: "char"}
    if zoff % zes or d0 % 4 or d1 != d0 + 4:
        return None
    return ("struct S { int w[2]; };\nextern struct S G;\n"
            f"void {name}(char *p) {{ *({ty[zes]} *)(p + {zoff:#x}) = 0; "
            f"*(struct S *)(p + {d0:#x}) = G; }}\n"), "zero_then_global_copy"


# ARM-only: these key on ARM's per-instruction condition codes (moveq/movne/
# ands-before-a-conditional), which don't exist in Thumb1 (no IT blocks on
# this ARMv5TE-era ROM) - gated to ARM-mode targets in scan().
# Address -> known function name, so a generated tail-call names its real
# callee instead of inventing one. Naming matters beyond aesthetics: an extern
# whose name/address is wrong still byte-matches (match.py wildcards reloc
# slots) but links a relocation to the WRONG symbol - the defect class found in
# the 80-function batch (FUN_0232d250), see notes/mwccarm-codegen.md.
_ADDR2NAME = None


def _callee_name(addr):
    global _ADDR2NAME
    if _ADDR2NAME is None:
        _ADDR2NAME = {f["addr"]: f["name"] for f in F.load_funcs() if f.get("module")}
    # ROM code addresses are even; a Thumb callee is stored with bit0 set.
    return _ADDR2NAME.get(addr & ~1) or ("func_%08x" % (addr & ~1))


def rule_tailcall(name, ins, b):
    """ldr rC,[pc,#..] ; (ldr rX,[pc,#..] | mov rX,#imm)* ; bx rC

    A tail-call thunk: load the callee's address from the pool, set up any
    CONSTANT arguments, and branch to it without ever building a frame. Any
    register never written holds whatever the caller passed, so r0 is
    forwarded.

    Worth having as a rule because the shape is mechanical and ~18 remain - and
    because it only became matchable when the project pin moved to 2.0/*. Under
    dsi/* mwccarm would not emit the bare `bx` tail call from C (it always built
    a frame), so these read as unmatchable and some were written off as
    hand-asm. Re-tested under 2.0/sp1 they match exactly.
    """
    # The `bx` is not necessarily ins[-1]: when scan() retries at an extended
    # size to reach the literal pool, capstone happily disassembles those pool
    # WORDS as trailing junk instructions. Locate the branch instead.
    bxi = next((k for k, i in enumerate(ins)
                if i.mnemonic == "bx" and squash(i.op_str) != "lr"), None)
    if bxi is None or bxi < 1:
        return None
    creg = squash(ins[bxi].op_str)
    base = ins[0].address
    vals = {}
    for i in ins[:bxi]:
        mn, ops = _mn(i), squash(i.op_str)
        m = re.fullmatch(r"(r\d+|ip|sb|sl|fp),\[pc,?" + IMM + r"?\]", ops)
        if mn == "ldr" and m:
            off = int(m.group(2), 0) if m.group(2) else 0
            # ARM pc is insn+8; Thumb pc is (insn+4) word-aligned.
            pool = (i.address + 8 + off) if len(i.bytes) == 4 else (((i.address + 4) & ~3) + off)
            k = pool - base
            if not (0 <= k <= len(b) - 4):
                return None
            vals[m.group(1)] = int.from_bytes(b[k:k + 4], "little")
            continue
        m = re.fullmatch(r"(r\d+|ip),#(-?0x[0-9a-fA-F]+|-?\d+)", ops)
        if mn in ("mov", "movs") and m:
            vals[m.group(1)] = int(m.group(2), 0)
            continue
        return None    # anything else: not a pure constant-setup thunk
    if creg not in vals:
        return None
    callee = _callee_name(vals.pop(creg))
    args, params = [], []
    for slot, reg in enumerate(("r0", "r1", "r2", "r3")):
        if reg in vals:
            v = vals[reg]
            args.append(str(v - (1 << 32) if v >= (1 << 31) else v))
        elif slot == 0:
            args.append("a0")          # untouched r0 is forwarded
            params.append("void *a0")
        else:
            break                      # a gap means the shape is not inferable
    if not args:
        return None
    decl = ", ".join("void *" if a == "a0" else "int" for a in args)
    return ("extern void %s(%s);\n"
            "void %s(%s) { %s(%s); }\n"
            % (callee, decl, name, ", ".join(params) or "void",
               callee, ", ".join(args))), "tailcall"


ARM_ONLY_RULES = [rule_cmp_eq, rule_bit_test, rule_global_bit_test]

RULES = [rule_tailcall, rule_empty, rule_ret_const, rule_ret_arg, rule_load, rule_store,
         rule_arith, rule_global_getter, rule_load_mask, rule_bitfield,
         rule_store_const, rule_store_const_ret, rule_add_imm,
         rule_field_bitop, rule_struct_copy, rule_set_fields, rule_pool_const,
         rule_global_setter, rule_global_store_const, rule_global_index,
         rule_global_deref, rule_global_field_bitop, rule_two_global_setters,
         rule_two_global_store_const, rule_global_swap, rule_setbit_byidx,
         rule_testbit_byidx, rule_two_indexed_store, rule_store_global_addr,
         rule_global_struct_copy, rule_zero_then_global_copy]


# -------------------------------------------------------------------- oracle
def flags_for(module, mode):
    base = M.DEFAULT_FLAGS_ARM7 if module == "arm7" else M.DEFAULT_FLAGS
    if mode == "arm" and "-thumb" in base:
        base = base.replace(" -thumb", "")
    return base


def oracle_ok(c_source, name, target, module, mode):
    flags = flags_for(module, mode)
    with tempfile.TemporaryDirectory() as td:
        cfile = pathlib.Path(td) / "cand.c"
        cfile.write_text(c_source)
        obj = M.compile_c(cfile, M.CANONICAL, flags)
    if obj is None:
        return False
    code, relocs, _ = M.extract_func(obj, name)
    if code is None:
        return False
    ok, _ = M.compare(target, code, relocs, verbose=False)
    return ok


def is_thunk(ins):
    """Tail-call / linker veneer: a computed jump to anything but lr.

    This used to be a hard SKIP in scan(), on the grounds that a bare `bx`
    tail call is "not reproducible from a single isolated C function". That
    was true of dsi/*, which always built a frame instead - but it is NOT true
    of 2.0/*, this ROM's actual compiler (notes/setup-mwccarm.md). Under
    2.0/sp1 these reproduce exactly from ordinary C, so the skip was hiding a
    whole matchable class; rule_tailcall handles them now and the oracle still
    filters anything that does not really match. Kept as a predicate because
    it is a useful thing to be able to ask about a shape."""
    return any(i.mnemonic == "bx" and squash(i.op_str) != "lr" for i in ins)


def rom_bytes(module, addr, length):
    """Raw ROM bytes for a function, independent of Ghidra's cached size -
    see scan()'s `extend` parameter for why this matters."""
    rel_path, base = M.MODULES[module]
    path = M.DSD_EXTRACT / rel_path
    data = path.read_bytes()
    off = addr - base
    return data[off:off + length]


def scan(module_filter, min_size, max_size, mode_filter, extend=0):
    """Find template-matchable functions. `extend`: also retry, past the
    Ghidra-cached size, at every 2-byte-larger window up to +extend bytes
    read straight from the ROM (see notes/tooling.md's "Ghidra's function
    size can exclude a trailing literal pool" - a real, recurring cause of
    rules like rule_pool_const missing an otherwise-exact shape purely
    because the cached size cuts off before the trailing pool word). Each
    hit records the SIZE that actually matched, which may differ from the
    Ghidra cache - callers must use hit size, not f["size"], when banking."""
    done = L.load_done()
    hits = []
    for f in F.load_funcs():
        if f["module"] is None:
            continue
        if module_filter and f["module"] != module_filter:
            continue
        if not (min_size <= f["size"] <= max_size):
            continue
        if mode_filter and f["mode"] != mode_filter:
            continue
        if (f["module"], f["addr"]) in done:
            continue
        md = MD.get(f["mode"])
        if md is None:
            continue

        sizes = [f["size"]] + (list(range(f["size"] + 2, f["size"] + extend + 1, 2)) if extend else [])
        for size in sizes:
            tgt = F.target_bytes(f) if size == f["size"] else rom_bytes(f["module"], f["addr"], size)
            ins = list(md.disasm(tgt, 0))
            if not ins:
                continue
            rules = RULES + ARM_ONLY_RULES if f["mode"] == "arm" else RULES
            for rule in rules:
                cand = rule(f["name"], ins, tgt)
                if not cand:
                    continue
                csrc, label = cand
                if oracle_ok(csrc, f["name"], tgt, f["module"], f["mode"]):
                    hits.append((dict(f, size=size), csrc, label))
                    break
            else:
                continue
            break
    return hits


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--module", default=None, choices=list(M.MODULES))
    ap.add_argument("--min", type=lambda x: int(x, 0), default=0x2)
    ap.add_argument("--max", type=lambda x: int(x, 0), default=0x20)
    ap.add_argument("--mode", default=None, choices=["arm", "thumb"])
    ap.add_argument("--apply", action="store_true", help="bank wins via tools/ledger.py")
    ap.add_argument("--verbose", action="store_true", help="print each win's C")
    ap.add_argument("--extend", type=lambda x: int(x, 0), default=0,
                     help="also retry past the Ghidra-cached size, up to this many extra "
                          "bytes read from the ROM (catches rule_pool_const etc. missing a "
                          "trailing literal pool Ghidra's boundary excluded - see notes/tooling.md)")
    args = ap.parse_args()

    print(f"scanning unmatched functions (size 0x{args.min:x}-0x{args.max:x}"
          f"{', module ' + args.module if args.module else ''}"
          f"{', mode ' + args.mode if args.mode else ''}"
          f"{', extend +0x' + format(args.extend, 'x') if args.extend else ''})...")
    hits = scan(args.module, args.min, args.max, args.mode, args.extend)

    by_label = {}
    for f, csrc, label in hits:
        by_label.setdefault(label, []).append(f["name"])
        print(f"  [{label}] {f['module']:16} {f['name']:30} @ 0x{f['addr']:08x} "
              f"(0x{f['size']:x}, {f['mode']})")
        if args.verbose:
            print("    " + csrc.strip().replace("\n", "\n    "))

    print(f"\n{len(hits)} candidate(s) found, by rule: "
          + ", ".join(f"{k}={len(v)}" for k, v in sorted(by_label.items())))

    if not args.apply:
        print("(dry-run: nothing banked; re-run with --apply)")
        return

    banked = 0
    for f, csrc, label in hits:
        st = L.bank({"addr": f["addr"], "name": f["name"], "size": f["size"],
                      "module": f["module"], "versions": [f"template:{label}"]}, csrc)
        banked += st == "banked"
        if st != "banked":
            print(f"  {f['name']}: {st}")
    print(f"banked {banked}/{len(hits)}")


if __name__ == "__main__":
    main()
