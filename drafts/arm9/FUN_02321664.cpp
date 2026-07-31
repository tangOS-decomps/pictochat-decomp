// decomp: module=unk_autoload_0 addr=0x02321664 name=FUN_02321664
// NONMATCHING: register-coloring: target keeps r4 live across 4 local-array stores + call, every plain-C rephrasing colors it via r0 instead (div=6). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int G[];
extern int FUN_02321a6c(int arr[4]);
int FUN_02321664(void) {
    int arr[4];
    arr[0] = (int)G;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = -1;
    return FUN_02321a6c(arr);
}
