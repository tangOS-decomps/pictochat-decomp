// decomp: module=arm7 addr=0x022d3c98 name=FUN_022d3c98
// flags: -O4,s -noThumb

// Beacon/VBlank sync tick.  Latches the 16-bit counter at 0x0380fff0 into
// ctx +0xd0; when it changed since the last tick (+0xd4) it scales it by 64,
// reads the 32-bit TSF microsecond counter (lo/hi/lo re-read for carry), and
// projects it to the end of the frame from REG_VCOUNT (127 half-us per line).
// The latched value is then stepped by 0x414b up to 29 times until it passes
// that limit; the overshoot (0 if out of range) goes to +0xd8.  Finally the
// +0xd8 debt picks which FUN_037cb0b8 call is made (+0x1c set when small).

typedef struct Ctx {
    char pad0[0x1c];
    int f1c;                /* +0x1c */
    char pad1[0x22];
    short f42;              /* +0x42 */
    char pad2[0x8c];
    unsigned int d0;        /* +0xd0 */
    unsigned int d4;        /* +0xd4 */
    unsigned int d8;        /* +0xd8 */
} Ctx;

typedef struct ConnMgr {
    char pad[0x550];
    Ctx *ctx;               /* +0x550 */
} ConnMgr;

extern ConnMgr G_023190dc;

extern void FUN_037cb0b8(void *buf, int a, int b, const char *tag, int flag);

void FUN_022d3c98(void)
{
    Ctx *c = G_023190dc.ctx;

    c->d0 = *(volatile unsigned short *)0x0380fff0;
    if (c->d4 != c->d0) {
        int i;
        unsigned int limit;
        Ctx *c2;
        unsigned int lo;
        unsigned int hi;
        unsigned int lo2;
        unsigned int tsf;

        c->d4 = c->d0;
        c2 = G_023190dc.ctx;
        c2->d0 <<= 6;
        lo = *(volatile unsigned short *)0x048080f8;
        hi = *(volatile unsigned short *)0x048080fa;
        lo2 = *(volatile unsigned short *)0x048080f8;
        if (lo > lo2) {
            hi = *(volatile unsigned short *)0x048080fa;
        }
        tsf = lo2 | (hi << 16);
        limit = ((tsf & 0x3fffc0) * 2 + (0x107 - *(volatile unsigned short *)0x04000006) * 127) / 2 & 0x3fffc0;
        if (c2->d0 > limit) {
            c2->d8 = 0;
            goto done;
        }
        for (i = 1; i < 30; i++) {
            c2->d0 += 0x414b;
            if (c2->d0 > limit) {
                c2->d8 = c2->d0 - limit;
                if (c2->d8 > 0x400e) {
                    c2->d8 = 0;
                }
                goto done;
            }
        }
        c2->d8 = 0;
    }
done:
    if (c->d8 > 0x7f) {
        FUN_037cb0b8((void *)0x03807230, 0xd0, 0x107, (const char *)0x023070ac, 2);
    } else {
        c->f1c = 1;
        FUN_037cb0b8((void *)0x03807230, c->f42, 0x107, (const char *)0x0230716c, 4);
    }
}
