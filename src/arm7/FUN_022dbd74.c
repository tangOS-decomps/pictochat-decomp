// decomp: module=arm7 addr=0x022dbd74 name=FUN_022dbd74
// flags: -O4,s -noThumb
// size: 0xec - the stated 0xe8 excludes the trailing pool word (0x0380fff4).
//
// Allocates a 0x3a-byte type-0x87 message from the global pool at +0x188,
// copies the caller's 6-byte address into it, takes the payload length from
// src[1], then byte-copies up to 0x20 payload bytes across and zero-fills the
// remainder of the fixed-size payload field. Returns 1 on success; on an
// allocation failure it raises fault code 1 and returns 0.

typedef struct {
    unsigned char  pad00[0xc];
    unsigned short f0c;
    unsigned short f0e;
    unsigned char  f10[6];
    unsigned short f16;
    unsigned short f18;
    unsigned char  f1a[0x20];
} Msg;

typedef struct {
    unsigned char pad000[0x188];
    unsigned char f188[0x18];
} State;

extern State *G_0380fff4;

extern Msg *FUN_037c58fc(void *list, int size);
extern void FUN_037c5de8(void *list, Msg *m);
extern void FUN_022d9088(int code);
extern void FUN_022d811c(void *dst, const void *src);
extern unsigned char FUN_022d8d6c(const void *p);
extern void FUN_022d8d40(void *p, int v);

int FUN_022dbd74(const void *addr, unsigned short b, const unsigned char *src)
{
    Msg *m;
    unsigned int i;

    m = FUN_037c58fc(&G_0380fff4->f188, 0x3a);
    if (m == 0) {
        FUN_022d9088(1);
        return 0;
    }

    m->f0c = 0x87;
    m->f0e = 0x15;
    FUN_022d811c(m->f10, addr);
    m->f16 = b;
    m->f18 = FUN_022d8d6c(src + 1);

    for (i = 0; i < m->f18; i++) {
        if (i >= 0x20) {
            break;
        }
        FUN_022d8d40(&m->f1a[i], FUN_022d8d6c(src + 2 + i));
    }

    for (; i < 0x20; i++) {
        FUN_022d8d40(&m->f1a[i], 0);
    }

    FUN_037c5de8(&G_0380fff4->f188, m);
    return 1;
}
