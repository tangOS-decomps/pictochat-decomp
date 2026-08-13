// decomp: module=arm7 addr=0x022d061c name=FUN_022d061c
// NONMATCHING: register coloring only: same wall as FUN_022cfdf8 (zero=ip vs lr, pool 0x211=r4 vs ip); 11 words differ, shape identical (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// decomp: module=arm7 addr=0x022d061c name=FUN_022d061c
// flags: -O4,s -noThumb

// Sibling of FUN_022d0494 for frame type 0x211 with three halfwords of payload.
// 0x211 is not an ARM immediate, so it costs a trailing pool word - verify with
// --size 0x68, not funcs.json's 0x64.
// See FUN_022d03e8 for why the trailer is addressed by sliding the header type
// forward instead of indexing body[].

typedef struct Frame {
    unsigned short f00, f02, f04, f06, f08, f0a;
    unsigned short type;    /* +0x0c */
    unsigned short count;   /* +0x0e */
    unsigned short body[1]; /* +0x10 */
} Frame;

extern void FUN_022ce1d8(Frame *f);

unsigned short *FUN_022d061c(Frame *p, unsigned short a, unsigned short b, unsigned short c)
{
    unsigned short v;
    unsigned short n;
    Frame *q;

    p->f00 = 0;
    p->f02 = 0;
    p->f04 = 0;
    p->f06 = 0;
    p->f08 = 0;
    p->f0a = 0;
    v = 0x211;
    p->type = v;
    v = 3;
    p->count = v;
    p->body[0] = a;
    p->body[1] = b;
    p->body[2] = c;

    n = p->count;
    q = (Frame *)((unsigned short *)p + n);
    q->body[0] = p->type;
    q->body[1] = 1;
    FUN_022ce1d8(p);
    return q->body;
}
