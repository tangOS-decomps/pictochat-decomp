// decomp: module=arm7 addr=0x022d8c98 name=FUN_022d8c98
// flags: -noThumb

extern void *FUN_037fea3c(void *, void *, int);

void *FUN_022d8c98(void *a0, void *a1, int a2)
{
    return FUN_037fea3c(a1, a0, (a2 + 1) & ~1);
}
