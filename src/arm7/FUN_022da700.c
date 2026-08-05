// decomp: module=arm7 addr=0x022da700 name=FUN_022da700
// flags: -noThumb

// Clears the halfword at +0x428 of the ARM7 state block.

void FUN_022da700(void)
{
    *(unsigned short *)(*(int *)0x0380fff4 + 0x428) = 0;
}
