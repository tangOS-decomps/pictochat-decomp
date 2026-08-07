// decomp: module=arm7 addr=0x022d531c name=FUN_022d531c
// flags: -O4,s -noThumb

// Builds and queues a beacon frame for the channels still enabled in `mask`.
// If the remaining airtime at ctx+0x72 cannot cover the frame the attempt is
// abandoned with error 2; otherwise the extra IE block is added when either
// of the two mode words is 1 and the capability word gets bit 15 to match.

extern void FUN_037cb520(void);
extern void FUN_037cb534(void);
extern int FUN_022d5310(int mask);
extern void FUN_037c9c2c(int code);
extern void FUN_022cfa90(void);
extern int FUN_022d5c68(int a, int b, int mask, int d);
extern void FUN_022d0350(void *buf, int kind, int a, int b,
                         unsigned short mask, int extra, int beacon,
                         int pad, unsigned short caps, int tail);

extern void *G_023190dc[];

void FUN_022d531c(int arg)
{
    unsigned char buf[0x200];
    int mask;
    unsigned short beacon;
    int caps;
    unsigned char *ctx;
    int rate;
    int extra;

    ctx = (unsigned char *)G_023190dc[0x154];
    FUN_037cb520();
    FUN_037cb534();
    mask = arg & *(unsigned short *)(ctx + 0x182);
    rate = *(unsigned short *)(ctx + 0x3a);
    beacon = *(volatile unsigned short *)0x048080f8;
    caps = *(unsigned short *)(ctx + 0x6a);
    if (*(unsigned short *)(ctx + 0x72) <
        ((((rate + 0xc) * FUN_022d5310(mask)) + 0x29) & ~0x1f)) {
        FUN_037c9c2c(2);
        FUN_022cfa90();
        return;
    }
    if (*(short *)(ctx + 0x62) == 1 || *(short *)(ctx + 0x64) == 1) {
        extra = FUN_022d5c68(*(unsigned short *)(ctx + 0x6e),
                             *(unsigned short *)(ctx + 0x6c),
                             mask,
                             *(unsigned short *)(ctx + 0x40));
        caps |= 0x8000;
    } else {
        caps &= ~0x8000;
        extra = 0;
    }
    FUN_022d0350(buf, 0x800c, 0, 0,
                 (unsigned short)mask, extra, beacon, 0,
                 (unsigned short)caps, 0);
}
