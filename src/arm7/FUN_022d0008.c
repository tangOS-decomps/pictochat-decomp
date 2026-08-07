// decomp: module=arm7 addr=0x022d0008 name=FUN_022d0008
// flags: -noThumb

// Sibling of FUN_022cff10: same fixed-header-plus-trailer shape (type=5,
// len=4), but the caller-supplied fill value goes into the small 6-byte body
// instead of a field, and the third parameter is stamped directly into the
// header after the body fill.

typedef struct {
    unsigned short f0, f2, f4, f6, f8, fA;  // +0x00-+0x0a, always zeroed
    unsigned short type;                     // +0x0c
    unsigned short len;                      // +0x0e
    unsigned char body[6];                   // +0x10-+0x15
    unsigned short f16;                      // +0x16
} Hdr022d0008;

extern void FUN_037cb78c(int value, void *dest, unsigned int size);
extern void FUN_022ce1d8(void *conn);

void *FUN_022d0008(Hdr022d0008 *hdr, unsigned short fillValue, unsigned short f16val)
{
    hdr->f0 = 0;
    hdr->f2 = 0;
    hdr->f4 = 0;
    hdr->f6 = 0;
    hdr->f8 = 0;
    hdr->fA = 0;
    hdr->type = 5;
    hdr->len = 4;

    FUN_037cb78c(fillValue, hdr->body, 6);

    hdr->f16 = f16val;

    {
        unsigned short len = hdr->len;
        unsigned short type = hdr->type;
        unsigned char *trailer = (unsigned char *)hdr + (len << 1);
        *(unsigned short *)(trailer + 0x10) = type;
        *(unsigned short *)(trailer + 0x12) = 4;
        FUN_022ce1d8(hdr);
        return trailer + 0x10;
    }
}
