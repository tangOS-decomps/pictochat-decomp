// decomp: module=arm7 addr=0x022d3bd4 name=FUN_022d3bd4
// flags: -noThumb
//
// Single-argument tail call to an external syscall/OS primitive
// (func_037fe508, which lives outside every extracted module - a shared WRAM
// OS component, also a callee of FUN_022ce8b0).
//
// History: was parked NONMATCHING because the target loads the callee into
// `ip` before the argument into `r0`, while every phrasing tried (direct
// call, function-pointer local, function-pointer cast at the call site,
// argument-first local, -O4,s) emitted r0 then ip - recorded as the same
// pool-load-order floor class documented elsewhere in this project. It was
// not a floor: that verdict was reached at mwccarm dsi/1.3, and this ROM is
// built by 2.0/* (notes/setup-mwccarm.md). This file compiles BYTE-EXACT on
// 2.0/sp1..2.0/sp2p4 completely unchanged - no source edit was ever needed,
// only the correct toolchain.

extern int func_037fe508(void *arg);

int FUN_022d3bd4(void) {
    void *arg = (void *)0x03807230;
    return func_037fe508(arg);
}
