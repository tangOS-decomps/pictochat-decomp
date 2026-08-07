// decomp: module=arm7 addr=0x022c2f98 name=FUN_022c2f98
// flags: -noThumb

// Runs the same probe over the two sub-blocks that live at +0x47c and +0x490
// of the ARM7 state block (both hang off the common +0x42c base) and ORs the
// two answers together - "either of the pair reports set".

extern int FUN_00dd5080(void *);

int FUN_022c2f98(void)
{
    char *p = (char *)*(int *)0x0380fff4 + 0x42c;
    int a = FUN_00dd5080(p + 0x50);
    return a | FUN_00dd5080(p + 0x64);
}
