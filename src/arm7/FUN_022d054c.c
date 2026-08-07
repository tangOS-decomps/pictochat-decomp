// decomp: module=arm7 addr=0x022d054c name=FUN_022d054c
// flags: -O4,s -noThumb

// Sibling of FUN_022d04f0 / FUN_022d05c0 for frame type 0x20d: zeroes the six
// header halfwords, writes type/count at +0x0c/+0x0e, copies a 0x20-byte
// payload into the body, then opens the next element (type = the header's own
// type, length 1) at the window that starts p->count halfwords into the frame.
// FUN_022ce1d8 posts the frame; the new element's address is returned.
// NOTE: verify with --size 0x74, not 0x70 - the stated bound excludes this
// function's own trailing pool word (0x20d is not an ARM immediate).

typedef struct Frame054c {
    unsigned short f00, f02, f04, f06, f08, f0a;
    unsigned short type;    /* +0x0c */
    unsigned short count;   /* +0x0e */
    unsigned short body[1]; /* +0x10 */
} Frame054c;

extern void FUN_037cb78c(const void *src, void *dst, unsigned int size);
extern void FUN_022ce1d8(Frame054c *f);

unsigned short *FUN_022d054c(Frame054c *p, const void *src)
{
    unsigned short n;
    Frame054c *q;

    p->f00 = 0;
    p->f02 = 0;
    p->f04 = 0;
    p->f06 = 0;
    p->f08 = 0;
    p->f0a = 0;
    p->type = 0x20d;
    p->count = 0x10;
    FUN_037cb78c(src, p->body, 0x20);

    n = p->count;
    q = (Frame054c *)((unsigned short *)p + n);
    q->body[0] = p->type;
    q->body[1] = 1;
    FUN_022ce1d8(p);
    return q->body;
}
