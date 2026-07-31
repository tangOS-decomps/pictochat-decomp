// decomp: module=unk_autoload_0 addr=0x02321df4 name=FUN_02321df4
// NONMATCHING: instruction-scheduling swap: target loads the tail-call callee address (r3) before the argument (r0), every plain-C rephrasing (including a local fn-pointer variable, same trick tried on FUN_02320978) keeps arg-then-callee order. 1 word mismatch, otherwise byte-identical (div=1). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct S {
    int f0;
    int f4, f8, fc, f10;
    int f14;
    int f18, f1c, f20, f24;
};
extern struct S G;
extern int F(void *);
extern int G2[];
int FUN_02321df4(void) {
    G.f0 = 144;
    G.f14 = -1;
    G.f4 = 0;
    G.f8 = 0;
    G.fc = 0;
    G.f10 = 0;
    G.f18 = 0;
    G.f1c = 0;
    G.f20 = 0;
    G.f24 = 0;
    return F(G2);
}
