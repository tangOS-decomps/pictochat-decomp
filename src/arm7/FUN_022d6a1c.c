// decomp: module=arm7 addr=0x022d6a1c name=FUN_022d6a1c
// flags: -O4,s -noThumb

// Whole-subsystem bring-up: publishes the caller's 0x694-byte context block as
// the global at 0x0380fff4, zeroes it, then fills in the timing/queue fields
// from the config record and starts every sub-driver in turn.  FUN_022e2d50
// decides between "already configured" (just set bit 7 of the +0x33e flags)
// and the full ten-call cold-start sequence.  Returns the +0x33e flag word.
//
// Every ctx field is reached through a fresh read of the global rather than a
// cached local - each store through the resulting pointer may alias the global
// itself, so mwcc reloads it and only the pool address stays in a register.

typedef struct Ctx {
    char pad0[0x18];
    char f18[0x304 - 0x18];
    int f304;
    void *f308;
    int f30c;
    unsigned int f310;
    int f314;
    char pad1[0x33e - 0x318];
    unsigned short f33e;
    char pad2[0x68c - 0x340];
    int f68c;
    unsigned char f690[2];
    unsigned char f692[2];
} Ctx;

typedef struct Config {
    Ctx *ctx;          /* +0x00 */
    int f04;           /* +0x04 */
    int f08;           /* +0x08 */
    int f0c;           /* +0x0c */
    void *f10;         /* +0x10 */
    int f14;           /* +0x14 */
    int f18;           /* +0x18 */
    unsigned int f1c;  /* +0x1c */
    char f20[0xc];     /* +0x20 */
    int f2c;           /* +0x2c */
    unsigned int f30;  /* +0x30 */
} Config;

extern void FUN_037cb7d4(int value, void *dst, unsigned int size);
extern int FUN_037c939c(void);
extern unsigned int FUN_037c8a00(unsigned int a, unsigned int b);
extern void FUN_037c9818(void *a, void *b, int c, int d, int e, int f);
extern void FUN_037c9b30(void *a);

extern void FUN_022d6ca8(void *p);
extern void FUN_022e2f20(void);
extern void FUN_022e2e4c(int index, int n, unsigned char *dst);
extern void FUN_022d6e18(int a, unsigned int b);
extern int FUN_022e2d50(void *p);

extern void FUN_022d6c00(void);
extern void FUN_022da700(void);
extern void FUN_022dc0cc(void);
extern void FUN_022da490(void);
extern void FUN_022d8984(void);
extern void FUN_022d86ec(void);
extern void FUN_022d923c(void);
extern void FUN_022d7db8(void);
extern void FUN_022d875c(void);
extern void FUN_022d87fc(void);
extern void FUN_022d93e0(void);
extern void FUN_022d956c(void);
extern void FUN_022d8794(void);
extern void FUN_022d77ec(void);
extern void FUN_022d7d30(void);
extern void FUN_022d98d8(void);

#define G_0380fff4 (*(Ctx **)0x0380fff4)

unsigned short FUN_022d6a1c(Config *cfg)
{
    Ctx *ctx = cfg->ctx;
    int probe;

    G_0380fff4 = ctx;
    FUN_037cb7d4(0, ctx, 0x694);

    G_0380fff4->f314 = FUN_037c939c();
    G_0380fff4->f30c = cfg->f18;
    G_0380fff4->f310 = cfg->f1c >> 1;
    if (G_0380fff4->f310 == 0) {
        G_0380fff4->f310 = (unsigned int)-1;
    }

    FUN_022d6ca8(cfg->f20);
    FUN_022e2f20();

    *(volatile unsigned short *)0x04000304 |= 2;
    *(volatile unsigned short *)0x04000206 = 0x30;

    G_0380fff4->f68c = 3;
    FUN_022e2e4c(0x3c, 2, G_0380fff4->f692);
    FUN_022e2e4c(0x3e, 2, G_0380fff4->f690);

    G_0380fff4->f308 = cfg->f10;
    G_0380fff4->f304 = cfg->f14;

    FUN_022d6e18(cfg->f2c, FUN_037c8a00(cfg->f30, 0x1c));

    FUN_022d6c00();
    FUN_022da700();
    FUN_022dc0cc();
    FUN_022da490();
    FUN_022d8984();

    if (FUN_022e2d50(&probe) != 0) {
        G_0380fff4->f33e |= 0x80;
    } else {
        FUN_022d86ec();
        FUN_022d923c();
        FUN_022d7db8();
        FUN_022d875c();
        FUN_022d87fc();
        FUN_022d93e0();
        FUN_022d956c();
        FUN_022d8794();
        FUN_022d77ec();
        FUN_022d7d30();
    }

    FUN_037c9818(G_0380fff4->f18, (void *)0x037f8820, 0, cfg->f04, cfg->f08,
                 cfg->f0c);
    FUN_037c9b30(G_0380fff4->f18);
    FUN_022d98d8();

    return G_0380fff4->f33e;
}
