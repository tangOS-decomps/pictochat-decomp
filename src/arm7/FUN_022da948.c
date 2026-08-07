// decomp: module=arm7 addr=0x022da948 name=FUN_022da948
// flags: -O4,s -noThumb
//
// Validates a beacon/configuration block before arming channel 1 of the block
// at 0x0380fff4. Every rejection answers through the one shared epilogue with a
// status code: 0xb when the driver is not in state 2 or 3, 1 when the free-slot
// count is below 0x20, 0xe when the busy probe reports non-zero, 5 for each
// field-range failure, and 0x80 once everything is programmed.
//
// FUN_022d84e0 is called with the 0x4a halfword still live in r0, so it is
// declared as taking it (inferred from register liveness at the bl, not
// verified against another call site).

typedef struct Cfg {
    char pad00[0x10];
    unsigned short f10;
    char pad12[0x18 - 0x12];
    unsigned short f18;
    char pad1a[0x1e - 0x1a];
    unsigned short f1e;
    unsigned char f20[0x40 - 0x20];
    unsigned short f40;
    unsigned short f42;
    unsigned short f44;
    unsigned short f46;
    unsigned short f48;
    unsigned short f4a;
} Cfg;

typedef struct Req {
    unsigned short f00;
    unsigned short f02;
} Req;

typedef struct Sub {
    char pad00[8];
    unsigned short f08;
} Sub;

typedef struct Chan {
    unsigned short state;
    char pad02[0x18 - 2];
    Cfg *cfg;
    Req *req;
    char pad20[0x32a - 0x20];
    unsigned short f32a;
    char pad32c[0x340 - 0x32c];
    Sub sub;
    char pad34a[0x400 - 0x34a];
} Chan;

typedef struct Root {
    char pad00[4];
    Chan chan[2];
} Root;

extern void func_037c62c0(int n);
extern void func_037c5628(int a, int b);
extern int FUN_022d84e0(unsigned short v);
extern int FUN_022e2d50(int n);
extern void FUN_022d72cc(int on);
extern void FUN_022d75a8(unsigned short *p);
extern void FUN_022d760c(unsigned short n, unsigned char *p);
extern void FUN_022d771c(unsigned short n);
extern void FUN_022d793c(unsigned short n, int flag);
extern void FUN_022d7bc8(unsigned short *p);

int FUN_022da948(Cfg *cfg, Req *req)
{
    Root *root = *(Root **)0x0380fff4;
    Chan *c = &root->chan[1];
    Sub *sub = &root->chan[0].sub;
    int st;

    req->f02 = 5;

    st = root->chan[0].f32a;
    if (st != 3 && st != 2)
        return 0xb;
    if (sub->f08 < 0x20)
        return 1;

    func_037c62c0(0x20);

    if (cfg->f18 & 1)
        return 5;
    if (cfg->f1e == 0)
        return 5;
    if (cfg->f1e > 0x20)
        return 5;
    if (cfg->f46 < 0xa)
        return 5;
    if (cfg->f46 > 0x3e8)
        return 5;
    if (cfg->f48 > 0xff)
        return 5;
    if (cfg->f4a & 0xfff0)
        return 5;
    if (FUN_022d84e0(cfg->f4a) == 0)
        return 5;
    if (cfg->f42 & -0x1000)
        return 5;
    if (cfg->f44 & -0x1000)
        return 5;
    if (cfg->f42 == 0)
        return 5;
    if ((cfg->f44 | cfg->f42) == 0)
        return 5;
    if (cfg->f10 > 0x7d0)
        return 5;
    if (FUN_022e2d50(0) != 0)
        return 0xe;

    if (cfg->f40 & 0x20)
        FUN_022d72cc(1);
    else
        FUN_022d72cc(0);

    FUN_022d75a8(&cfg->f18);
    FUN_022d760c(cfg->f1e, cfg->f20);
    FUN_022d771c(cfg->f46);
    FUN_022d793c(cfg->f4a, 0);
    FUN_022d7bc8(&cfg->f42);

    c->cfg = cfg;
    c->req = req;
    c->state = 0x20;
    func_037c5628(2, 1);
    return 0x80;
}
