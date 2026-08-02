// decomp: module=arm7 addr=0x022cfa90 name=FUN_022cfa90
// flags: -O4,s -noThumb
typedef struct Conn4 {
    char pad[0x66];
    unsigned short f66;
    unsigned short f68;
} Conn4;

typedef struct ConnMgr8 {
    char pad[0x550];
    Conn4 *conn;
} ConnMgr8;

extern ConnMgr8 G_023190dc;
extern void *FUN_022ce718(void);
extern int func_037c9e90(void *a, void *pkt, int c);
extern void *func_037d14bc(void);
extern void func_037d1464(void *pkt);

void FUN_022cfa90(void) {
    Conn4 *conn = G_023190dc.conn;
    int *pkt = (int *)FUN_022ce718();
    int r;
    if (pkt != 0) {
        pkt[0] = 0x2d;
        pkt[1] = conn->f68;
        r = func_037c9e90((void *)0x02318164, pkt, 0);
    } else {
        r = 0;
    }
    if (r != 0) {
        conn->f66 = 1;
        return;
    }
    unsigned short *ind = (unsigned short *)func_037d14bc();
    ind[0] = 0x80;
    ind[1] = 8;
    ind[2] = 0x16;
    ind[3] = 0x2d;
    func_037d1464(ind);
}
