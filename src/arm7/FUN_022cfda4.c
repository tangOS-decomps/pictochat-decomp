// decomp: module=arm7 addr=0x022cfda4 name=FUN_022cfda4
// flags: -noThumb

// Builds a one-argument command block in the caller's buffer: header halfwords
// cleared, opcode 0, one argument, then the trailing terminator pair is
// appended past the argument list and the block is submitted. Returns the
// address of that terminator pair.

extern void FUN_022ce1d8(void *blk);

unsigned short *FUN_022cfda4(unsigned short *p, unsigned short a)
{
    unsigned short *q;

    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 1;
    p[8] = a;

    q = p + p[7];
    q[8] = p[6];
    q[9] = 1;

    FUN_022ce1d8(p);
    return q + 8;
}
