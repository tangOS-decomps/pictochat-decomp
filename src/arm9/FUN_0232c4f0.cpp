//cpp
// decomp: module=unk_autoload_0 addr=0x0232c4f0 name=FUN_0232c4f0
// verify: python tools/match.py --c src/arm9/FUN_0232c4f0.cpp --func FUN_0232c4f0 --addr 0x0232c4f0 --size 0x30 --module unk_autoload_0 --version 2.0/sp1

// Refreshes the head halfword of the live record and reports 3 while it still
// reads 0 or 1.

#pragma thumb on
extern "C" {
extern int FUN_0232c4dc(void);
extern void FUN_023314cc(void *, int);
extern unsigned short **G_023bd8a0[];
int FUN_0232c4f0(void)
{
    int rc = FUN_0232c4dc();

    if (rc != 0) return rc;
    FUN_023314cc(G_023bd8a0[1][1], 2);
    if (*G_023bd8a0[1][1] <= 1) return 3;
    return 0;
}
}
