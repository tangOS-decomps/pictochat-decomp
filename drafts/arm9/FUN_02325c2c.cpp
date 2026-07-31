// decomp: module=unk_autoload_0 addr=0x02325c2c name=FUN_02325c2c
// NONMATCHING: instruction-scheduling floor: no plain-C phrasing tried (13+ variants) reproduces the target's guard-free-jump + explicit-copy-compare bottom-of-loop test (div=6). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
int FUN_02325c2c(int *p, int n)
{
    int count = (n + 3) >> 2;
    while (count-- != 0) {
        if (*p != 0) return 0;
        p++;
    }
    return 1;
}
