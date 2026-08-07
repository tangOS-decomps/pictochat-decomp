// decomp: module=arm7 addr=0x022d8e84 name=FUN_022d8e84
// flags: -O4,s -noThumb
//
// Stamps the magic pair 0xb6b8 / 0x1d46 into the two halfwords immediately
// below the context's buffer, and mirrors it into the buffer's own 0xc/0xe
// slots. If the magic is already present nothing happens and 0 is returned;
// otherwise a global counter at +0x3fa of the block pointed at by 0x0380fff4
// is bumped and 1 is returned.

typedef struct Buf {
    unsigned short f00;
    unsigned short f02;
    unsigned short f04;
    unsigned short f06;
    unsigned short f08;
    unsigned short f0a;
    unsigned short f0c;
    unsigned short f0e;
} Buf;

typedef struct Ctx {
    char pad[8];
    Buf *buf;
} Ctx;

typedef struct Stats {
    char pad[0x3fa];
    unsigned short count;
} Stats;

int FUN_022d8e84(Ctx *s)
{
    unsigned short *p;
    Buf *b = s->buf;

    p = (unsigned short *)b - 2;
    if (p[0] == 0xb6b8 && p[1] == 0x1d46)
        return 0;

    b->f0a = 1;
    p[0] = 0xb6b8;
    p[1] = 0x1d46;
    b = s->buf;
    b->f0c = 0xb6b8;
    b->f0e = 0x1d46;
    (*(Stats **)0x0380fff4)->count++;
    return 1;
}
