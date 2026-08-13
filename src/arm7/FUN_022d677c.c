// decomp: module=arm7 addr=0x022d677c name=FUN_022d677c
// flags: -O4,s -noThumb
// size: 0x78 - the stated 0x74 excludes the trailing pool word (0x242 is not
// an ARM immediate).

// Sibling of FUN_022d3ad4 on the 0x24 message channel: queries FUN_022d0798
// (which also wants the u16 taken from the caller block's word at +4) into a
// 0x200-byte scratch block, then reports either the long (0x242) form carrying
// the status word or the short form.

typedef struct {
    unsigned int f00;
    unsigned int f04;
} Arg022d677c;

extern unsigned short *FUN_022d0798(void *buf, unsigned short v);
extern unsigned short *FUN_037d14bc(void);
extern void FUN_037d1464(void);

void FUN_022d677c(Arg022d677c *a)
{
    unsigned char buf[0x200];
    unsigned short *r;
    unsigned short *p;
    unsigned short status;

    r = FUN_022d0798(buf, a->f04);
    status = r[2];
    if (status != 0) {
        p = FUN_037d14bc();
        p[0] = 0x24;
        p[1] = 1;
        p[2] = 0x242;
        p[3] = status;
        FUN_037d1464();
    } else {
        p = FUN_037d14bc();
        p[0] = 0x24;
        p[1] = 0;
        FUN_037d1464();
    }
}
