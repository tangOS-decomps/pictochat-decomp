//cpp
// decomp: module=unk_autoload_0 addr=0x02336334 name=FUN_02336334
// verify: python tools/match.py --c src/arm9/FUN_02336334.cpp --func FUN_02336334 --addr 0x02336334 --size 0x34 --module unk_autoload_0 --version 2.0/sp1

// Parks the display mode: stashes the two-bit mode out of DISPCNT, clears it
// there, and tail-calls the teardown.

#pragma thumb on
extern "C" {
extern short G_0236a178;
extern short G_023c1910;
extern void FUN_023398f4(void);
void FUN_02336334(void)
{
    volatile unsigned int *dispcnt = (volatile unsigned int *)0x04000000;
    unsigned int v = *dispcnt;

    G_0236a178 = 0;
    G_023c1910 = (short)((v & 0x30000) >> 16);
    *dispcnt = v & ~0x30000u;
    FUN_023398f4();
}
}
