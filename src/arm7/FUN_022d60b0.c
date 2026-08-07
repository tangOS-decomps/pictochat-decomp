// decomp: module=arm7 addr=0x022d60b0 name=FUN_022d60b0
// flags: -O4,s -noThumb

// Answers a status query on the shared indication channel. When the session
// word is not 1 the reply is (5, 3); otherwise FUN_022d6158 is asked for the
// two u16 results and the reply is either (5, 1, a, b) or, after parking the
// session word at 2, (5, 0).

extern void *FUN_037d14bc(void);
extern void FUN_037d1464(void *ind);
extern int FUN_022d6158(unsigned short *a, unsigned short *b);

extern void *G_023190dc[];

void FUN_022d60b0(void)
{
    unsigned short a;
    unsigned short b;
    unsigned short *state = (unsigned short *)G_023190dc[0x154];
    unsigned short *ind;

    if (*state != 1) {
        ind = (unsigned short *)FUN_037d14bc();
        ind[0] = 5;
        ind[1] = 3;
        FUN_037d1464(ind);
    } else if (FUN_022d6158(&a, &b) == 0) {
        ind = (unsigned short *)FUN_037d14bc();
        ind[0] = 5;
        ind[1] = 1;
        ind[2] = a;
        ind[3] = b;
        FUN_037d1464(ind);
    } else {
        *state = 2;
        ind = (unsigned short *)FUN_037d14bc();
        ind[0] = 5;
        ind[1] = 0;
        FUN_037d1464(ind);
    }
}
