// decomp: module=arm7 addr=0x022d023c name=FUN_022d023c
// flags: -O4,s -noThumb

// Initializes two related control structures: clears the first six halfword
// fields of `a0`, sets its capacity (+0xc = 0x100) and element-size
// (+0xe = 0x18) fields, hands `a1` off to FUN_037cb78c for a 0x30-byte
// setup sourced from `a0+0x10`, clears a scattered set of `a1`'s halfword
// fields, then derives a sub-header inside `a0` (at `a0 + elemSize*2`),
// fills its size/type fields, initializes it via FUN_022ce1d8(a0), and
// returns a pointer 0x10 into that sub-header.

extern void FUN_037cb78c(void *dst, void *src, unsigned int n);
extern void FUN_022ce1d8(void *ctx);

void *FUN_022d023c(void *a0, void *a1)
{
    unsigned char *p0 = (unsigned char *)a0;
    unsigned char *p1;
    unsigned short elemSize;
    unsigned short cap;
    unsigned char *sub;

    *(unsigned short *)(p0 + 0x00) = 0;
    *(unsigned short *)(p0 + 0x02) = 0;
    *(unsigned short *)(p0 + 0x04) = 0;
    *(unsigned short *)(p0 + 0x06) = 0;
    *(unsigned short *)(p0 + 0x08) = 0;
    *(unsigned short *)(p0 + 0x0a) = 0;

    p1 = (unsigned char *)a1;

    *(unsigned short *)(p0 + 0x0c) = 0x100;
    *(unsigned short *)(p0 + 0x0e) = 0x18;

    FUN_037cb78c(p1, p0 + 0x10, 0x30);

    *(unsigned short *)(p1 + 0x02) = 0;
    *(unsigned short *)(p1 + 0x04) = 0;
    *(unsigned short *)(p1 + 0x08) = 0;
    *(unsigned short *)(p1 + 0x0a) = 0;
    *(unsigned short *)(p1 + 0x0c) = 0;
    *(unsigned short *)(p1 + 0x10) = 0;
    *(unsigned short *)(p1 + 0x12) = 0;
    *(unsigned short *)(p1 + 0x14) = 0;
    *(unsigned short *)(p1 + 0x16) = 0;
    *(unsigned short *)(p1 + 0x24) = 0;
    *(unsigned short *)(p1 + 0x26) = 0;
    *(unsigned short *)(p1 + 0x28) = 0;
    *(unsigned short *)(p1 + 0x2a) = 0;

    elemSize = *(unsigned short *)(p0 + 0x0e);
    cap = *(unsigned short *)(p0 + 0x0c);
    sub = p0 + (elemSize << 1);

    *(unsigned short *)(sub + 0x10) = cap;
    *(unsigned short *)(sub + 0x12) = 2;

    FUN_022ce1d8(a0);

    return sub + 0x10;
}
