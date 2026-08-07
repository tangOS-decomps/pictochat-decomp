// decomp: module=arm7 addr=0x022d09e4 name=FUN_022d09e4
// flags: -O4,s -noThumb

// Same frame-opening shape as FUN_022d03e8, but the type comes from the caller
// and the body starts empty (count = 0), so the first element lands at the
// start of the body with `arg` as its length. FUN_022ce1d8 posts the frame and
// the element address is returned.
//
// p->type is reloaded rather than reused because the store narrowed an int to
// a halfword. p->count is forwarded from the just-stored 0 (no reload, unlike
// FUN_022d03e8, because nothing aliasing has been written yet) but it is still
// a value in a register, which is why the ROM keeps the general
// `add r4, r0, r3, lsl #1` with r3 == 0 instead of folding it away.

typedef struct Frame {
    unsigned short f00, f02, f04, f06, f08, f0a;
    unsigned short type;    /* +0x0c */
    unsigned short count;   /* +0x0e */
    unsigned short body[1]; /* +0x10 */
} Frame;

extern void FUN_022ce1d8(Frame *f);

unsigned short *FUN_022d09e4(Frame *p, int type, unsigned short arg)
{
    unsigned short n;
    Frame *q;

    p->f00 = 0;
    p->f02 = 0;
    p->f04 = 0;
    p->f06 = 0;
    p->f08 = 0;
    p->f0a = 0;
    p->type = (unsigned short)type;
    p->count = 0;

    n = p->count;
    q = (Frame *)((unsigned short *)p + n);
    q->body[0] = p->type;
    q->body[1] = arg;
    FUN_022ce1d8(p);
    return q->body;
}
