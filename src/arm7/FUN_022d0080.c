// decomp: module=arm7 addr=0x022d0080 name=FUN_022d0080
// flags: -O4,s -noThumb

// Frame builder for type 6: zeroes the six header halfwords, writes
// type/count at +0x0c/+0x0e, copies a 6-byte payload into the body, drops
// two more halfword arguments into body[3]/body[4], then opens the next
// element (type = the header's own type, length 3) at the window that starts
// p->count halfwords into the frame. FUN_022ce1d8 posts the frame.

typedef struct Frame0080 {
    unsigned short f00, f02, f04, f06, f08, f0a;
    unsigned short type;    /* +0x0c */
    unsigned short count;   /* +0x0e */
    unsigned short body[1]; /* +0x10 */
} Frame0080;

extern void FUN_037cb78c(const void *src, void *dst, unsigned int size);
extern void FUN_022ce1d8(Frame0080 *f);

unsigned short *FUN_022d0080(Frame0080 *p, const void *src, unsigned short c,
                             unsigned short d)
{
    unsigned short n;
    Frame0080 *q;

    p->f00 = 0;
    p->f02 = 0;
    p->f04 = 0;
    p->f06 = 0;
    p->f08 = 0;
    p->f0a = 0;
    p->type = 6;
    p->count = 5;
    FUN_037cb78c(src, p->body, 6);
    p->body[3] = c;
    p->body[4] = d;

    n = p->count;
    q = (Frame0080 *)((unsigned short *)p + n);
    q->body[0] = p->type;
    q->body[1] = 3;
    FUN_022ce1d8(p);
    return q->body;
}
