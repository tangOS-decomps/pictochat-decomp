// decomp: module=arm7 addr=0x022d07f4 name=FUN_022d07f4
// NONMATCHING: register coloring only: same wall as FUN_022cfdf8 (zero=ip vs lr, pool 0x245=r5 vs ip); 9 words differ, shape identical (div=9). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// decomp: module=arm7 addr=0x022d07f4 name=FUN_022d07f4
// flags: -O4,s -noThumb

// Sibling of FUN_022d054c for frame type 0x245, but the payload is variable
// length: `n` bytes are copied in behind a halfword length prefix, so the
// element count is the signed round-up (n + 1) / 2 plus the prefix itself.
// NOTE: verify with --size 0x84, not funcs.json's 0x80 - the boundary excludes
// this function's own trailing pool word (0x245 is not an ARM immediate).

typedef struct Frame07f4 {
    unsigned short f00, f02, f04, f06, f08, f0a;
    unsigned short type;    /* +0x0c */
    unsigned short count;   /* +0x0e */
    unsigned short body[1]; /* +0x10 */
} Frame07f4;

extern void FUN_037cb78c(const void *src, void *dst, unsigned int size);
extern void FUN_022ce1d8(Frame07f4 *f);

unsigned short *FUN_022d07f4(Frame07f4 *p, int n, const void *src)
{
    unsigned short cnt;
    Frame07f4 *q;

    p->f00 = 0;
    p->f02 = 0;
    p->f04 = 0;
    p->f06 = 0;
    p->f08 = 0;
    p->f0a = 0;
    p->type = 0x245;
    p->count = (n + 1) / 2 + 1;
    p->body[0] = n;
    FUN_037cb78c(src, &p->body[1], n);

    cnt = p->count;
    q = (Frame07f4 *)((unsigned short *)p + cnt);
    q->body[0] = p->type;
    q->body[1] = 1;
    FUN_022ce1d8(p);
    return q->body;
}
