// decomp: module=arm7 addr=0x022cfcfc name=FUN_022cfcfc
// flags: -O4,s -noThumb
//
// The ARM7 command-message pump: blocks on the message queue at
// G_023180dc+0x88, dispatches each command through the 0x2e-entry handler
// table at 0x023162bc, and stamps bit 15 into the message id on the way out
// (the "handled" ack the sender polls for).  A NULL message means shutdown.

typedef struct Msg {
    unsigned short id;      // +0x00
} Msg;

typedef struct Ctx {
    char pad0[2];
    unsigned short cmd;     // +0x02  currently-dispatching command
    int busy;               // +0x04
} Ctx;

typedef struct ConnMgr {
    char pad[0x550];
    Ctx *ctx;               // +0x550
} ConnMgr;

typedef struct Queue {
    char pad[0x20];
} Queue;

typedef struct Mgr {
    char pad0[0x88];
    Queue queue;            // +0x88
} Mgr;

extern ConnMgr G_023190dc;
extern Mgr G_023180dc;
extern void (*G_023162bc[])(Msg *);

extern void func_037c9f1c(Queue *queue, Msg **out, int block);
extern void func_037c9920(void);

void FUN_022cfcfc(void)
{
    Ctx *ctx = G_023190dc.ctx;
    Mgr *mgr = &G_023180dc;
    Msg *msg;
    unsigned short cmd;

    for (;;) {
        func_037c9f1c(&mgr->queue, &msg, 1);
        if (msg == 0) {
            func_037c9920();
            break;
        }
        cmd = msg->id;
        if ((cmd & 0x8000) != 0) {
            cmd &= ~0x8000;
        }
        if (cmd < 0x2e) {
            ctx->busy = 1;
            ctx->cmd = cmd;
            G_023162bc[cmd](msg);
            ctx->busy = 0;
        }
        msg->id = cmd | 0x8000;
    }
}
