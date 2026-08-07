// decomp: module=arm7 addr=0x022c5584 name=FUN_022c5584
// flags: -noThumb

// The release half of FUN_022c554c: under the same critical section it drops
// the refcount word at G_03804f68[1] by one and hands back the pre-decrement
// value. Unlike the acquire side the "already at the floor" answer is a
// defined 0. The interrupt state from FUN_022c6d40 rides in r0 untouched all
// the way to FUN_022c6d54, which is what keeps r0 out of the temp pool and
// shifts every other allocation up one register.

extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int);
extern unsigned int G_03804f68[];

unsigned int FUN_022c5584(void)
{
    unsigned int old;
    int e = FUN_022c6d40();
    old = 0;
    if (G_03804f68[1] != 0) {
        old = G_03804f68[1];
        G_03804f68[1] = old - 1;
    }
    FUN_022c6d54(e);
    return old;
}
