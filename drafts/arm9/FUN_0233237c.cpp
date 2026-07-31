// decomp: module=unk_autoload_0 addr=0x0233237c name=FUN_0233237c
// NONMATCHING: struct field initializer (f14=-3, f18=f1c=f20=f24=0 on global G_023c0ba0) - fully logic-correct and same instruction shapes/count/order as target, but the compiler always colors the computed value into r1 and the struct base pointer into r0, while the target has them swapped (value in r0, pointer in r1), regardless of declaration/statement order (tried inline, local pointer var, local value var, -3 literal vs ~2). Pure register-coloring difference; also a 45s/600+ iteration decomp-permuter run found no score-0. Also note Ghidra's cached size (0x14) excluded the trailing pool word for G_023c0ba0's address - true size 0x18. (div=5). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct S023c0ba0 {
    char pad[0x14];
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
};
extern struct S023c0ba0 G_023c0ba0;

void FUN_0233237c(void) {
    G_023c0ba0.f14 = ~2;
    G_023c0ba0.f18 = 0;
    G_023c0ba0.f24 = 0;
    G_023c0ba0.f20 = 0;
    G_023c0ba0.f1c = 0;
}
