// decomp: module=arm7 addr=0x022cfc48 name=FUN_022cfc48
// flags: -O4,s -noThumb
// size: 0x90 - the stated 0x88 excludes the two trailing pool words.

// Sibling of FUN_022cfb24 for opcode 0x2c, with no payload word: clears the
// context's +0x5e/+0x60/+0x88 halfwords, then enqueues the packet on the 0x88
// queue; if the allocation or the enqueue fails and a connection is live, an
// error indication {0x80, 8, 0x16, 0x2c} is pushed instead.

typedef struct Ctxfc48 {
    char pad[0x5e];
    unsigned short f5e;  /* +0x5e */
    unsigned short f60;  /* +0x60 */
    char pad2[0x88 - 0x62];
    unsigned short f88;  /* +0x88 */
} Ctxfc48;

typedef struct Mgrfc48 {
    char pad[0x550];
    Ctxfc48 *ctx; /* +0x550 */
} Mgrfc48;

extern Mgrfc48 G_023190dc;
extern unsigned char G_023180dc[];

extern void *FUN_022ce718(void);
extern int func_037c9e90(void *q, void *pkt, int block);
extern void *func_037d14bc(void);
extern void func_037d1464(void *ind);

void FUN_022cfc48(void)
{
    unsigned char *base;
    Ctxfc48 *ctx;
    int *pkt;
    int r;

    pkt = (int *)FUN_022ce718();
    ctx = G_023190dc.ctx;
    r = 0;
    ctx->f5e = 0;
    ctx->f60 = 0;
    base = G_023180dc;
    ctx->f88 = 0;

    if (pkt != 0) {
        pkt[0] = 0x2c;
        r = func_037c9e90(base + 0x88, pkt, 0);
    }

    if (r == 0) {
        if (*(int *)(base + 0x1000 + 0x54c) != 0) {
            unsigned short *ind = (unsigned short *)func_037d14bc();
            ind[0] = 0x80;
            ind[1] = 8;
            ind[2] = 0x16;
            ind[3] = 0x2c;
            func_037d1464(ind);
        }
    }
}
