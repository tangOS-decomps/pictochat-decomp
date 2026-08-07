// decomp: module=arm7 addr=0x022d5d10 name=FUN_022d5d10
// flags: -O4,s -noThumb
//
// Records the caller's word at +4 into the session block's halfword at 0xf6,
// renders the block's +0xe8 record into a small scratch buffer, expands that
// into a larger one, then posts a type-0x21 message describing the result.
//
// func_037d14bc / func_037d1464 are the SDK message-slot acquire/commit pair
// (inferred from the call shape: the first returns the slot the code fills in,
// the second takes no arguments and closes it) - not verified elsewhere.

typedef struct Ctx {
    char pad[0xe8];
    unsigned char fe8[4];
    unsigned short fec;
    unsigned short fee;
    unsigned short ff0;
    unsigned short ff2;
    unsigned short ff4;
    unsigned short ff6;
} Ctx;

typedef struct Arg {
    char pad[4];
    int f04;
} Arg;

typedef struct Res {
    char pad[4];
    unsigned short f04;
} Res;

typedef struct Msg {
    unsigned short f00;
    unsigned short f02;
    unsigned short f04;
    unsigned short f06;
} Msg;

extern Ctx *G_023190dc[];
extern void FUN_022ce324(void *dst, void *src);
extern Res *FUN_022d07f4(void *dst, unsigned short len, void *src);
extern Msg *func_037d14bc(void);
extern void func_037d1464(void);

void FUN_022d5d10(Arg *a)
{
    char large[0x200];
    char small[0x80];
    Ctx *c = G_023190dc[0x154];
    Res *r;
    Msg *m;

    c->ff6 = (unsigned short)a->f04;
    FUN_022ce324(small, c->fe8);
    r = FUN_022d07f4(large, (unsigned short)(c->fec + 0x10), small);

    m = func_037d14bc();
    m->f00 = 0x21;
    if (r->f04 == 0) {
        m->f02 = 0;
    } else {
        m->f02 = 1;
        m->f04 = 0x245;
        m->f06 = r->f04;
    }
    func_037d1464();
}
