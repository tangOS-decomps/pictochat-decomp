// decomp: module=arm7 addr=0x022d2ad8 name=FUN_022d2ad8
// flags: -O4,s -noThumb
// size: 0xc4 - the nominal 0xbc excludes the two trailing pool words
// (0x023190dc and 0x0000f001).

// Builds and posts one of two link-layer frames from the shared message buffer.
// `mode` non-zero gives the 0x8 frame (peer MAC at +0xa, `id` at +0x10, the
// 0xf001 protocol tag at +0x12, and the connection's +0x30/+0x32 pair at
// +0x2c/+0x2e); mode zero gives the 0xc frame (the connection's +0x188 word at
// +0xa, the 0xf001 tag at +0xc, peer MAC at +0x10 and the +0x30/+0x32 pair at
// +0x16/+0x18). Both carry the fixed 0x1a length at +0x8 and clear +0x2.

typedef struct Conn {
    unsigned char pad0[0x30];
    unsigned short f30;  /* +0x30 */
    unsigned short f32;  /* +0x32 */
    unsigned char pad1[0x188 - 0x34];
    unsigned short f188; /* +0x188 */
} Conn;

typedef struct ConnMgr {
    char pad[0x550];
    Conn *conn; /* +0x550 */
} ConnMgr;

extern ConnMgr G_023190dc;

extern unsigned short *FUN_037d14bc(void);
// This call site passes the buffer back in r0; other sites in src/ spell the
// same helper as taking no argument.
extern void FUN_037d1464(unsigned short *msg);
extern void FUN_037cb8b4(const void *src, void *dst, unsigned int len);

void FUN_022d2ad8(int mode, unsigned short id, const void *mac)
{
    unsigned short *msg;
    Conn *conn;

    conn = G_023190dc.conn;
    msg = FUN_037d14bc();

    msg[1] = 0;
    if (mode != 0) {
        msg[0] = 8;
        msg[4] = 0x1a;
        msg[9] = 0xf001;
        msg[8] = id;
        FUN_037cb8b4(mac, &msg[5], 6);
        msg[0x16] = conn->f30;
        msg[0x17] = conn->f32;
    } else {
        msg[0] = 0xc;
        msg[4] = 0x1a;
        msg[6] = 0xf001;
        msg[5] = conn->f188;
        FUN_037cb8b4(mac, &msg[8], 6);
        msg[0xb] = conn->f30;
        msg[0xc] = conn->f32;
    }
    FUN_037d1464(msg);
}
