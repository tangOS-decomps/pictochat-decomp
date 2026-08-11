// decomp: module=unk_autoload_0 addr=0x0232bf8c name=FUN_0232bf8c

// Completion callback for the bulk-transfer channel. On a data ack it either
// re-sends the queued control block, finishes the transfer (notifying the
// owner and resetting the cursor), or ships the next slice; on the control
// opcode it clears the pending flag and lets the idle path run again.

typedef unsigned short u16;
typedef unsigned char u8;

struct Hdr {
    u16 kind;
    u16 len;
    u8 chan;
    u8 pad05;
    u8 slice;
    u8 last;
    int cursor;
};

struct Msg {
    char pad00[0xa];
    u16 kind;       /* 0x0a */
    char pad0c[8];
    void *data;     /* 0x14 */
};

struct Ctx {
    char pad00[0xc];
    void *peer;     /* 0x0c */
    void *buf;      /* 0x10 */
    int state;      /* 0x14 */
    char pad18[4];
    int cursor;     /* 0x1c */
    int base;       /* 0x20 */
    int resend;     /* 0x24 */
    volatile int end;   /* 0x28 */
    int pending;    /* 0x2c */
    char pad30[8];
    volatile int flag;  /* 0x38 */
    void (*done)(int, void *, int);  /* 0x3c */
};

extern struct Ctx G_023bd814;   /* pool 0x0232c084 */
extern char G_023bd854[];       /* pool 0x0232c088 */
extern char *G_02369d04;        /* pool 0x0232c094 */

extern int FUN_0232b834(void *);
extern void FUN_0232b7ec(void *, void *, int);
extern void FUN_02337584(const void *src, void *dst, int len);
extern void FUN_0232c100(int, void *, u16, int, void *);
extern int FUN_0232a4e8(void);
extern void FUN_0232bd8c(void);
extern void FUN_0232becc(void);

void FUN_0232bf8c(struct Msg *msg)
{
    struct Hdr hdr;

    if (msg->kind == 0xe) {
        if (G_023bd814.resend != 0) {
            G_023bd814.resend = 0;
            if (FUN_0232b834(G_023bd854) != 0)
                return;
            G_023bd814.resend = 1;
            FUN_0232b7ec(G_023bd854, G_023bd814.buf, 0xac);
            FUN_02337584(G_023bd814.buf, &hdr, 0xc);
            FUN_0232c100(0xe, G_023bd814.buf, 0xac, 0xffff, (void *)FUN_0232bf8c);
            return;
        }
        if (G_023bd814.end == G_023bd814.cursor && G_023bd814.end != 0 &&
            FUN_0232a4e8() == 0 && G_023bd814.state == 2) {
            if (G_023bd814.done != 0)
                G_023bd814.done(0, G_02369d04, G_023bd814.end);
            if (G_023bd814.pending != 0)
                G_023bd814.flag = 3;
            else
                G_023bd814.flag = 0;
            G_023bd814.state = 0;
            G_023bd814.end = 0;
            G_023bd814.cursor = 0;
            G_023bd814.base = -1;
            FUN_0232bd8c();
            return;
        }
        if (FUN_0232a4e8() == 0) {
            FUN_02337584(msg->data, &hdr, 0xc);
            G_023bd814.base = hdr.cursor;
        }
        FUN_0232becc();
        return;
    }

    if (msg->kind != 0xd)
        return;
    if (msg->data != G_023bd814.peer)
        return;
    G_023bd814.pending = 0;
    if (G_023bd814.flag != 3)
        return;
    if (FUN_0232a4e8() != 0)
        return;
    G_023bd814.flag = 0;
    FUN_0232bd8c();
}
