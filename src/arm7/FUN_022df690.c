// decomp: module=arm7 addr=0x022df690 name=FUN_022df690
// flags: -noThumb

// True when the counter at +0x1a8 is still below 0x18 minus the counter at
// +0x538 - a capacity check against a reserved allowance.

int FUN_022df690(void)
{
    int base = *(int *)0x0380fff4;
    int lim = 0x18 - *(unsigned short *)(base + 0x538);
    return *(unsigned short *)(base + 0x1a8) < lim;
}
