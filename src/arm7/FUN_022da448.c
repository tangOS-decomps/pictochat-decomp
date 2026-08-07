// decomp: module=arm7 addr=0x022da448 name=FUN_022da448
// flags: -noThumb
// Tears down chat entry `idx`: releases its resources, clears the first
// halfword of its 0x1c-byte record and decrements the live-entry counter.
extern void FUN_022ded7c(int idx);

void FUN_022da448(int idx)
{
    FUN_022ded7c(idx);
    *(unsigned short *)(*(unsigned char **)(*(unsigned char **)0x0380fff4 + 0x31c) + idx * 0x1c) = 0;
    *(unsigned short *)(*(unsigned char **)0x0380fff4 + 0x52c) -= 1;
}
