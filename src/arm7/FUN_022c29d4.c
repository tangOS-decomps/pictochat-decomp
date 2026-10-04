// decomp: module=arm7 addr=0x022c29d4 name=FUN_022c29d4
// flags: -O4,s -noThumb
// size: 0xf0 - the nominal 0xe4 excludes the three trailing pool words.
//
// TX-start interrupt (bit 0x1000). With a frame queued at +0x42c+0x3c, and
// when multi-poll is enabled (+0x690 bit 4), `mode` is non-zero, the RF state
// at 0x04808214 is 3 or 5 and nothing is pending at 0x048080b6, it arms the
// reply timeout: (peer count) * (per-peer time + 10) + 0xc0 + 4 * header,
// counting peers as the set bits of the frame's mask, and bumps the counter
// at +0x400. Otherwise event (0, 0x10) is reported.
//
// CALLEE NOTE: the timer `bl` decodes to 0x00dd43a0 (placeholder name, as in
// FUN_022c22b0); its second argument is the ARM7 runtime address 0x037fa998.

typedef unsigned short u16;
typedef volatile unsigned short vu16;

typedef struct Frame {
    u16 f00;
    u16 mask;       /* +0x02 */
    char pad04[6];
    u16 hdr;        /* +0x0a */
    char pad0c[0x18];
    u16 perPeer;    /* +0x24 */
} Frame;

typedef struct Ctx {
    char pad00[0x3c];
    u16 f3c;
    char pad3e[6];
    Frame *f44;
} Ctx;

extern char G_037fa998[];
extern void FUN_00dd43a0(u16 time, void *cb);
extern void FUN_022c0e48(int a, int b);

#define ST (*(char **)0x0380fff4)

void FUN_022c29d4(int mode)
{
    vu16 *io = (vu16 *)0x04808010;
    Ctx *c = (Ctx *)(ST + 0x42c);
    int n;
    u16 m;
    u16 rf;
    u16 busy;
    Frame *f;

    io[0] = 0x1000;
    if (c->f3c == 0) {
        return;
    }
    if ((*(u16 *)(ST + 0x690) & 0x10) && mode != 0) {
        busy = io[0x53];
        rf = *(vu16 *)0x04808214;
        if ((rf == 3 || rf == 5) && busy == 0) {
            f = c->f44;
            n = 0;
            m = f->mask;
            while (m != 0) {
                n += m & 1;
                m >>= 1;
            }
            FUN_00dd43a0(n * (f->perPeer + 10) + 0xc0 + f->hdr * 4, G_037fa998);
            (*(u16 *)(ST + 0x400))++;
            return;
        }
    }
    FUN_022c0e48(0, 0x10);
}
