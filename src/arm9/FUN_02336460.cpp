//cpp
// decomp: module=unk_autoload_0 addr=0x02336460 name=FUN_02336460
// NitroSDK BG screen-base getter, the shape of G2_GetBG0ScrPtr: the screen base is split
// across two hardware registers, a per-background field in BG0CNT (0x04000008)
// and a screen-wide field in DISPCNT (0x04000000), and the two are scaled and
// added onto the BG VRAM base 0x06000000.
//
// The association of the three terms is load-bearing, not cosmetic. The ROM
// computes bg + (disp + base); writing it left-to-right as (base + disp) + bg
// reorders the adds and stops matching, so the parentheses below must stay.

#pragma thumb on
extern "C" {
void *FUN_02336460(void)
{
    return (void *)(((((*(volatile unsigned short *)0x04000008) & 0x1f00) >> 8) * 0x800)
        + (((((*(volatile unsigned int *)0x04000000) & 0x38000000) >> 27) * 0x10000) + 0x06000000));
}
}
