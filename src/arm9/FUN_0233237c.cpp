//cpp
// decomp: module=unk_autoload_0 addr=0x0233237c name=FUN_0233237c
// NONMATCHING: byte-identical apart from a single r0/r1 swap: the target holds ~2 in r0 and the block base in r1, mwcc picks the other way round for every phrasing tried (literal, named local, local base pointer, both store orders). Permuter fodder. (div=5). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.

// Puts the block at G_023c0ba0 back to its idle state: -3 in the status slot,
// zero everywhere after it.

#pragma thumb on
extern "C" {
extern int G_023c0ba0[];
void FUN_0233237c(void)
{
    int idle = -3;

    G_023c0ba0[5] = idle;
    G_023c0ba0[6] = 0;
    G_023c0ba0[7] = 0;
    G_023c0ba0[8] = 0;
    G_023c0ba0[9] = 0;
}
}
