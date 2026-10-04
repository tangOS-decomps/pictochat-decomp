// decomp: module=arm7 addr=0x022c1ce4 name=FUN_022c1ce4
// flags: -O4,s -noThumb
//
// Wireless pre-TBTT/beacon interrupt (ARM7 side). Acks the interrupt, then by
// MAC mode (+0x350): in parent mode (1) patches the beacon's TIM/counter
// bytes from 0x0380fff0, advances the beacon timer and refreshes the TX
// enable state from the MAC status; in child modes (2/3) re-arms the
// listen-interval countdowns, chooses whether the receiver stays awake and
// kicks any TX queue (0/1) that has a frame ready.

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define REG16(a) (*(volatile u16 *)(a))
#define CTX (*(u8 **)0x0380fff4)

typedef struct Frame {
    u8 pad0[8];
    u16 busy;           /* +0x8 */
} Frame;

typedef struct Queue {
    u16 count;          /* +0x00 */
    u16 pad2;
    u32 f4;
    u16 *buf;           /* +0x08 */
    Frame *frame;       /* +0x0c */
    const void *desc;   /* +0x10 */
} Queue;

typedef struct Queues {
    Queue q[7];         /* +0x00 */
    u32 f8c;            /* +0x8c */
    u8 pad90[0xae - 0x90];
    u16 txCount;        /* +0xae */
} Queues;

typedef struct Cfg {
    u8 pad0[8];
    u16 f08;            /* +0x08 */
    u16 pad0a;
    u16 mode;           /* +0x0c */
    u16 f0e;            /* +0x0e */
    u8 pad10[2];
    u16 f12;            /* +0x12 */
    u16 f14;            /* +0x14 */
    u8 pad16[4];
    u16 f1a;            /* +0x1a */
    u8 pad1c[0x70 - 0x1c];
    u16 f70;            /* +0x70 */
    u16 f72;            /* +0x72 */
    u16 f74;            /* +0x74 */
    u16 f76;            /* +0x76 */
    u8 pad78[0x96 - 0x78];
    u16 f96;            /* +0x96 */
} Cfg;

typedef struct Ctx {
    u8 pad0[0x31c];
    u8 x[0x28];         /* +0x31c */
    Cfg cfg;            /* +0x344 */
    u8 pad3de[0x42c - 0x344 - sizeof(Cfg)];
    Queues qs;          /* +0x42c */
} Ctx;

#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))

extern void FUN_00dd4560(u8 *dst, int value);
extern void FUN_00dd3510(int a);
extern int FUN_00dd9ab8(Frame *frame);
extern void FUN_00dda510(int queue);
extern void FUN_022c2e40(void);
extern void FUN_022c0e48(int a, int b);

void FUN_022c1ce4(void)
{
    Ctx *ctx;
    Cfg *cfg;
    u8 *x;
    Queues *qs;
    u8 *bcn;
    u16 v;
    u16 st;
    int awake;
    u32 i;
    Queue *q;

    ctx = (Ctx *)CTX;
    REG16(0x04808010) = 0x4000;
    cfg = &ctx->cfg;
    x = ctx->x;
    qs = &ctx->qs;
    switch (cfg->mode) {
    case 1:
        bcn = (u8 *)qs->q[6].buf + 0x24 + cfg->f96;
        v = *(u16 *)0x0380fff0;
        FUN_00dd4560(bcn + 8, v & 0xff);
        FUN_00dd4560(bcn + 9, ((u32)v >> 8) & 0xff);
        if (cfg->f0e == 1)
            REG16(0x04808134) = U16(x, 0x20) + REG16(0x04808134) + 1;
        U16(CTX, 0x530) = ~U16(CTX, 0x52e) | U16(CTX, 0x532);
        st = REG16(0x048080b6);
        if ((st & 0x18) || (st & 6) == 2) {
            qs->f8c &= ~2;
            FUN_022c2e40();
        } else {
            qs->f8c |= 2;
        }
        break;
    case 2:
        if (cfg->f12 == 0)
            REG16(0x04808134) = 0xffff;
        else
            REG16(0x04808134) = U16(x, 0x20) + REG16(0x04808134) + 1;
        if (cfg->f1a == 2)
            FUN_00dd3510(2);
    case 3:
        if (cfg->f08 != 0x40) {
            awake = 1;
        } else {
            awake = 0;
            if (cfg->f72 == 1)
                awake = 1;
            if (cfg->f14 != 0) {
                if (cfg->f76 == 1 || (cfg->f76 == 0 && cfg->f74 == 1))
                    awake = 1;
            }
        }
        if (awake)
            REG16(0x04808038) |= 1;
        else
            REG16(0x04808038) &= ~1;
        if (REG16(0x04808118) > 10)
            REG16(0x04808048) = 0;
        cfg->f72--;
        if (cfg->f72 == 0)
            cfg->f72 = cfg->f70;
        if (cfg->f76-- == 0)
            cfg->f76 = cfg->f74 - 1;
        for (i = 0; i < 2; i++) {
            q = &qs->q[i];
            if (q->count != 0 && q->frame->busy == 0 && FUN_00dd9ab8(q->frame) != 0) {
                FUN_00dda510(i);
                *q->buf = 2;
                FUN_022c0e48(0, 0xe);
                qs->txCount++;
            }
        }
        REG16(0x048080ae) = 0xd;
        break;
    }
}
