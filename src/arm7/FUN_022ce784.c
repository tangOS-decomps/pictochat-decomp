// decomp: module=arm7 addr=0x022ce784 name=FUN_022ce784
// flags: -noThumb
typedef struct ConnMgr7 {
    char pad[0x550];
    char *conn;
} ConnMgr7;

extern ConnMgr7 G_023190dc;

void FUN_022ce784(void) {
    char *c = G_023190dc.conn;
    *(unsigned short *)(c + 0x38) = 0;
    *(unsigned short *)(c + 0x3a) = 0;
    *(unsigned short *)(c + 0x30) = 0;
    *(unsigned short *)(c + 0x32) = 0;
    *(unsigned short *)(c + 0x3c) = 0;
    *(unsigned short *)(c + 0x3e) = 0;
    *(unsigned short *)(c + 0x34) = 0;
    *(unsigned short *)(c + 0x36) = 0;
}
