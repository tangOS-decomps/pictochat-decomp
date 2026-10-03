// decomp: module=arm7 addr=0x022d0a2c name=FUN_022d0a2c
// flags: -O4,s -noThumb

// Session-open counterpart of FUN_022d60b0: installs the caller's context
// block and state pointer into the manager slots at +0x54c/+0x550, seeds the
// context's first two words from the request, hands the word at +0x10 to
// FUN_022d5e9c, then reports over channel 0: (0, 1, a, b) when FUN_022d6158
// delivers the two results, else the state halfword is parked at 2 and the
// reply is (0, 0).

typedef struct {
    unsigned int f00;
    unsigned short **f04;
    unsigned short *f08;
    unsigned short *f0c;
    unsigned int f10;
} Req022d0a2c;

extern void *G_023190dc[];

extern unsigned short *FUN_037d14bc(void);
extern void FUN_037d1464(void);
extern void FUN_022d5e9c(unsigned int v);
extern int FUN_022d6158(unsigned short *a, unsigned short *b);

void FUN_022d0a2c(Req022d0a2c *q)
{
    unsigned short a;
    unsigned short b;
    unsigned short **s;
    unsigned short *v;
    unsigned short *ind;

    s = q->f04;
    G_023190dc[0x153] = (void *)s;
    v = q->f08;
    G_023190dc[0x154] = (void *)v;
    s[0] = v;
    s[2] = q->f0c;
    FUN_022d5e9c(q->f10);
    if (FUN_022d6158(&a, &b) == 0) {
        ind = FUN_037d14bc();
        ind[0] = 0;
        ind[1] = 1;
        ind[2] = a;
        ind[3] = b;
        FUN_037d1464();
    } else {
        *s[0] = 2;
        ind = FUN_037d14bc();
        ind[0] = 0;
        ind[1] = 0;
        FUN_037d1464();
    }
}
