// decomp: module=unk_autoload_0 addr=0x0232bb9c name=FUN_0232bb9c

// Receives one slice of a bulk transfer: copies the slice header and payload
// into the transfer buffer at its cursor. A child acks a new cursor once
// (queueing later packets in the receive ring, dropping the link if it is
// full); the parent records the cursor and, on the last slice, finishes the
// transfer, notifying the owner and resetting channel and cursor.

typedef unsigned char u8;
typedef unsigned short u16;

struct Hdr {
    u16 kind;
    u16 len;
    u8 chan;
    u8 pad05;
    u8 slice;
    u8 last;
    int cursor;
};

struct Packet {
    char pad00[0xc];
    void *data;     /* 0x0c */
    u16 len;        /* 0x10 */
};

struct Comm {
    /* 0x00 */ u16 channel;
    /* 0x02 */ char pad02[0xe];
    /* 0x10 */ void *buf;
    /* 0x14 */ int phase;
    /* 0x18 */ int arg;
    /* 0x1c */ int pad1c;
    /* 0x20 */ int cursor;
    /* 0x24 */ int acked;
    /* 0x28 */ char pad28[8];
    /* 0x30 */ char *data;
    /* 0x34 */ int pad34;
    /* 0x38 */ int busy;
    /* 0x3c */ void (*done)(int, void *, int);
};

extern struct Comm G_023bd814;
extern char G_023bd854[];

extern void FUN_02337584(const void *src, void *dst, int len);
extern int FUN_0232a4e8(void);
extern int FUN_0232b794(void *, void *, int);
extern void FUN_0232a480(void);
extern void FUN_02329bd8(int);
extern void FUN_0232be80(u8);
extern void FUN_0232c100(int, void *, u16, int, void *);
extern void FUN_0232bf8c(void *);

void FUN_0232bb9c(struct Packet *pkt)
{
    struct Hdr hdr;

    if (pkt->len == 0)
        return;
    FUN_02337584(pkt->data, &hdr, 0xc);
    FUN_02337584((char *)pkt->data + 0xc, G_023bd814.data + hdr.cursor, hdr.slice);
    if (FUN_0232a4e8() == 0) {
        if (G_023bd814.cursor == hdr.cursor)
            return;
        G_023bd814.cursor = hdr.cursor;
        if (G_023bd814.acked == 0) {
            G_023bd814.acked = 1;
            FUN_02337584(pkt->data, G_023bd814.buf, pkt->len);
            FUN_0232c100(0xe, G_023bd814.buf, pkt->len, 0xffff, FUN_0232bf8c);
            return;
        }
        if (FUN_0232b794(G_023bd854, pkt->data, pkt->len) == 0) {
            FUN_0232a480();
            FUN_02329bd8(0xc);
        }
        return;
    }
    G_023bd814.cursor = hdr.cursor;
    if (hdr.last != 1)
        return;
    if (G_023bd814.channel == 0xffff)
        return;
    if (hdr.chan == FUN_0232a4e8()) {
        if (G_023bd814.phase == 2)
            G_023bd814.phase = 0;
        FUN_0232be80(1);
    }
    if (G_023bd814.done != 0)
        G_023bd814.done(G_023bd814.channel, G_023bd814.data, G_023bd814.arg);
    G_023bd814.channel = 0xffff;
    G_023bd814.cursor = -1;
}
