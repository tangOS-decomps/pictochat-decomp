// decomp: module=arm7 addr=0x022c554c name=FUN_022c554c
// flags: -noThumb

// Takes the global lock and bumps the refcount word at G_03804f68[1], but only
// while it is short of saturation, returning its pre-increment value. On the
// saturated path nothing is stored and the result is left undefined - which is
// exactly why the ROM's `mov r4, r3` is conditional and r4 has no initialiser.
// The interrupt state from FUN_022c6d40 rides in r0 untouched all the way to
// FUN_022c6d54, which keeps r0 out of the temp pool and shifts every other
// allocation up one register.

extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int);
extern unsigned int G_03804f68[];

unsigned int FUN_022c554c(void)
{
    unsigned int old;
    int e = FUN_022c6d40();
    if (G_03804f68[1] < 0xffffffff) {
        old = G_03804f68[1];
        G_03804f68[1] = old + 1;
    }
    FUN_022c6d54(e);
    return old;
}
