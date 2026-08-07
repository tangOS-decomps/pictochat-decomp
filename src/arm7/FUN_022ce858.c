// decomp: module=arm7 addr=0x022ce858 name=FUN_022ce858
typedef unsigned short u16;

typedef struct Conn {
    char pad[0x30];
    u16 f30;
    char pad2[6];
    u16 f38;
    u16 f3a;
    char pad3[0x188 - 0x3c];
    u16 f188;
} Conn;

typedef struct ConnMgr {
    char pad[0x550];
    Conn *conn;
} ConnMgr;

extern ConnMgr G_023190dc;

void FUN_022ce858(u16 v) {
    Conn *conn = G_023190dc.conn;
    conn->f30 = v;
    if (conn->f188 == 0) {
        conn->f38 = v + 4;
    } else {
        conn->f3a = v + 4;
    }
}
