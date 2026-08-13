// decomp: module=arm7 addr=0x022cff88 name=FUN_022cff88
// NONMATCHING: register coloring only: ROM keeps len const 5 in r5 (shared with the post-call f18val web), candidate uses ip; 2 words differ, shape identical (div=2). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// decomp: module=arm7 addr=0x022cff88 name=FUN_022cff88
// flags: -noThumb

// Sibling of FUN_022d0008 (type=4, len=5): the 6-byte body is filled from the
// caller-supplied value, then two more header halfwords are stamped at +0x16
// and +0x18 before the trailer is opened with length 6.

typedef struct {
    unsigned short f0, f2, f4, f6, f8, fA;  // +0x00-+0x0a, always zeroed
    unsigned short type;                     // +0x0c
    unsigned short len;                      // +0x0e
    unsigned char body[6];                   // +0x10-+0x15
    unsigned short f16;                      // +0x16
    unsigned short f18;                      // +0x18
} Hdr022cff88;

extern void FUN_037cb78c(int value, void *dest, unsigned int size);
extern void FUN_022ce1d8(void *conn);

void *FUN_022cff88(Hdr022cff88 *hdr, unsigned short fillValue,
                   unsigned short f16val, unsigned short f18val)
{
    hdr->f0 = 0;
    hdr->f2 = 0;
    hdr->f4 = 0;
    hdr->f6 = 0;
    hdr->f8 = 0;
    hdr->fA = 0;
    hdr->type = 4;
    hdr->len = 5;

    FUN_037cb78c(fillValue, hdr->body, 6);

    hdr->f16 = f16val;
    hdr->f18 = f18val;

    {
        unsigned short len = hdr->len;
        unsigned short type = hdr->type;
        unsigned char *trailer = (unsigned char *)hdr + (len << 1);
        *(unsigned short *)(trailer + 0x10) = type;
        *(unsigned short *)(trailer + 0x12) = 6;
        FUN_022ce1d8(hdr);
        return trailer + 0x10;
    }
}
