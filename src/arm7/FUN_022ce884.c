// decomp: module=arm7 addr=0x022ce884 name=FUN_022ce884
// flags: -noThumb
typedef unsigned short u16;

typedef struct Conn {
    char pad[0x32];
    u16 f32;
    char pad2[4];
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

void FUN_022ce884(u16 v) {
    Conn *conn = G_023190dc.conn;
    conn->f32 = v;
    if (conn->f188 == 0) {
        conn->f3a = v + 2;
    } else {
        conn->f38 = v + 2;
    }
}
