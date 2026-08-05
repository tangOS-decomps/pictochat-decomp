// decomp: module=arm7 addr=0x022da01c name=FUN_022da01c
// flags: -noThumb

// Returns the requested bit of the flag word at +0x530, shifted down to 0/1.
// The shift is ARITHMETIC in the ROM, so the value is read through `int`.

unsigned int FUN_022da01c(unsigned int bit)
{
    return ((int)*(unsigned short *)(*(int *)0x0380fff4 + 0x530) >> bit) & 1;
}
