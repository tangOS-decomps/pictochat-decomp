// decomp: module=arm7 addr=0x022c5504 name=FUN_022c5504
// flags: -O4,s -noThumb

// Installs `p` into slot 10 of the table at G_03804f68 under the usual
// interrupt-off critical section and hands back whatever was there before.
// The interrupt state from FUN_022c6d40 rides in r0 untouched all the way to
// FUN_022c6d54, which keeps r0 out of the temp pool and pushes the argument
// and the saved old value into r5/r4.

extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);

extern void *G_03804f68[];

void *FUN_022c5504(void *p)
{
    int state = FUN_022c6d40();
    void *old = G_03804f68[10];

    G_03804f68[10] = p;
    FUN_022c6d54(state);
    return old;
}
