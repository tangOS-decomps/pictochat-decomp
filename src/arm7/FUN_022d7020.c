// decomp: module=arm7 addr=0x022d7020 name=FUN_022d7020
// flags: -O4,s -noThumb
//
// Sibling of FUN_022d70c0: stores a 0..3 selector, this time into the halfword
// at +0x334 of the ARM7 state block, and mirrors it into the channel block at
// +0x344 (bit 4 of f7c, bit 14 of f8a) plus the wifi register at 0x04808006
// (field at bits 3..5, where selector 0 is encoded as 1).

typedef struct Chan7020 {
    char pad0[8];
    unsigned short f08;
    char pad1[0x7c - 0x0a];
    unsigned short f7c;
    char pad2[0x8a - 0x7e];
    unsigned short f8a;
} Chan7020;

typedef struct Blk7020 {
    char pad[0x34];
    unsigned short f34;
} Blk7020;

typedef struct Out7020 {
    char pad[0x2e];
    unsigned short f2e;
} Out7020;

int FUN_022d7020(unsigned int mode)
{
    Chan7020 *c = (Chan7020 *)(*(char **)0x0380fff4 + 0x344);
    Blk7020 *b;

    if (mode > 3) {
        return 5;
    }
    b = (Blk7020 *)(*(char **)0x0380fff4 + 0x300);
    b->f34 = (unsigned short)mode;
    if (mode == 0) {
        c->f7c &= ~0x10;
        c->f8a &= ~0x4000;
    } else {
        c->f7c |= 0x10;
        c->f8a |= 0x4000;
    }
    if (c->f08 == 0x40 && mode == 1) {
        (*(Out7020 **)(*(char **)0x0380fff4 + 0x4ac))->f2e = c->f7c;
    }
    if (mode == 0) {
        mode = 1;
    }
    *(volatile unsigned short *)0x04808006 =
        (unsigned short)((*(volatile unsigned short *)0x04808006 & 0xffc7) |
                         (mode << 3));
    return 0;
}
