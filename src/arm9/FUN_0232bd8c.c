// decomp: module=unk_autoload_0 addr=0x0232bd8c name=FUN_0232bd8c

// Kicks off the next queued request of the comm state at G_023bd814: with
// interrupts off it claims the state (busy = 2, result = -1), cancels a
// pending timer, and pops the head request out of the queue at +0x50. If the
// request names a channel, the channel must be enabled in the system mask at
// +0x86; otherwise the request is dropped and, when the queue is not empty,
// the next one is tried right away. The request is then sent with
// FUN_0232bf8c as its completion callback.

typedef unsigned char u8;
typedef unsigned short u16;

struct Request {
    /* 0x00 */ u16 state;
    /* 0x02 */ u16 pad02;
    /* 0x04 */ u8 channel;
    /* 0x05 */ u8 pad05[3];
    /* 0x08 */ int arg;
};

struct Comm {
    /* 0x00 */ u16 channel;
    /* 0x02 */ u8 pad02[0xa];
    /* 0x0c */ struct Request *req;
    /* 0x10 */ int unk10;
    /* 0x14 */ int phase;
    /* 0x18 */ int arg;
    /* 0x1c */ int unk1c;
    /* 0x20 */ int result;
    /* 0x24 */ u8 pad24[8];
    /* 0x2c */ int timer;
    /* 0x30 */ u8 pad30[8];
    /* 0x38 */ int busy;
};

struct System {
    u8 pad[0x86];
    u16 channels;
};

extern struct Comm G_023bd814;
extern char G_023bd864[]; /* request queue inside G_023bd814 */

extern int FUN_02332080(void);
extern void FUN_02332094(int);
extern int FUN_0232b834(void *);
extern void FUN_0232b7ec(void *, void *, int);
extern void FUN_02332274(void);
extern struct System *FUN_02329978(void);
extern void FUN_0232c100(int, void *, int, int, void (*)(void));
extern void FUN_0232becc(void);
extern void FUN_0232bf8c(void);

void FUN_0232bd8c(void)
{
    int irq;
    u16 mask;
    struct Request *req;

    irq = FUN_02332080();
    if (FUN_0232b834(G_023bd864) == 0 && G_023bd814.busy == 0) {
        G_023bd814.busy = 2;
        G_023bd814.result = -1;
        if (G_023bd814.timer != 0)
            FUN_02332274();
        G_023bd814.timer = 1;
        FUN_0232b7ec(G_023bd864, G_023bd814.req, 0x14);
        FUN_02332094(irq);
        G_023bd814.req->state = 1;
        if (G_023bd814.req->channel != 0) {
            mask = 1 << G_023bd814.req->channel;
            if ((FUN_02329978()->channels & mask) == mask) {
                req = G_023bd814.req;
                G_023bd814.channel = req->channel;
                G_023bd814.arg = req->arg;
                FUN_0232c100(0xd, req, 0x14, 0xffff, FUN_0232bf8c);
            } else {
                G_023bd814.timer = 0;
                if (FUN_0232b834(G_023bd864) == 0) {
                    G_023bd814.busy = 0;
                    FUN_0232bd8c();
                } else {
                    G_023bd814.busy = 0;
                    G_023bd814.result = -1;
                }
            }
        } else {
            FUN_0232c100(0xd, G_023bd814.req, 0x14, 0xffff, FUN_0232bf8c);
            if (G_023bd814.phase == 1) {
                G_023bd814.phase = 2;
                G_023bd814.channel = 0;
                FUN_0232becc();
            }
        }
    } else {
        FUN_02332094(irq);
    }
}
