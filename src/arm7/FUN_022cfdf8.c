// decomp: module=arm7 addr=0x022cfdf8 name=FUN_022cfdf8
// NONMATCHING: register coloring only: ROM colors const temps r4/ip, candidate ip/lr (allocator prefers scratch over the already-pushed r4 that hosts the trailer web); 12 words differ, shape identical; ~8 source/flag levers tried (div=12). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// decomp: module=arm7 addr=0x022cfdf8 name=FUN_022cfdf8
// flags: -O4,s -noThumb

// Sibling of FUN_022d03e8 for type-1 frames: same zero-the-header / stamp the
// type-count pair / open the next element shape, but three halfwords of payload
// instead of one. Because the type and the trailer's length are both 1, mwcc
// keeps the constant in ip across the whole body.
// See FUN_022d03e8 for why the trailer is addressed by sliding the header type
// forward instead of indexing body[].

typedef struct Frame {
    unsigned short f00, f02, f04, f06, f08, f0a;
    unsigned short type;    /* +0x0c */
    unsigned short count;   /* +0x0e */
    unsigned short body[1]; /* +0x10 */
} Frame;

extern void FUN_022ce1d8(Frame *f);

unsigned short *FUN_022cfdf8(Frame *p, unsigned short a, unsigned short b, unsigned short c)
{
    Frame *q;
    unsigned short n;

    p->f00 = 0;
    p->f02 = 0;
    p->f04 = 0;
    p->f06 = 0;
    p->f08 = 0;
    p->f0a = 0;
    p->type = 1;
    p->count = 3;
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
