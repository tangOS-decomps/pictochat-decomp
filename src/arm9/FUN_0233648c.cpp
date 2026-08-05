//cpp
// decomp: module=unk_autoload_0 addr=0x0233648c name=FUN_0233648c

// Sub-engine BG2 screen base, the G2S_GetBG2ScrPtr shape: the screen-base field
// of BG2CNT scaled onto the sub BG VRAM base 0x06200000.

#pragma thumb on
extern "C" {
void *FUN_0233648c(void)
{
    return (void *)(((*(volatile unsigned short *)0x04001008 & 0x1f00) >> 8) * 0x800 + 0x06200000);
}
}
