// decomp: module=arm7 addr=0x022d71ec name=FUN_022d71ec
// flags: -O4,s -noThumb
// size: 0xb0 - the stated 0xa8 excludes the two trailing pool words
// (0x0380fff4 and 0x04808134).
//
// Programs the interval `v` (rejecting anything below 10 with error 5) into
// the state block at +0x33c and, when `flag` is set, into the hardware
// register at 0x04808134. If the beacon buffer is live, the interval is also
// patched into the outgoing frame at +0x24+f3da as a little-endian pair -
// or as 0xffff when the frame is not of type 1.

typedef struct {
    unsigned char  pad000[0x33c];
    unsigned short f33c;
    unsigned char  pad33e[0x14];
    unsigned short f352;
    unsigned char  pad354[0x86];
    unsigned short f3da;
    unsigned char  pad3dc[0xc8];
    unsigned short f4a4;
    unsigned char  pad4a6[6];
    unsigned char *f4ac;
} State;

extern State *G_0380fff4;
extern void FUN_022d8d40(void *p, int b);

int FUN_022d71ec(unsigned short v, int flag)
{
    State *s;
    unsigned char *p;

    if (v < 0xa) {
        return 5;
    }

    G_0380fff4->f33c = v;
    if (flag) {
        *(volatile unsigned short *)0x04808134 = v;
    }

    s = G_0380fff4;
    if (s->f4a4 != 0) {
        p = s->f4ac + 0x24 + s->f3da;
        if (s->f352 == 1) {
            FUN_022d8d40(p + 6, v & 0xff);
            FUN_022d8d40(p + 7, (v >> 8) & 0xff);
        } else {
            FUN_022d8d40(p + 6, 0xff);
            FUN_022d8d40(p + 7, 0xff);
        }
    }

    return 0;
}
