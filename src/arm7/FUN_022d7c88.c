// decomp: module=arm7 addr=0x022d7c88 name=FUN_022d7c88
// flags: -O4,s -noThumb

// Records the requested power-save flag at +0x352 and mirrors it into bit 6 of
// the wifi register at 0x04808006.  The bit only goes *on* when the link state
// at +0x32e is not 1; in every other case the bit is cleared and the current
// beacon interval at +0x33c is re-applied.  Always reports success.
//
// The +0x31c fields have to be reached through their own local pointer: the
// ROM keeps base+0x31c live in a register alongside base+0x300, which spelling
// them as base-relative constants does not reproduce.

extern void FUN_022d71ec(unsigned short a, int b);

int FUN_022d7c88(unsigned short enable)
{
    int base = *(int *)0x0380fff4;
    unsigned short *p = (unsigned short *)(base + 0x31c);

    *(unsigned short *)(base + 0x352) = enable;

    if (enable != 0 && p[9] != 1) {
        *(unsigned short *)0x04808006 |= 0x40;
    } else {
        *(unsigned short *)0x04808006 &= ~0x40;
        FUN_022d71ec(p[16], 0);
    }
    return 0;
}
