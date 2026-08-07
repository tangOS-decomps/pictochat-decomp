// decomp: module=arm7 addr=0x022d073c name=FUN_022d073c
// flags: -noThumb

// FUN_022cfda4 command builder with opcode 0x216 and a single argument.

extern void FUN_022ce1d8(void *blk);

unsigned short *FUN_022d073c(unsigned short *p, unsigned short a)
{
    unsigned short *q;

    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0x216;
    p[7] = 1;
    p[8] = a;

    q = p + p[7];
    q[8] = p[6];
    q[9] = 1;

    FUN_022ce1d8(p);
    return q + 8;
}
