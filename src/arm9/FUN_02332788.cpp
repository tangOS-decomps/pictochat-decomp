//cpp
// decomp: module=unk_autoload_0 addr=0x02332788 name=FUN_02332788
// verify: python tools/match.py --c src/arm9/FUN_02332788.cpp --func FUN_02332788 --addr 0x02332788 --size 0x28 --module unk_autoload_0 --version 2.0/sp1

// Kicks the 0x05000001 request off a zeroed handle, then records the reply
// code in the halfword at G_023c130c+6.

#pragma thumb on
extern "C" {
extern void FUN_02332d2e(int *, void *, int);
extern int FUN_02330aa4(void);
extern char G_023c1310[];
extern short G_023c130c[];
void FUN_02332788(void)
{
    int h = 0;

    FUN_02332d2e(&h, G_023c1310, 0x05000001);
    G_023c130c[3] = (short)FUN_02330aa4();
}
}
