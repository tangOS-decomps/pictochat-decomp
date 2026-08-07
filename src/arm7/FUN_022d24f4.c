// decomp: module=arm7 addr=0x022d24f4 name=FUN_022d24f4
// flags: -O4,s -noThumb

// Runs the type-0xd query for `req` and, when it comes back with status 1,
// allocates a reply block, fills in the request id and the returned value and
// posts it back to the ARM9.

typedef struct Req {
    int f0;
    int f4;
    int f8;
} Req;

typedef struct Msg {
    unsigned short f0;
    unsigned short f2;
    int f4;
    unsigned short f8;
    unsigned short fa;
} Msg;

extern int FUN_022d254c(Req *req, int mode, unsigned short *out);
extern void *func_037d14bc(void);
extern void func_037d1464(void *msg);

void FUN_022d24f4(Req *req)
{
    unsigned short out;
    unsigned short id = (unsigned short)req->f4;

    if (FUN_022d254c(req, 0, &out) == 1) {
        Msg *m = (Msg *)func_037d14bc();
        m->f0 = 0xd;
        m->f2 = 0;
        m->f8 = id;
        m->fa = out;
        func_037d1464(m);
    }
}
