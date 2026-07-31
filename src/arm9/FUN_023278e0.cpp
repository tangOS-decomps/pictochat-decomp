// decomp: module=unk_autoload_0 addr=0x023278e0 name=FUN_023278e0
// NONMATCHING: instruction-scheduling swap: target loads tail-call callee (r3) before arg (r0), same recurring floor as FUN_02320978/FUN_02321df4 (div=1). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int G[];
extern int F(void *, int);
int FUN_023278e0(void) {
    return F(G, 0);
}
