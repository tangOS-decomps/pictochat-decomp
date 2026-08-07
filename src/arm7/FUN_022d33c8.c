// decomp: module=arm7 addr=0x022d33c8 name=FUN_022d33c8
// flags: -O4,s -noThumb
// NOTE: verify with --size 0xbc, not the nominal 0xb8 - the stated size
// excludes this function's own trailing pool word.
//
// "Disconnect" request handler. Only legal while the connection block is in
// state 0xb; otherwise it answers immediately with indication 0x13 result 3
// (bad state). In state 0xb it clears the pending-reason word, moves to
// state 8 and issues the teardown command through FUN_022d03e8 using a
// 0x200-byte scratch frame on the stack. A non-zero status word in the
// command result is reported as indication 0x13 result 1 with the failing
// code in the 0x104 slot; success answers 0x13 result 0.

typedef struct Conn {
    unsigned short state;       /* +0x00 */
    unsigned char pad[0xe];
    int reason;                 /* +0x10 */
} Conn;

typedef struct ConnMgr {
    unsigned char pad[0x550];
    Conn *conn;                 /* +0x550 */
} ConnMgr;

typedef struct CmdResult {
    unsigned char pad[4];
    unsigned short status;      /* +0x4 */
} CmdResult;

extern ConnMgr G_023190dc;
extern int func_037cb520(void);
extern void func_037cb534(int state);
extern void *func_037d14bc(void);
extern void func_037d1464(void *ind);
extern CmdResult *FUN_022d03e8(void *frame, int cmd);

void FUN_022d33c8(void)
{
    unsigned char frame[0x200];
    Conn *conn = G_023190dc.conn;
    int irq = func_037cb520();
    unsigned short *ind;
    unsigned short status;

    if (conn->state != 0xb) {
        func_037cb534(irq);
        ind = (unsigned short *)func_037d14bc();
        ind[0] = 0x13;
        ind[1] = 3;
        func_037d1464(ind);
    } else {
        conn->reason = 0;
        conn->state = 8;
        func_037cb534(irq);

        status = FUN_022d03e8(frame, 7)->status;
        if (status != 0) {
            ind = (unsigned short *)func_037d14bc();
            ind[0] = 0x13;
            ind[1] = 1;
            ind[2] = 0x104;
            ind[3] = status;
            func_037d1464(ind);
        } else {
            ind = (unsigned short *)func_037d14bc();
            ind[0] = 0x13;
            ind[1] = 0;
            func_037d1464(ind);
        }
    }
}
