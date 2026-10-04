// decomp: module=arm7 addr=0x022c1c58 name=FUN_022c1c58
// flags: -O4,s -noThumb
// size: 0x8c - the nominal 0x84 excludes the two trailing pool words.
//
// Beacon-transmitted interrupt: acks bit 0x8000 and, while associated as an
// AP (state 0x40) with a non-zero DTIM period whose count has wrapped, steps
// the DTIM counter at +0x80, reporting event (1, 0xd) and restarting it when
// it passes the period. Finally marks the beacon as sent at +0x10.

typedef unsigned short u16;

extern void FUN_022c0e48(int a, int b);

void FUN_022c1c58(void)
{
    u16 *w = (u16 *)(*(char **)0x0380fff4 + 0x344);
    volatile u16 *io = (volatile u16 *)0x04808010;

    io[0] = 0x8000;

    if (w[4] == 0x40 && w[0x3f] != 0 && w[0x39] == w[0x38]) {
        w[0x40]++;
        if (w[0x40] > w[0x3f]) {
            w[0x40] = 0;
            FUN_022c0e48(1, 0xd);
        }
    }
    w[8] = 1;
}
