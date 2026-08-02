// decomp: module=arm7 addr=0x022ce2c4 name=FUN_022ce2c4
// flags: -noThumb
typedef struct ConnMgr5 {
    char pad[0x550];
    unsigned char *conn;
} ConnMgr5;

extern ConnMgr5 G_023190dc;

int FUN_022ce2c4(unsigned char *addr) {
    unsigned char *conn = G_023190dc.conn;
    return addr[0] == conn[0xe0] && addr[1] == conn[0xe1] && addr[2] == conn[0xe2] &&
           addr[3] == conn[0xe3] && addr[4] == conn[0xe4] && addr[5] == conn[0xe5];
}
