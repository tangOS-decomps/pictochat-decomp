// decomp: module=arm7 addr=0x022d7ed0 name=FUN_022d7ed0
// flags: -noThumb

// Flags the state block as idle; if no transfer is still outstanding it also
// clears the enable bit of the wifi block at 0x04808038 and zeroes 0x04808048.

void FUN_022d7ed0(void)
{
    unsigned char *state;
    volatile unsigned short *reg;

    state = *(unsigned char **)0x0380fff4;
    *(unsigned short *)(state + 0x3ea) = 1;

    state = *(unsigned char **)0x0380fff4;
    if (*(unsigned short *)(state + 0x468) != 0) {
        return;
    }

    reg = (volatile unsigned short *)0x04808038;
    reg[0] = reg[0] & ~2;
    reg[8] = 0;
}
