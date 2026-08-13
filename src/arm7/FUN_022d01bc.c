// decomp: module=arm7 addr=0x022d01bc name=FUN_022d01bc
// NONMATCHING: register coloring only: same wall as FUN_022cfdf8 (zero const r5 in ROM vs ip in candidate); 8 words differ, shape identical (div=8). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// decomp: module=arm7 addr=0x022d01bc name=FUN_022d01bc
// flags: -noThumb

// Sibling of FUN_022cff10 (type=0xa, len=0xc): three caller halfwords go into
// +0x12..+0x16 behind a zeroed +0x10 slot, the 0x10 bytes from +0x18 are filled
// from the stack-passed value, and the trailer carries opcode 0x12.

typedef struct {
    unsigned short f0, f2, f4, f6, f8, fA;  // +0x00-+0x0a, always zeroed
    unsigned short type;                     // +0x0c
    unsigned short len;                      // +0x0e
    unsigned short f10;                      // +0x10
    unsigned short f12;                      // +0x12
    unsigned short f14;                      // +0x14
    unsigned short f16;                      // +0x16
} Hdr022d01bc;

extern void FUN_037cb78c(int value, void *dest, unsigned int size);
extern void FUN_022ce1d8(void *conn);

void *FUN_022d01bc(Hdr022d01bc *hdr, unsigned short a, unsigned short b,
                   unsigned short c, int fillValue)
{
    hdr->f0 = 0;
    hdr->f2 = 0;
    hdr->f4 = 0;
    hdr->f6 = 0;
    hdr->f8 = 0;
    hdr->fA = 0;
    hdr->type = 0xa;
    hdr->len = 0xc;
    hdr->f10 = 0;
    hdr->f12 = a;
    hdr->f14 = b;
    hdr->f16 = c;

    FUN_037cb78c(fillValue, (unsigned char *)hdr + 0x18, 0x10);

    {
        unsigned short len = hdr->len;
        unsigned short type = hdr->type;
        unsigned char *trailer = (unsigned char *)hdr + (len << 1);
        *(unsigned short *)(trailer + 0x10) = type;
        *(unsigned short *)(trailer + 0x12) = 0x12;
        FUN_022ce1d8(hdr);
        return trailer + 0x10;
    }
}
