// decomp: module=arm7 addr=0x022dab00 name=FUN_022dab00
// flags: -O4,s -noThumb
//
// Request validator/launcher: sanity-checks a request block, and on success
// parks it (plus its reply block) in the pending-command slot at +0x404,
// raises command 0x30, copies the request's +0x10 block into the reply at +8,
// and kicks the worker.  Returns an error code (0xb wrong state, 1 not ready,
// 5 bad parameters) or 0x80 on success.

typedef struct Req {
    char pad0[0x10];
    unsigned short f10;     // +0x10  flags; also the head of the block copied out
    char pad1[4];
    unsigned short f16;     // +0x16
    unsigned short f18;     // +0x18
} Req;

typedef struct Rep {
    char pad0[2];
    unsigned short f2;      // +0x02
    char pad1[4];
    unsigned char buf[6];   // +0x08
    unsigned short fe;      // +0x0e
} Rep;

typedef struct Pool {
    char pad0[8];
    unsigned short avail;   // +0x08  (base +0x34c)
} Pool;

typedef struct Cmd {
    unsigned short cmd;     // +0x00  (base +0x404)
    char pad0[0x16];
    Req *req;               // +0x18  (base +0x41c)
    Rep *rep;               // +0x1c  (base +0x420)
} Cmd;

typedef struct Base {
    char pad0[0x32e];
    unsigned short state;   // +0x32e
    char pad1[0x14];
    Pool pool;              // +0x344
    char pad2[0xb6];
    Cmd cmd;                // +0x404
} Base;

extern Base *G_0380fff4;

extern void func_037c62c0(int n);
extern void FUN_022d811c(void *dst, void *src);
extern void FUN_022db560(void);

int FUN_022dab00(Req *req, Rep *rep)
{
    Base *g = G_0380fff4;
    Pool *pool = &g->pool;
    Cmd *cmd = &g->cmd;

    rep->f2 = 6;
    if (g->state != 3 && g->state != 2) {
        return 0xb;
    }
    if (pool->avail < 0x20) {
        return 1;
    }
    if ((req->f10 & 1) != 0) {
        return 5;
    }
    if (req->f16 > 1) {
        return 5;
    }
    if (req->f18 > 0x7d0) {
        return 5;
    }
    if (req->f18 < 0xa) {
        return 5;
    }

    func_037c62c0(0x20);
    cmd->req = req;
    cmd->rep = rep;
    cmd->cmd = 0x30;
    rep->fe = cmd->req->f16;
    FUN_022d811c(rep->buf, &cmd->req->f10);
    FUN_022db560();
    return 0x80;
}
