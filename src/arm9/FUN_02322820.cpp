//cpp
// decomp: module=unk_autoload_0 addr=0x02322820 name=FUN_02322820
// verify: python tools/match.py --c src/arm9/FUN_02322820.cpp --func FUN_02322820 --addr 0x02322820 --size 0x24 --module unk_autoload_0 --version 2.0/sp1

// Copies the shared-WRAM list into G_0238e1e4 and null-terminates it at the
// count the hardware block reports.

#pragma thumb on
extern "C" {
extern void FUN_02337424(void *, void *, int);
extern unsigned short G_0238e1e4[];
void FUN_02322820(void)
{
    unsigned char *hw = (unsigned char *)0x02FFFC86;

    FUN_02337424(hw, G_0238e1e4, hw[0x14] * 2);
    G_0238e1e4[hw[0x14]] = 0;
}
}
