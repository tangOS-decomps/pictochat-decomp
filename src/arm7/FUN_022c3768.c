// decomp: module=arm7 addr=0x022c3768 name=FUN_022c3768
// flags: -O4,s -noThumb
//
// Wireless MAC queue setup. Clears the 0xb0-byte queue block at ctx+0x42c,
// then, per MAC variant (ctx+0x350), points each TX/RX queue at its buffer in
// MAC RAM (0x048040xx..) and its descriptor table, stamps the 0xB6B8/0x1D46
// marker words just below every buffer (and at the mirror +0x620 above queue
// 0), and programs the variant's config word (+0x8a of the block at 0x344)
// and RX control. Finally sets the 0x4000 flag when the block at 0x31c asks
// for it.

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define REG16(a) (*(volatile u16 *)(a))

typedef struct Queue {
    u16 count;          /* +0x00 */
    u16 pad2;
    u32 f4;
    u16 *buf;           /* +0x08 */
    u32 pos;            /* +0x0c */
    const void *desc;   /* +0x10 */
} Queue;

typedef struct Queues {
    Queue q[7];         /* +0x00 */
    u8 pad8c[0xa2 - 0x8c];
    u16 fa2;            /* +0xa2 */
    u16 fa4;            /* +0xa4 */
    u8 pada6[0xb0 - 0xa6];
} Queues;

typedef struct Ctx {
    u8 pad0[0x31c];
    u8 x[0x28];         /* +0x31c */
    u8 cfg[0xe8];       /* +0x344 */
    Queues qs;          /* +0x42c */
} Ctx;

#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))

extern const u8 G_023115c8[];
extern const u8 G_02311744[];
extern const u8 G_02311c10[];
extern const u8 G_02311c78[];

extern void FUN_022c6fc8(int value, void *dst, u32 size);
extern void FUN_00ddaa40(void);

void FUN_022c3768(void)
{
    Ctx *ctx;
    Queues *qs;
    u8 *cfg;
    u8 *x;

    ctx = *(Ctx **)0x0380fff4;
    qs = &ctx->qs;
    cfg = ctx->cfg;
    x = ctx->x;
    FUN_022c6fc8(0, qs, sizeof(Queues));
    ctx->qs.q[0].count = 0;
    qs->q[0].pos = 0;
    qs->q[1].count = 0;
    qs->q[1].pos = 0;
    qs->q[2].count = 0;
    qs->q[2].pos = 0;
    qs->fa2 = 0xffff;
    qs->fa4 = 0xffff;

    switch (U16(cfg, 0xc)) {
    case 0:
        qs->q[0].buf = (u16 *)0x04804170;
        qs->q[1].buf = (u16 *)0x04804028;
        qs->q[2].buf = (u16 *)0x04804000;
        qs->q[0].desc = G_023115c8;
        qs->q[1].desc = G_02311744;
        qs->q[2].desc = G_02311c10;
        REG16(0x04804024) = 0xb6b8;
        REG16(0x04804026) = 0x1d46;
        REG16(0x0480416c) = 0xb6b8;
        REG16(0x0480416e) = 0x1d46;
        REG16(0x04804790) = 0xb6b8;
        REG16(0x04804792) = 0x1d46;
        U16(cfg, 0x8a) = 8;
        REG16(0x048080ae) = 1;
        break;
    case 1:
        qs->q[0].buf = (u16 *)0x04804aa0;
        qs->q[1].buf = (u16 *)0x04804958;
        qs->q[2].buf = (u16 *)0x04804334;
        qs->q[0].desc = G_023115c8;
        qs->q[1].desc = G_02311744;
        qs->q[2].desc = G_02311c78;
        qs->q[6].buf = (u16 *)0x04804238;
        qs->q[3].buf = (u16 *)0x04804000;
        REG16(0x04804234) = 0xb6b8;
        REG16(0x04804236) = 0x1d46;
        REG16(0x04804330) = 0xb6b8;
        REG16(0x04804332) = 0x1d46;
        REG16(0x04804954) = 0xb6b8;
        REG16(0x04804956) = 0x1d46;
        REG16(0x04804a9c) = 0xb6b8;
        REG16(0x04804a9e) = 0x1d46;
        REG16(0x048050c0) = 0xb6b8;
        REG16(0x048050c2) = 0x1d46;
        U16(cfg, 0x8a) = 0x208;
        qs->q[6].buf = (u16 *)0x04804238;
        FUN_00ddaa40();
        break;
    case 2:
        qs->q[0].buf = (u16 *)0x048045d8;
        qs->q[1].buf = (u16 *)0x04804490;
        qs->q[2].buf = (u16 *)0x04804468;
        qs->q[0].desc = G_023115c8;
        qs->q[1].desc = G_02311744;
        qs->q[2].desc = G_02311c10;
        qs->q[4].buf = (u16 *)0x04804000;
        qs->q[5].buf = (u16 *)0x04804234;
        REG16(0x04804230) = 0xb6b8;
        REG16(0x04804232) = 0x1d46;
        REG16(0x04804464) = 0xb6b8;
        REG16(0x04804466) = 0x1d46;
        REG16(0x0480448c) = 0xb6b8;
        REG16(0x0480448e) = 0x1d46;
        REG16(0x048045d4) = 0xb6b8;
        REG16(0x048045d6) = 0x1d46;
        REG16(0x04804bf8) = 0xb6b8;
        REG16(0x04804bfa) = 0x1d46;
        U16(cfg, 0x8a) = 0x108;
        REG16(0x048080ae) = 0xd;
        break;
    case 3:
        qs->q[0].buf = (u16 *)0x04804170;
        qs->q[1].buf = (u16 *)0x04804028;
        qs->q[2].buf = (u16 *)0x04804000;
        qs->q[0].desc = G_023115c8;
        qs->q[1].desc = G_02311744;
        qs->q[2].desc = G_02311c10;
        REG16(0x04804024) = 0xb6b8;
        REG16(0x04804026) = 0x1d46;
        REG16(0x0480416c) = 0xb6b8;
        REG16(0x0480416e) = 0x1d46;
        REG16(0x04804790) = 0xb6b8;
        REG16(0x04804792) = 0x1d46;
        U16(cfg, 0x8a) = 0x108;
        REG16(0x048080ae) = 0xd;
        break;
    }
    if (U16(x, 0x18) != 0)
        U16(cfg, 0x8a) |= 0x4000;
}
