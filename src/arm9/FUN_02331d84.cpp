//cpp
// decomp: module=unk_autoload_0 addr=0x02331d84 name=FUN_02331d84
// NONMATCHING: identical stream apart from one r0/r1 swap in the entry block: the target holds the flag value in r0 and the block base in r1, mwcc picks the reverse for every phrasing tried (direct member access, named local, local base pointer). (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.

// One-shot shutdown: latches the flag, drains, clears both counters and drops
// interrupt bit 4.

#pragma thumb on
extern "C" {
typedef struct Ctl {
    unsigned short on;
    unsigned short pad;
    int a;
    int b;
} Ctl;
extern Ctl G_023c0af0;
extern void FUN_02331be8(void);
extern unsigned int FUN_023307f8(unsigned int);
void FUN_02331d84(void)
{
    unsigned short on = G_023c0af0.on;

    if (on != 0) return;
    on = 1;
    G_023c0af0.on = on;
    FUN_02331be8();
    G_023c0af0.a = 0;
    G_023c0af0.b = 0;
    FUN_023307f8(0x10);
}
}
