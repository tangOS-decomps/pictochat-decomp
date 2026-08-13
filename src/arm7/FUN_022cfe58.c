// decomp: module=arm7 addr=0x022cfe58 name=FUN_022cfe58
// NONMATCHING: same single-root coloring wall as FUN_022cff88: ROM parks consts 2/0x1f in r5 which pushes a into r7 (6-reg push), candidate uses ip (4-reg push); all 14 diffs downstream of that one allocation choice (div=14). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// decomp: module=arm7 addr=0x022cfe58 name=FUN_022cfe58
// flags: -O4,s -noThumb

// Big sibling of FUN_022d0008 (type=2, len=0x1f): 6-byte fill at +0x10, the
// third register argument stamped at +0x16, a 0x20-byte copy at +0x18, a
// halfword at +0x38, a 0x10-byte copy at +0x3a, a halfword at +0x4a and a
// cleared halfword at +0x4c. The trailer's second slot is (a >> 1) - 0x2c
// rather than a constant.

typedef struct Hdrfe58 {
    unsigned short f00, f02, f04, f06, f08, f0a;
    unsigned short type;    /* +0x0c */
    unsigned short len;     /* +0x0e */
    unsigned char  f10[6];  /* +0x10 */
    unsigned short f16;     /* +0x16 */
    unsigned char  f18[0x20]; /* +0x18 */
    unsigned short f38;     /* +0x38 */
    unsigned char  f3a[0x10]; /* +0x3a */
    unsigned short f4a;     /* +0x4a */
    unsigned short f4c;     /* +0x4c */
} Hdrfe58;

extern void FUN_037cb78c(int value, void *dest, unsigned int size);
extern void FUN_022ce1d8(void *conn);

unsigned short *FUN_022cfe58(Hdrfe58 *hdr, unsigned int a, int fill,
                             unsigned short b, int src1, unsigned short c,
                             int src2, unsigned short d)
{
    hdr->f00 = 0;
    hdr->f02 = 0;
    hdr->f04 = 0;
    hdr->f06 = 0;
    hdr->f08 = 0;
    hdr->f0a = 0;
    hdr->type = 2;
    hdr->len = 0x1f;
    FUN_037cb78c(fill, hdr->f10, 6);
    hdr->f16 = b;
    FUN_037cb78c(src1, hdr->f18, 0x20);
    hdr->f38 = c;
    FUN_037cb78c(src2, hdr->f3a, 0x10);
    hdr->f4a = d;
    hdr->f4c = 0;

    {
        unsigned short len = hdr->len;
        unsigned short type = hdr->type;
        unsigned char *trailer = (unsigned char *)hdr + (len << 1);
        *(unsigned short *)(trailer + 0x10) = type;
        *(unsigned short *)(trailer + 0x12) = (a >> 1) - 0x2c;
        FUN_022ce1d8(hdr);
        return (unsigned short *)(trailer + 0x10);
    }
}
