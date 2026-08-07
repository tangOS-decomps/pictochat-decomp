// decomp: module=arm7 addr=0x022df0b0 name=FUN_022df0b0
// flags: -O4,s -noThumb
// size: 0x74 - the stated 0x70 excludes the trailing pool word (0x0380fff4).
//
// Refreshes one entry: re-reads its channel byte (folding the 0xff "none"
// sentinel back to 0), copies the current global tick into the entry, bumps
// the retry counter when the 0x4000 flag is live, then hands the entry and
// the two global scratch blocks to the shared packer.

typedef struct {
    unsigned short f00;
    unsigned short f02;
    unsigned short f04;
    unsigned char  pad06[0xc];
    unsigned short f12;
    unsigned short f14;
    unsigned short f16;
    unsigned char  f18[8];
} Entry;

typedef struct {
    unsigned char  pad000[0x188];
    unsigned char  f188[0x18];
    unsigned char  f1a0[0x24c];
    unsigned int   f3ec;
} State;

extern State *G_0380fff4;
extern unsigned short FUN_022d991c(void *p);
extern void FUN_022d9b60(Entry *e);
extern void FUN_037c5a18(void *dst, void *src, void *e);

void FUN_022df0b0(Entry *e)
{
    e->f02 = FUN_022d991c(e->f18);
    if (e->f02 == 0xff) {
        e->f02 = 0;
    }

    e->f04 = G_0380fff4->f3ec;

    if (e->f14 & 0x4000) {
        e->f12 += 8;
    }

    FUN_022d9b60(e);
    FUN_037c5a18(&G_0380fff4->f188, &G_0380fff4->f1a0, (char *)e - 0x10);
}
