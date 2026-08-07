// decomp: module=arm7 addr=0x022d40d8 name=FUN_022d40d8
// flags: -O4,s -noThumb

// "Start" request for command 0x1c: takes the interrupt lock, bails out if the
// context's +0xce busy flag is already 1, otherwise sets it and releases the
// lock. Then allocates a packet slot (FUN_022ce718), stamps the 0x1c opcode
// and enqueues it on the 0x02318164 queue. If the allocation or the enqueue
// fails, the busy flag is rolled back and (when a connection is live) an
// error indication {0x80, 8, 0x16, 0x1c} is pushed instead.
//
// Same 0x023180dc-base sharing that FUN_022cfb24 could not steer, except here
// the base has two uses (+0x88 and +0x1000+0x54c) so CSE keeps it in r4 on
// its own. 0x023180dc + 0x154c is the same word as G_023190dc.f54c, but the
// ROM reaches it off the 0x023180dc pool word, so it is spelled that way.
//
// NOTE: verify with --size 0xb0, not 0xa8 - the stated bound excludes this
// function's own two trailing pool words.

typedef struct Ctx40d8 {
    char pad[0xce];
    unsigned short busy; /* +0xce */
} Ctx40d8;

typedef struct Mgr40d8 {
    char pad[0x550];
    Ctx40d8 *ctx; /* +0x550 */
} Mgr40d8;

extern Mgr40d8 G_023190dc;
extern unsigned char G_023180dc[];

extern int func_037cb520(void);  /* OS_DisableInterrupts */
extern void func_037cb534(int state); /* OS_RestoreInterrupts */
extern void *FUN_022ce718(void);
extern int func_037c9e90(void *q, void *pkt, int block);
extern void *func_037d14bc(void);
extern void func_037d1464(void *ind);

void FUN_022d40d8(void)
{
    unsigned char *base = G_023180dc;
    Ctx40d8 *ctx = G_023190dc.ctx;
    int state;
    int *pkt;
    int r;

    state = func_037cb520();
    if (ctx->busy == 1) {
        func_037cb534(state);
        return;
    }
    ctx->busy = 1;
    func_037cb534(state);

    pkt = (int *)FUN_022ce718();
    if (pkt != 0) {
        pkt[0] = 0x1c;
        r = func_037c9e90(base + 0x88, pkt, 0);
    } else {
        r = 0;
    }

    if (r == 0) {
        ctx->busy = 0;
        if (*(int *)(base + 0x1000 + 0x54c) != 0) {
            unsigned short *ind = (unsigned short *)func_037d14bc();
            ind[0] = 0x80;
            ind[1] = 8;
            ind[2] = 0x16;
            ind[3] = 0x1c;
            func_037d1464(ind);
        }
    }
}
