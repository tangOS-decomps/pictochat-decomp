// decomp: module=arm7 addr=0x022d00fc name=FUN_022d00fc
// NONMATCHING: register coloring only: same wall as FUN_022cfdf8 (zero=ip vs lr, (len+1)/2 temp=r5 vs ip); 9 words differ, shape identical (div=9). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// decomp: module=arm7 addr=0x022d00fc name=FUN_022d00fc
// flags: -O4,s -noThumb

// Big sibling of FUN_022cff10 (type=9): fixed 0x20-byte fill at +0x12 behind
// the first halfword, five stack halfwords stamped at +0x34..+0x3c, then a
// variable-length copy of `len` bytes to +0x3e. The element count is the
// signed round-up (len + 1)/2 plus the 0x17 fixed halfwords.

typedef struct Hdr00fc {
    unsigned short f00, f02, f04, f06, f08, f0a;
    unsigned short type;    /* +0x0c */
    unsigned short count;   /* +0x0e */
    unsigned short f10;     /* +0x10 */
    unsigned char  f12[0x20]; /* +0x12 */
    unsigned short f32;     /* +0x32 */
    unsigned short f34;     /* +0x34 */
    unsigned short f36;     /* +0x36 */
    unsigned short f38;     /* +0x38 */
    unsigned short f3a;     /* +0x3a */
    unsigned short f3c;     /* +0x3c */
    unsigned char  f3e[1];  /* +0x3e */
} Hdr00fc;

extern void FUN_037cb78c(int value, void *dest, unsigned int size);
extern void FUN_022ce1d8(void *conn);

unsigned short *FUN_022d00fc(Hdr00fc *p, unsigned short a, int fill,
                             unsigned short b, unsigned short c,
                             unsigned short d, unsigned short e,
                             unsigned short f, unsigned short len, int src)
{
    unsigned short n;
    unsigned short *q;

    p->f00 = 0;
    p->f02 = 0;
    p->f04 = 0;
    p->f06 = 0;
    p->f08 = 0;
    p->f0a = 0;
    p->type = 9;
    p->count = (len + 1) / 2 + 0x17;
    p->f10 = a;
    FUN_037cb78c(fill, p->f12, 0x20);
    p->f32 = b;
    p->f34 = c;
    p->f36 = d;
    p->f38 = e;
    p->f3a = f;
    p->f3c = len;
    FUN_037cb78c(src, p->f3e, len);

    n = p->count;
    q = (unsigned short *)p + n;
    q[8] = p->type;
    q[9] = 1;
    FUN_022ce1d8(p);
    return q + 8;
}
