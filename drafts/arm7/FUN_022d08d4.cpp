// decomp: module=arm7 addr=0x022d08d4 name=FUN_022d08d4
// NONMATCHING: ARM-mode tail-call trampoline scheduling swap: target loads callee (ip) before the pointer arg (r1), every plain-C rephrasing (incl. local fn-pointer variable) keeps r1-then-ip order. Same recurring floor as the Thumb-mode indirect-tail-call cases (FUN_02320978 etc.) (div=2). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int F(int, void *, int);
extern int G[];
int FUN_022d08d4(int a) {
    return F(a, G, 1);
}
