// decomp: module=arm7 addr=0x022d3bd4 name=FUN_022d3bd4
// NONMATCHING: pool-load-order scheduling floor (ip/r0 swapped) for a computed tail-call, tried 4 rephrasings + -O4,s (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// decomp: module=arm7 addr=0x022d3bd4 name=FUN_022d3bd4
// NONMATCHING: single-argument tail call to an external syscall/OS primitive
// (func_037fe508, outside every extracted module - shared WRAM OS component,
// callee of FUN_022ce8b0). Logic-correct, byte-identical except the target
// swaps the "load callee into ip" / "load argument into r0" pool-load order
// vs this candidate (target: ip then r0; every C rephrasing tried - direct
// call, function-pointer local, function-pointer cast at the call site,
// argument-first local, -O4,s - consistently emits r0 then ip). Same class
// as the documented pop{pc}-fold/pool-load-order floors elsewhere in this
// project; not a logic issue (div=3, all in the swapped pool-load region).
// Counts as decompiled, not matched.
extern int func_037fe508(void *arg);

int FUN_022d3bd4(void) {
    void *arg = (void *)0x03807230;
    return func_037fe508(arg);
}
