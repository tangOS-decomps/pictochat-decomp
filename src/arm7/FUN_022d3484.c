// decomp: module=arm7 addr=0x022d3484 name=FUN_022d3484
// flags: -O4,s -noThumb
// NOTE: verify with --size 0xa8, not the nominal 0xa4 - the stated size
// excludes this function's own trailing pool word.
//
// Applies a "set security mode" request to the connection block: latches the
// requested mode, decides whether that mode uses a key (modes 1..3 do, mode 0
// and anything out of range do not), then either copies the caller's 0x50-byte
// key material into the connection or clears the stored key. Finally posts a
// completion indication (type 0x14, result 0).

typedef struct Conn {
    unsigned char pad[0x196];
    unsigned short mode;        /* +0x196 */
    int keyed;                  /* +0x198 */
    unsigned char key[0x50];    /* +0x19c */
} Conn;

typedef struct ConnMgr {
    unsigned char pad[0x550];
    Conn *conn;                 /* +0x550 */
} ConnMgr;

typedef struct Req {
    unsigned char pad[4];
    int mode;                   /* +0x4 */
    void *key;                  /* +0x8 */
} Req;

extern ConnMgr G_023190dc;
extern void func_037cb8b4(void *dst, void *src, int len);
extern void func_037cb820(void *dst, int fill, int len);
extern void *func_037d14bc(void);
extern void func_037d1464(void *ind);

void FUN_022d3484(Req *req)
{
    Conn *conn = G_023190dc.conn;
    unsigned short *ind;

    conn->mode = (unsigned short)req->mode;
    switch (conn->mode) {
    case 0:
        conn->keyed = 0;
        break;
    case 1:
    case 2:
    case 3:
        conn->keyed = 1;
        break;
    default:
        conn->keyed = 0;
        break;
    }

    if (conn->keyed == 1) {
        func_037cb8b4(req->key, conn->key, 0x50);
    } else {
        func_037cb820(conn->key, 0, 0x50);
    }

    ind = (unsigned short *)func_037d14bc();
    ind[0] = 0x14;
    ind[1] = 0;
    func_037d1464(ind);
}
