//cpp
// decomp: module=unk_autoload_0 addr=0x02322844 name=FUN_02322844
// verify: python tools/match.py --c src/arm9/FUN_02322844.cpp --func FUN_02322844 --addr 0x02322844 --size 0x2c --module unk_autoload_0 --version 2.0/sp1

// Sibling of FUN_02322820 over the second shared-WRAM list.

#pragma thumb on
extern "C" {
extern void FUN_02337424(void *, void *, int);
extern unsigned short G_0238e1fa[];
void FUN_02322844(void)
{
    unsigned char *hw = (unsigned char *)0x02FFFC9C;

    FUN_02337424(hw, G_0238e1fa, hw[0x34] * 2);
    G_0238e1fa[hw[0x34]] = 0;
}
}
