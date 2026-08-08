//cpp
// decomp: module=unk_autoload_0 addr=0x02337ed0 name=FUN_02337ed0
// verify: python tools/match.py --c src/arm9/FUN_02337ed0.cpp --func FUN_02337ed0 --addr 0x02337ed0 --size 0x1c --module unk_autoload_0 --version 2.0/sp1

// Refreshes the halfword at +8 of the object behind G_023c34a0 and returns it.

#pragma thumb on
extern "C" {
extern void FUN_023314cc(void *, int);
extern char *G_023c34a0;
int FUN_02337ed0(void)
{
    FUN_023314cc(G_023c34a0 + 8, 2);
    return *(unsigned short *)(G_023c34a0 + 8);
}
}
