// decomp: module=arm7 addr=0x022d0494 name=FUN_022d0494
// flags: -O4,s -noThumb

// Sibling of FUN_022d03e8 for frame type 0x207: zeroes the six header
// halfwords, writes the type/count pair at +0xc/+0xe, drops `arg` into the
// first body slot and opens the next element (type = the header's own type,
// length 1) at the window that starts p->count halfwords into the frame.
// FUN_022ce1d8 posts the frame; the new element's address is returned.
// See FUN_022d03e8 for why the element is addressed by sliding the header type
// forward instead of indexing body[].
// NOTE: verify with --size 0x5c, not funcs.json's 0x58 - the boundary excludes
// this function's own trailing pool word (0x207 is not an ARM immediate).

typedef struct Frame {
    unsigned short f00, f02, f04, f06, f08, f0a;
    unsigned short type;    /* +0x0c */
    unsigned short count;   /* +0x0e */
    unsigned short body[1]; /* +0x10 */
} Frame;

extern void FUN_022ce1d8(Frame *f);

unsigned short *FUN_022d0494(Frame *p, unsigned short arg)
{
    unsigned short n;
    Frame *q;

    p->f00 = 0;
    p->f02 = 0;
    p->f04 = 0;
    p->f06 = 0;
    p->f08 = 0;
    p->f0a = 0;
    p->type = 0x207;
    p->count = 1;
    p->body[0] = arg;

    n = p->count;
    q = (Frame *)((unsigned short *)p + n);
    q->body[0] = p->type;
    q->body[1] = 1;
    FUN_022ce1d8(p);
    return q->body;
}
