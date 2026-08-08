//cpp
// decomp: module=unk_autoload_0 addr=0x0232c838 name=FUN_0232c838
// verify: python tools/match.py --c src/arm9/FUN_0232c838.cpp --func FUN_0232c838 --addr 0x0232c838 --size 0x24 --module unk_autoload_0 --version 2.0/sp1

// Reads the halfword at +0x150 of the live record, or 0 when there is none,
// with interrupts held off.

#pragma thumb on
extern "C" {
extern int FUN_02332080(void);
extern void FUN_02332094(int);
extern unsigned short *G_023bd8a0[];
int FUN_0232c838(void)
{
    int r;
    int s = FUN_02332080();
    unsigned short *p = G_023bd8a0[1];

    if (p != 0) r = p[0xa8];
    else r = 0;
    FUN_02332094(s);
    return r;
}
}
