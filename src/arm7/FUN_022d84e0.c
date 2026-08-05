// decomp: module=arm7 addr=0x022d84e0 name=FUN_022d84e0
// flags: -noThumb

// Returns the requested bit of the 16-bit flag word at +0x32c of the structure
// pointed to by 0x0380fff4 - masked in place, not shifted down, so the result is
// the bit's own value rather than 0/1.

unsigned int FUN_022d84e0(unsigned int bit)
{
    return *(unsigned short *)(*(int *)0x0380fff4 + 0x32c) & (1 << bit);
}
