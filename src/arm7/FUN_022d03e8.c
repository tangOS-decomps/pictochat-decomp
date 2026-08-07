// decomp: module=arm7 addr=0x022d03e8 name=FUN_022d03e8
// flags: -O4,s -noThumb

// Starts a type-0x104 frame in `p`: zeroes the six header halfwords, writes
// the type/count pair at +0xc/+0xe, drops `arg` into the first body slot and
// then opens the next element (type = the header's own type, length 1) at the
// window that starts p->count halfwords into the frame. FUN_022ce1d8 posts the
// frame; the new element's address is returned so the caller can keep filling
// it in.
//
// Two shapes here are load-bearing:
//  - the reloads of p->type / p->count are the ROM's own: the store through
//    p->body[0] is a halfword store that kills both cached header copies;
//  - the next element is addressed by *sliding the header type* forward
//    (q = p + count halfwords) rather than by &p->body[count]. Only the
//    sliding form folds the +0x10/+0x12 into the store displacements off a
//    single `add r4, r0, r2, lsl #1`; indexing body[] makes mwcc materialise
//    p+0x10 first and costs four extra instructions.

typedef struct Frame {
    unsigned short f00, f02, f04, f06, f08, f0a;
    unsigned short type;    /* +0x0c */
    unsigned short count;   /* +0x0e */
    unsigned short body[1]; /* +0x10 */
} Frame;

extern void FUN_022ce1d8(Frame *f);

unsigned short *FUN_022d03e8(Frame *p, unsigned short arg)
{
    unsigned short n;
    Frame *q;

    p->f00 = 0;
    p->f02 = 0;
    p->f04 = 0;
    p->f06 = 0;
    p->f08 = 0;
    p->f0a = 0;
    p->type = 0x104;
    p->count = 1;
    p->body[0] = arg;

    n = p->count;
    q = (Frame *)((unsigned short *)p + n);
    q->body[0] = p->type;
    q->body[1] = 1;
    FUN_022ce1d8(p);
    return q->body;
}
