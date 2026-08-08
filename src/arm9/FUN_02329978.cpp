//cpp
// decomp: module=unk_autoload_0 addr=0x02329978 name=FUN_02329978
// verify: python tools/match.py --c src/arm9/FUN_02329978.cpp --func FUN_02329978 --addr 0x02329978 --size 0x1c --module unk_autoload_0 --version 2.0/sp1

// Refreshes the 0x7d0-byte buffer two links down from G_023bd5e0 and returns
// it.

#pragma thumb on
extern "C" {
extern void FUN_023314cc(void *, int);
extern int **G_023bd5e0[];
int *FUN_02329978(void)
{
    FUN_023314cc(G_023bd5e0[1][1], 0x7d0);
    return G_023bd5e0[1][1];
}
}
