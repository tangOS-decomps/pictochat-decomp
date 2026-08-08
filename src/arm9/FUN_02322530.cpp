//cpp
// decomp: module=unk_autoload_0 addr=0x02322530 name=FUN_02322530
// verify: python tools/match.py --c src/arm9/FUN_02322530.cpp --func FUN_02322530 --addr 0x02322530 --size 0x1c --module unk_autoload_0 --version 2.0/sp1

// Clears the two control words at G_0238e1dc, then sets bits 9 and 10 of the
// first one back on.

#pragma thumb on
extern "C" {
extern int G_0238e1dc[];
void FUN_02322530(void)
{
    G_0238e1dc[0] = 0;
    G_0238e1dc[1] = 0;
    G_0238e1dc[0] |= 0x200;
    G_0238e1dc[0] |= 0x400;
}
}
