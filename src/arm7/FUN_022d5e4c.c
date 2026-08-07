// decomp: module=arm7 addr=0x022d5e4c name=FUN_022d5e4c
// flags: -noThumb

// Installs the work area described by the init block: the context and its
// buffer are published into the global manager, wired into each other, then the
// remaining setup is handed to FUN_022d5e9c and a type-3 message is posted to
// the ARM9.

typedef struct Ctx {
    void *f0;
    char pad[4];
    void *f8;
} Ctx;

typedef struct Init {
    char pad[4];
    Ctx *f4;
    void *f8;
    void *fc;
    int f10;
} Init;

typedef struct Mgr {
    char pad[0x54c];
    Ctx *f54c;
    void *f550;
} Mgr;

extern Mgr G_023190dc;
extern void FUN_022d5e9c(int);
extern unsigned short *FUN_037d14bc(void);
extern void FUN_037d1464(void);

void FUN_022d5e4c(Init *init) {
    unsigned short *msg;
    void *buf;
    Ctx *ctx = init->f4;
    G_023190dc.f54c = ctx;
    buf = init->f8;
    G_023190dc.f550 = buf;
    ctx->f0 = buf;
    ctx->f8 = init->fc;
    FUN_022d5e9c(init->f10);
    msg = FUN_037d14bc();
    msg[0] = 3;
    msg[1] = 0;
    FUN_037d1464();
}
