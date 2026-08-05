//cpp
// decomp: module=unk_autoload_0 addr=0x023366e8 name=FUN_023366e8
// NitroSDK BG character-base getter, the shape of G2_GetBG1CharPtr: the character base is split
// across two hardware registers, a per-background field in BG1CNT (0x0400000a)
// and a screen-wide field in DISPCNT (0x04000000), and the two are scaled and
// added onto the BG VRAM base 0x06000000.
//
// The association of the three terms is load-bearing, not cosmetic. The ROM
// computes bg + (disp + base); writing it left-to-right as (base + disp) + bg
// reorders the adds and stops matching, so the parentheses below must stay.

#pragma thumb on
extern "C" {
void *FUN_023366e8(void)
{
    return (void *)(((((*(volatile unsigned short *)0x0400000a) & 0x3c) >> 2) * 0x4000)
        + (((((*(volatile unsigned int *)0x04000000) & 0x7000000) >> 24) * 0x10000) + 0x06000000));
}
}
