// decomp: module=arm7 addr=0x022d72cc name=FUN_022d72cc
// flags: -O4,s -noThumb
// size: 0xa8 - 0xa0 of code plus the two trailing pool words (0x0380fff4 and
// the 0x048080bc register address).

// Publishes a one-bit setting into three places: bit 2 of the mode word at
// +0x33a of the ARM7 state block, bit 5 of the flags halfword in the +0x344
// sub-block, and bits 1..2 of the 0x048080bc register. While the sub-block is
// in state 0x40 and +0x32e says 1, the freshly written flags word is also
// mirrored into +0x2e of the descriptor hanging off +0x4ac. Rejects anything
// but 0/1 with error 5.

extern void FUN_022d7c08(void);

typedef struct Mode {
    unsigned short b0 : 1;
    unsigned short b1 : 1;
    unsigned short b2 : 1;
    unsigned short b3 : 1;
    unsigned short b4 : 1;
    unsigned short b5 : 1;
    unsigned short rest : 10;
} Mode;

typedef struct Blk {
    char pad00[8];
    unsigned short state; /* +0x08 (state block +0x34c) */
    char pad0a[0x72];
    unsigned short flags; /* +0x7c (state block +0x3c0) */
} Blk;

int FUN_022d72cc(unsigned short v)
{
    Blk *b;
    Mode *m;

    b = (Blk *)(*(char **)0x0380fff4 + 0x344);

    if (v > 1) return 5;

    m = (Mode *)(*(char **)0x0380fff4 + 0x33a);
    m->b2 = v;

    if (v == 0) {
        b->flags &= ~0x20;
    } else {
        b->flags |= 0x20;
    }

    if (b->state == 0x40 &&
        *(unsigned short *)(*(char **)0x0380fff4 + 0x32e) == 1) {
        *(unsigned short *)(*(int *)(*(char **)0x0380fff4 + 0x4ac) + 0x2e) =
            b->flags;
    }

    if (v == 0) {
        *(volatile unsigned short *)0x048080bc &= ~6;
    } else {
        *(volatile unsigned short *)0x048080bc |= 6;
    }

    FUN_022d7c08();
    return 0;
}
