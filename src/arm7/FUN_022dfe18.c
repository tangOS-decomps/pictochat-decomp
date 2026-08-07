// decomp: module=arm7 addr=0x022dfe18 name=FUN_022dfe18
// flags: -O4,s -noThumb

// Allocates and primes a management frame of `len` payload bytes out of the
// heap hanging off G_0380fff4 + 0x188, and hands back the frame body
// (block + 0x10). `extra` non-zero runs the pre-flight check first; a failed
// allocation reports code 2 and returns null.

extern int FUN_022df690(int id, unsigned short len, int extra);
extern void *FUN_037c58fc(void *heap, int size);
extern void FUN_022d9088(int code);
extern void FUN_022dffc4(void *body, int id);
extern void FUN_022d8d40(unsigned char *p, unsigned char v);

extern char *G_0380fff4;

void *FUN_022dfe18(int id, unsigned short len, int extra)
{
    unsigned char *blk;

    if (extra != 0) {
        if (FUN_022df690(id, len, extra) == 0) {
            return 0;
        }
    }
    blk = (unsigned char *)FUN_037c58fc(G_0380fff4 + 0x188, len + 0x3d);
    if (blk == 0) {
        FUN_022d9088(2);
        return blk;
    }
    *(unsigned short *)(blk + 0xc) = 0xffff;
    FUN_022dffc4(blk + 0x10, id);
    if (len != 0) {
        FUN_022d8d40(blk + 0x42, 0x10);
        FUN_022d8d40(blk + 0x43, (unsigned char)len);
        len = len + 2;
    }
    *(unsigned short *)(blk + 0x16) = len + 6;
    *(unsigned short *)(blk + 0x22) = *(unsigned short *)(blk + 0x16) + 0x1c;
    *(unsigned short *)(blk + 0x24) = 0xb0;
    return blk + 0x10;
}
