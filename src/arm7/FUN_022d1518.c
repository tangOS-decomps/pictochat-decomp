// decomp: module=arm7 addr=0x022d1518 name=FUN_022d1518
// flags: -O4,s -noThumb
// NOTE: verify with --size 0x360, not funcs.json's 0x350 - Ghidra's boundary
// excludes this function's own trailing literal pool (the &G_023190dc word).
//
// Validates an incoming request against the channel state machine at
// 0x023190DC+0x550, builds an error response (opcode 0xa) and sends it via
// func_037d1464 on any rejection, otherwise walks a chain of parse/verify
// helpers (FUN_022d0960/FUN_022ce3e8/FUN_022d08ec/FUN_022cfdf8/FUN_022cfe58)
// and finally assembles a success response into a freshly allocated buffer
// and sends it.

extern void *func_037d14bc(void);
extern void func_037d1464(void *p);
extern void func_037cb8b4(void *a, void *b, int len);
extern void func_037cb774(int value, void *dst, int len);
extern void func_037cb820(void *dst, int value, int len);
extern void func_037cb78c(void *a, void *b, int len);
extern void *FUN_022d0960(void *p);
extern int FUN_022ce3e8(int a, void *p);
extern void *FUN_022d08ec(void *p);
extern void *FUN_022cfdf8(void *p, int a, int b, int c);
extern void *FUN_022cfe58(void *a, int b, void *c, int d, void *e, int f, void *g, unsigned short h);
extern void FUN_022d1dbc(int code, int val, int zero);
extern int FUN_022d1878(int a);
extern int FUN_022ce5f0(void);
extern void FUN_022d188c(int a);

typedef struct ConnMgrD1518 {
    char pad[0x550];
    unsigned char *conn;
} ConnMgrD1518;

extern ConnMgrD1518 G_023190dc;

void FUN_022d1518(void *arg0)
{
    unsigned char sp[0x238];
    void *r4 = sp + 0x38;
    unsigned short f2;
    unsigned short f8;
    unsigned char *req = (unsigned char *)arg0;
    unsigned char *ch = G_023190dc.conn;
    unsigned short state = *(unsigned short *)ch;

    if (state != 2 && state != 3 && state != 5) {
        void *p = func_037d14bc();
        *(unsigned short *)((char *)p + 0) = 0xa;
        *(unsigned short *)((char *)p + 2) = 3;
        *(unsigned short *)((char *)p + 8) = 4;
        func_037d1464(p);
        return;
    }

    *(unsigned int *)(ch + 0x184) = *(unsigned int *)(req + 4);
    f2 = *(unsigned short *)(req + 2);
    *(unsigned short *)(ch + 0x100 + 0x90) = f2;
    f8 = *(unsigned short *)(req + 8);

    func_037cb8b4(req + 0xa, sp + 0x00, 6);

    {
        unsigned short v = *(unsigned short *)(sp + 0x00);
        if (v == 0xffff) {
            /* leave as-is */
        } else if (v & 1) {
            *(unsigned short *)(sp + 0x00) = v & ~1;
        }
    }

    if (f2 == 0) {
        void *p = func_037d14bc();
        *(unsigned short *)((char *)p + 0) = 0xa;
        *(unsigned short *)((char *)p + 2) = 6;
        *(unsigned short *)((char *)p + 8) = 4;
        func_037d1464(p);
        return;
    }

    {
        unsigned short bits = *(unsigned short *)(ch + 0x100 + 0xf4);
        unsigned int mask = 1u << f2;
        if (!(mask & bits)) {
            void *p = func_037d14bc();
            *(unsigned short *)((char *)p + 0) = 0xa;
            *(unsigned short *)((char *)p + 2) = 6;
            *(unsigned short *)((char *)p + 8) = 4;
            func_037d1464(p);
            return;
        }
    }

    *(unsigned short *)(ch + 0xe6) = 2;

    {
        void *m = FUN_022d0960(r4);
        unsigned short e = *(unsigned short *)((char *)m + 4);
        if (e != 0) {
            FUN_022d1dbc(0x308, e, 0);
            return;
        }

        if (*(unsigned short *)((char *)m + 6) == 0x10) {
            if (!FUN_022ce3e8(0xa, r4))
                return;

            {
                void *m2 = FUN_022d08ec(r4);
                unsigned short e2 = *(unsigned short *)((char *)m2 + 4);
                if (e2 != 0) {
                    FUN_022d1dbc(0x303, e2, 0);
                    return;
                }
            }

            *(unsigned short *)ch = 3;

            {
                void *m3 = FUN_022cfdf8(r4, 1, 0, 1);
                unsigned short e3 = *(unsigned short *)((char *)m3 + 4);
                if (e3 != 0) {
                    FUN_022d1dbc(1, e3, 0);
                    return;
                }
            }

            *(unsigned short *)(ch + 0xc6) = 1;
        }
    }

    *(unsigned short *)ch = 5;

    func_037cb774(0xffff, sp + 0x16, 0x20);
    sp[0x06] = (unsigned char)f2;
    func_037cb820(sp + 0x07, 0, 0xf);

    r4 = FUN_022cfe58(r4, 0x11e, sp + 0x00, 0, sp + 0x16, 1, sp + 0x06, f8);

    if (*(unsigned short *)((char *)r4 + 4) != 0) {
        FUN_022d1dbc(2, *(unsigned short *)((char *)r4 + 4), 0);
        return;
    }

    void *r6 = func_037d14bc();
    if (*(unsigned short *)((char *)r4 + 8) == 0) {
        *(unsigned short *)((char *)r6 + 0) = 0xa;
        *(unsigned short *)((char *)r6 + 2) = 0;
        *(unsigned short *)((char *)r6 + 8) = 4;
        *(unsigned short *)((char *)r6 + 0x10) = f2;
        *(unsigned short *)((char *)r6 + 0x12) = 0;
        goto finish;
    }

    func_037cb774(0, *(char **)(ch + 0x184) + 0x40, 0x80);
    func_037cb8b4((char *)r4 + 0xa, *(void **)(ch + 0x184), *(unsigned short *)((char *)r4 + 0xa) << 1);

    *(unsigned short *)((char *)r6 + 0) = 0xa;
    *(unsigned short *)((char *)r6 + 2) = 0;
    *(unsigned short *)((char *)r6 + 8) = 5;
    *(unsigned short *)((char *)r6 + 0x10) = *(unsigned short *)((char *)r4 + 0x40);

    {
        int t = FUN_022d1878(*(unsigned short *)((char *)r4 + 0xc) & 0xff);
        *(unsigned short *)((char *)r6 + 0x12) = FUN_022ce5f0();
        FUN_022d188c(t);
    }

    *(unsigned short *)((char *)r6 + 0x14) = *(unsigned short *)((char *)r4 + 0x14);
    func_037cb8b4((char *)r4 + 0xe, (char *)r6 + 0xa, 6);
    func_037cb78c((char *)r4 + 0x16, (char *)r6 + 0x16, 0x20);

    {
        unsigned short len46 = *(unsigned short *)((char *)r4 + 0x46);
        *(unsigned short *)((char *)r6 + 0x36) = len46;

        if (len46 > 0x80) {
            *(unsigned short *)((char *)r6 + 0) = 0xa;
            *(unsigned short *)((char *)r6 + 2) = 0;
            *(unsigned short *)((char *)r6 + 8) = 4;
            *(unsigned short *)((char *)r6 + 0x10) = f2;
            *(unsigned short *)((char *)r6 + 0x12) = 0;
            goto finish;
        }

        func_037cb774(0, (char *)r6 + 0x38, 0x80);
        {
            unsigned short again = *(unsigned short *)((char *)r6 + 0x36);
            func_037cb78c((char *)r4 + 0x4a, (char *)r6 + 0x38, (again + 1) & ~1);
        }
    }

finish:
    func_037d1464(r6);
}
