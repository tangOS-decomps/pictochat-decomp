// decomp: module=arm7 addr=0x022da03c name=FUN_022da03c
// flags: -noThumb

// Returns the requested bit of the flag word at +0x52e, shifted down to 0/1 -
// the FUN_022da01c shape against a different field. The shift is ARITHMETIC in
// the ROM, so the value is read through `int`.

unsigned int FUN_022da03c(unsigned int bit)
{
    return ((int)*(unsigned short *)(*(int *)0x0380fff4 + 0x52e) >> bit) & 1;
}
