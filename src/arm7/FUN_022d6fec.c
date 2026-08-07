// decomp: module=arm7 addr=0x022d6fec name=FUN_022d6fec
// flags: -O4,s -noThumb

// Stores the requested mode (0..2) into the halfword at +0x330 of the ARM7
// state block and kicks FUN_022d7c08; rejects anything above 2 with 5.

extern void FUN_022d7c08(void);

typedef struct Blk6fec {
    char pad[0x30];
    unsigned short f30;
} Blk6fec;

int FUN_022d6fec(unsigned int mode)
{
    Blk6fec *b;

    if (mode > 2) {
        return 5;
    }
    b = (Blk6fec *)(*(char **)0x0380fff4 + 0x300);
    b->f30 = (unsigned short)mode;
    FUN_022d7c08();
    return 0;
}
