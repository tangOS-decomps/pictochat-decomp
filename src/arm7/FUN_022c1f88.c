// decomp: module=arm7 addr=0x022c1f88 name=FUN_022c1f88
// flags: -O4,s -noThumb

// Wifi interrupt/ack path: acks bit 0x2000, re-arms the register at +0x9c, then
// advances the small state machine at +0x344+0x1a.  State 1 -> 2, state 2 -> 0,
// anything else falls through to the "TX done" cleanup that clears +0x38 unless
// the pending count at +0x08 is exactly 0x40.

void FUN_022c1f88(void)
{
    unsigned short *w = (unsigned short *)((*(char **)0x0380fff4) + 0x344);
    volatile unsigned short *io = (volatile unsigned short *)0x04808010;

    io[0] = 0x2000;
    io[0x4e] = 0xd;

    if (w[0xd] == 1) {
        w[0xd] = 2;
        return;
    }
    if (w[0xd] == 2) {
        w[0xd] = 0;
        return;
    }
    if (w[6] != 2) {
        return;
    }
    if (w[4] != 0x40) {
        io[0x1c] = 0;
    }
}
