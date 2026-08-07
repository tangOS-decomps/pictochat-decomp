// decomp: module=arm7 addr=0x022c5dfc name=FUN_022c5dfc
// flags: -O4,s -noThumb

// Atomically swaps the word pointed at by slot `i` of the pointer table at
// G_03805168 and hands back the previous value. The interrupt state from
// FUN_022c6d40 rides in r0 untouched all the way to FUN_022c6d54.
// NOTE: verify with --size 0x34, not funcs.json's 0x30 - the boundary excludes
// this function's own trailing pool word.

extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);

extern int *G_03805168[];

int FUN_022c5dfc(int i, int value)
{
    int state = FUN_022c6d40();
    int *slot = G_03805168[i];
    int old = *slot;

    *slot = value;
    FUN_022c6d54(state);
    return old;
}
