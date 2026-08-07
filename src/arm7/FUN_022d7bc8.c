// decomp: module=arm7 addr=0x022d7bc8 name=FUN_022d7bc8
// flags: -noThumb

// Copies the two halfwords of `a` into the pair at +0x3a4 of the ARM7 state
// block - the second slot getting the OR of both - then kicks FUN_022d7c08.

extern void FUN_022d7c08(void);

int FUN_022d7bc8(unsigned short *a)
{
    int s = *(int *)0x0380fff4;
    unsigned short *q;

    *(unsigned short *)(s + 0x3a4) = a[0];
    q = (unsigned short *)(s + 0x3a4);
    q[1] = a[1] | a[0];
    FUN_022d7c08();
    return 0;
}
