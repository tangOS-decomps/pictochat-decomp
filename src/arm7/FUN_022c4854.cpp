// decomp: module=arm7 addr=0x022c4854 name=FUN_022c4854
// NONMATCHING: register-coloring: target colors the pointer into r2 and the zero constant into r1, every plain-C rephrasing (direct field, local pointer var, reordered locals) colors them the opposite way (div=4). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern unsigned short G[];
int FUN_022c4854(void) {
    int zero = 0;
    int v = G[0];
    G[0] = zero;
    return v;
}
