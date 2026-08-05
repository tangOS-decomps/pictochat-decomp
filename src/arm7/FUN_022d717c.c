// decomp: module=arm7 addr=0x022d717c name=FUN_022d717c
// flags: -noThumb

// Sets bit 1 of the mode word at +0x33a - the FUN_022d7144 shape. The bit is
// placed with a shift pair rather than a mask, and the same `v > 1` guard
// spelling is required.

int FUN_022d717c(unsigned int v)
{
    unsigned short *p;
    if (v > 1) return 5;
    p = (unsigned short *)(*(int *)0x0380fff4 + 0x33a);
    *p = (*p & ~2) | ((v << 31) >> 30);
    return 0;
}
