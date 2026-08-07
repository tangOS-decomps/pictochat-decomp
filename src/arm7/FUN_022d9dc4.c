// decomp: module=arm7 addr=0x022d9dc4 name=FUN_022d9dc4
// flags: -O4,s -noThumb

// Clears bit `bit` of the flag word at +0x530 of the ARM7 state block, but only
// when the lookup at 0x022d9ffc reports 0x40 for that bit.

extern int FUN_022d9ffc(unsigned int bit);

void FUN_022d9dc4(unsigned int bit)
{
    unsigned short *p;

    if (FUN_022d9ffc(bit) == 0x40) {
        p = (unsigned short *)(*(int *)0x0380fff4 + 0x530);
        *p = *p & ~(1 << bit);
    }
}
