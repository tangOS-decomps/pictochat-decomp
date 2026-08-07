// decomp: module=arm7 addr=0x022ce808 name=FUN_022ce808
// flags: -O4,s -noThumb

// Clamps a window size to 0x200 and publishes it to the active connection: the
// raw value lands at +0x36/+0x32 and the value plus two goes to the pair of
// fields selected by the direction flag at +0x188.

typedef unsigned short u16;

typedef struct Conn {
    char pad[0x32];
    u16 f32;
    char pad2[2];
    u16 f36;
    u16 f38;
    u16 f3a;
    u16 f3c;
    u16 f3e;
    char pad3[0x188 - 0x40];
    u16 f188;
} Conn;

typedef struct ConnMgr {
    char pad[0x550];
    Conn *conn;
} ConnMgr;

extern ConnMgr G_023190dc;

void FUN_022ce808(u16 v) {
    Conn *conn = G_023190dc.conn;
    if (v > 0x200) v = 0x200;
    conn->f36 = v;
    conn->f32 = v;
    if (conn->f188 == 0) {
        conn->f3e = (u16)(v + 2);
        conn->f3a = (u16)(v + 2);
    } else {
        conn->f3c = (u16)(v + 2);
        conn->f38 = (u16)(v + 2);
    }
}
