// decomp: module=arm7 addr=0x022d37d4 name=FUN_022d37d4
// flags: -O4,s -noThumb
// size: 0x124 - the nominal 0x118 excludes the three trailing pool words.
// Matches under 2.0/sp2p2..sp2p4 only: sp1..sp2 cannot drop the zero high
// word of the (s64)(int)x * 0x82ea multiply (notes/setup-mwccarm.md).
//
// Handles request 0x1d. Builds the configuration frame from the request's
// first three words via FUN_022d061c; a non-zero status there is answered as
// (0x1d, 1, 0x211, status). Otherwise the keep-alive interval in the fourth
// word (in 100 ms units; 0xffff = never, 0 = immediately) is converted to
// ticks at +0x7b8, all 16 per-peer deadlines at +0x738 are reset to the
// current tick (forced odd so they are never 0), and (0x1d, 0) is indicated.

typedef unsigned short u16;
typedef unsigned long long u64;

typedef struct Req {
    int f00;
    int a;
    int b;
    int c;
    int interval;
} Req;

typedef struct Blk37d4 {
    char pad000[0x738];
    u64 deadline[16];   /* +0x738 */
    u64 interval;       /* +0x7b8 */
} Blk37d4;

extern Blk37d4 *G_023190dc[];
extern u16 *FUN_037d14bc(void);
extern void FUN_037d1464(u16 *ind);
extern u16 *FUN_022d061c(u16 *buf, u16 a, u16 b, u16 c);
extern u64 FUN_037caa3c(void);

void FUN_022d37d4(Req *req)
{
    u16 buf[0x100];
    Blk37d4 *b = G_023190dc[0x154];
    u16 interval = req->interval;
    u16 status;
    u16 *ind;
    u64 now;
    int i;

    status = FUN_022d061c(buf, req->a, req->b, req->c)[2];
    if (status != 0) {
        ind = FUN_037d14bc();
        ind[0] = 0x1d;
        ind[1] = 1;
        ind[2] = 0x211;
        ind[3] = status;
        FUN_037d1464(ind);
        return;
    }

    if (interval != 0xffff) {
        b->interval = (interval == 0) ? 1 : (u64)(interval * 100) * 33514 / 64;
    } else {
        b->interval = 0;
    }

    now = FUN_037caa3c() | 1;
    for (i = 0; i < 16; i++) {
        b->deadline[i] = now;
    }

    ind = FUN_037d14bc();
    ind[0] = 0x1d;
    ind[1] = 0;
    FUN_037d1464(ind);
}
