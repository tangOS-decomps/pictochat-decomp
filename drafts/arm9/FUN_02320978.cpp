// decomp: module=unk_autoload_0 addr=0x02320978 name=FUN_02320978
// NONMATCHING: instruction-scheduling swap (target loads callee addr before arg regs; every plain-C rephrasing keeps arg regs first) (div=2). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int G[];
extern int F(int *, int, int);
int FUN_02320978(int a) {
    return F(G, 0, a);
}
