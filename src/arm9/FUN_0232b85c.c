// decomp: module=unk_autoload_0 addr=0x0232b85c name=FUN_0232b85c

// Initialises the comm state at G_023bd814: clears the phase/busy flags,
// resets the channel to 0xffff and the result to -1, allocates the transfer
// buffers through the installed allocator (when there is one), sets up the
// request queue and the receive ring, and registers the handlers for
// packet kinds 0xd and 0xe.

typedef unsigned short u16;

typedef void *(*Alloc)(int, int);

struct Comm {
    /* 0x00 */ u16 channel;
    /* 0x02 */ u16 pad02;
    /* 0x04 */ int unk04;
    /* 0x08 */ int ringSize;
    /* 0x0c */ void *req;
    /* 0x10 */ void *buf;
    /* 0x14 */ int phase;
    /* 0x18 */ char pad18[8];
    /* 0x20 */ int result;
    /* 0x24 */ char pad24[0xc];
    /* 0x30 */ void *data;
    /* 0x34 */ void *ctl;
    /* 0x38 */ int busy;
    /* 0x3c */ void *done;
};

extern struct Comm G_023bd814;
extern char G_023bd864[];
extern char G_023bd854[];
extern Alloc G_023bd5fc;

extern void FUN_0232b74c(void *, int, int);
extern void FUN_0232c8c0(int, void (*)(void *), int);
extern void FUN_0232bb1c(void *);
extern void FUN_0232bccc(void *);

void FUN_0232b85c(int size)
{
    G_023bd814.phase = 0;
    G_023bd814.busy = 0;
    G_023bd814.channel = 0xffff;
    G_023bd814.unk04 = 0;
    G_023bd814.done = 0;
    G_023bd814.result = -1;
    if (G_023bd5fc != 0) {
        G_023bd814.data = G_023bd5fc(size, 0x20);
        G_023bd814.ctl = G_023bd5fc(0xc0, 0x20);
        G_023bd814.req = G_023bd5fc(0xc0, 0x20);
        G_023bd814.buf = G_023bd5fc(0xc0, 0x20);
    }
    G_023bd814.ringSize = 0xc0;
    FUN_0232b74c(G_023bd864, 0x14, 0x40);
    FUN_0232b74c(G_023bd854, G_023bd814.ringSize, 0x40);
    FUN_0232c8c0(0xd, FUN_0232bb1c, 0);
    FUN_0232c8c0(0xe, FUN_0232bccc, 0);
}
