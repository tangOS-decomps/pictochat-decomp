// decomp: module=arm7 addr=0x022df73c name=FUN_022df73c
// flags: -O4,s -noThumb
//
// Allocates a 0x5e-byte request block out of the heap at G_0380fff4+0x188 and
// builds a variable-length body at +0x40 from two serialisers; the resulting
// body length (+4) becomes the header length at +0x16 and the frame length at
// +0x22.  Returns the body pointer at +0x10, or 0 on allocation failure.
// Verify with size 0xa8, not 0xa0 - the stated size excludes the two trailing
// pool words (0x0380fff4 and 0x0000ffff).

extern void *G_0380fff4;

extern void *FUN_037c58fc(void *heap, int size);
extern void FUN_022d9088(int code);
extern void FUN_022dffc4(void *body, int dest);
extern int FUN_022e0078(void *dst);
extern int FUN_022e00ec(void *dst);

void *FUN_022df73c(int dest) {
    char *base = (char *)G_0380fff4;
    char *chan;
    char *p;
    int n;

    chan = base + 0x344;
    p = (char *)FUN_037c58fc(base + 0x188, 0x5e);
    if (p == 0) {
        FUN_022d9088(2);
        return p;
    }

    *(unsigned short *)(p + 0xc) = 0xffff;
    FUN_022dffc4(p + 0x10, dest);
    *(unsigned short *)(p + 0x3c) = *(unsigned short *)(chan + 0x7c);
    *(unsigned short *)(p + 0x3e) = *(unsigned short *)(chan + 0x70);
    n = FUN_022e0078(p + 0x40);
    *(unsigned short *)(p + 0x16) = n + FUN_022e00ec(p + 0x40 + n) + 4;
    *(unsigned short *)(p + 0x22) = *(unsigned short *)(p + 0x16) + 0x1c;
    *(unsigned short *)(p + 0x24) = 0;
    return p + 0x10;
}
