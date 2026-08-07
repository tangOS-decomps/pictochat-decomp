// decomp: module=arm7 addr=0x022d0f98 name=FUN_022d0f98
// flags: -O4,s -noThumb
//
// Copies the 0x40-byte key block out to the caller's buffer, then reports the
// result of a WEP/key request. If the requested slot's bit is clear in the
// mask at +0x1f4 the request is refused with code 6; otherwise a command
// block is assembled on the stack and its status halfword decides between the
// success (code 1 + 0x212 + status) and the plain-success (code 0) reply.

typedef struct Blk0f98 {
    char pad0[0xe8];
    unsigned char fe8[0x10];
    unsigned short ff8;
    char pad1[0x11a - 0xfa];
    unsigned short f11a;
    char pad2[0x1f4 - 0x11c];
    unsigned short f1f4;
} Blk0f98;

typedef struct Mgr0f98 {
    char pad[0x550];
    Blk0f98 *f550;
} Mgr0f98;

typedef struct Req0f98 {
    char pad[4];
    void *f4;
} Req0f98;

extern Mgr0f98 G_023190dc;

extern void func_037cb8b4(void *dst, const void *src, int len);
extern unsigned short *FUN_037d14bc(void);
extern void FUN_037d1464(unsigned short *ind);
extern unsigned short *FUN_022d0684(void *buf, unsigned short a);

void FUN_022d0f98(Req0f98 *req)
{
    unsigned char buf[0x200];
    Blk0f98 *b = G_023190dc.f550;
    unsigned short *ind;
    unsigned short v;

    func_037cb8b4(req->f4, b->fe8, 0x40);
    if (((1 << b->f11a) & b->f1f4) == 0) {
        ind = FUN_037d14bc();
        ind[0] = 7;
        ind[1] = 6;
        FUN_037d1464(ind);
    } else {
        v = FUN_022d0684(buf, b->ff8)[2];
        if (v != 0) {
            ind = FUN_037d14bc();
            ind[0] = 7;
            ind[1] = 1;
            ind[2] = 0x212;
            ind[3] = v;
            FUN_037d1464(ind);
        } else {
            ind = FUN_037d14bc();
            ind[0] = 7;
            ind[1] = 0;
            FUN_037d1464(ind);
        }
    }
}
