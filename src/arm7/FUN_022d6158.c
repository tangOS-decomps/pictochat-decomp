// decomp: module=arm7 addr=0x022d6158 name=FUN_022d6158
// flags: -O4,s -noThumb

// Runs the radio bring-up sequence against a 0x200-byte command buffer: each
// stage is issued through its own helper and, if the helper reports a non-zero
// status, the caller gets the stage tag in *stage and the raw status in *status
// and the whole thing fails. Success caches the calibration values into the
// block at G_023190dc.block and returns 1.

typedef struct Rsp {
    unsigned char pad00[4];
    unsigned short status;      /* 0x04 */
    unsigned short f06;         /* 0x06 */
    unsigned char pad08[6];
    unsigned short f0e;         /* 0x0e */
    unsigned short f10;         /* 0x10 */
    unsigned short f12;         /* 0x12 */
    unsigned short f14;         /* 0x14 */
} Rsp;

typedef struct Root {
    unsigned char pad000[0x550];
    unsigned char *block;       /* 0x550 */
} Root;

extern Root G_023190dc;

extern Rsp *FUN_022d0904(void *buf);
extern Rsp *FUN_022d08d4(void *buf);
extern Rsp *FUN_022d0890(void *buf);
extern void FUN_022d061c(void *buf, int a, int b, int c);
extern Rsp *FUN_022d0930(void *buf);
extern Rsp *FUN_022d0878(void *buf);
extern Rsp *FUN_022d06e0(void *buf, int a);

extern unsigned short FUN_037d1510(unsigned int v);
extern void FUN_037cb78c(void *src, void *dst, int n);
extern void FUN_037cb8b4(void *src, void *dst, int n);

int FUN_022d6158(unsigned short *stage, unsigned short *status)
{
    unsigned char buf[0x200];
    Rsp *r;
    unsigned char *base;
    unsigned short *reg;
    unsigned int chan;

    base = G_023190dc.block;

    r = FUN_022d0904(buf);
    if (r->status != 0) {
        *stage = 0x304;
        *status = r->status;
        return 0;
    }

    r = FUN_022d08d4(buf);
    if (r->status != 0) {
        *stage = 0x302;
        *status = r->status;
        return 0;
    }

    reg = (unsigned short *)0x04808124;
    reg[0] = 0xc8;
    reg[2] = 0x7d0;
    reg[0x16] = 0x202;

    r = FUN_022d0890(buf);
    if (r->status != 0) {
        *stage = 0x283;
        *status = r->status;
        return 0;
    }

    chan = r->f06;
    *(unsigned short *)(base + 0x1f4) = (unsigned short)chan;
    *(unsigned short *)(base + 0x1f6) = FUN_037d1510((chan << 15) >> 16);

    FUN_022d061c(buf, 0xffff, 0x28, 5);
    *(int *)(base + 0x7b8) = 0x001ff621;
    *(int *)(base + 0x7bc) = 0;
    *(unsigned short *)(base + 0x1ec) = 2;
    *(unsigned short *)(base + 0x1ee) = 1;

    r = FUN_022d0930(buf);
    if (r->status != 0) {
        *stage = 0x306;
        *status = r->status;
        return 0;
    }
    FUN_037cb78c((unsigned char *)r + 6, base + 0x20, 8);
    *(unsigned short *)(base + 0x28) = r->f0e;
    *(unsigned short *)(base + 0x2c) = r->f10;
    *(unsigned short *)(base + 0x2e) = r->f12;
    *(unsigned short *)(base + 0x2a) = r->f14;

    r = FUN_022d0878(buf);
    if (r->status != 0) {
        *stage = 0x281;
        *status = r->status;
        return 0;
    }
    FUN_037cb8b4((unsigned char *)r + 6, base + 0xe0, 6);

    r = FUN_022d06e0(buf, 1);
    if (r->status != 0) {
        *stage = 0x215;
        *status = r->status;
        return 0;
    }
    return 1;
}
