// decomp: module=arm7 addr=0x022d6368 name=FUN_022d6368
// flags: -O4,s -noThumb
// size: 0xac - the nominal 0xa8 excludes the trailing pool word (0x023190dc).

// Handles the "disconnect" step of the connection state machine.
//
// If the connection block (G_023190dc + 0x550) is not in state 2 the request is
// refused with reply (6, 3). Otherwise the current link info is fetched into a
// 0x200-byte scratch buffer; if it still reports a peer count at +4 the reply is
// (6, 1, 0x301, count), else the block drops to state 1 and the reply is (6, 0).

typedef struct ConnMgr {
    char pad[0x550];
    unsigned short *conn; /* +0x550 */
} ConnMgr;

typedef struct LinkInfo {
    unsigned char pad[4];
    unsigned short peers; /* +0x4 */
} LinkInfo;

extern ConnMgr G_023190dc;

// FUN_022d08bc is declared void in src/arm7/FUN_022d08bc.c; this call site
// consumes its r0, which is the pointer its own tail call leaves behind.
extern LinkInfo *FUN_022d08bc(void *buf);
extern unsigned short *FUN_037d14bc(void);
extern void FUN_037d1464(void);

void FUN_022d6368(void)
{
    unsigned char buf[0x200];
    unsigned short *conn;
    LinkInfo *info;
    unsigned short *msg;

    conn = G_023190dc.conn;
    if (conn[0] != 2) {
        msg = FUN_037d14bc();
        msg[0] = 6;
        msg[1] = 3;
        FUN_037d1464();
        return;
    }

    info = FUN_022d08bc(buf);
    if (info->peers != 0) {
        msg = FUN_037d14bc();
        msg[0] = 6;
        msg[1] = 1;
        msg[2] = 0x301;
        msg[3] = info->peers;
        FUN_037d1464();
    } else {
        conn[0] = 1;
        msg = FUN_037d14bc();
        msg[0] = 6;
        msg[1] = 0;
        FUN_037d1464();
    }
}
