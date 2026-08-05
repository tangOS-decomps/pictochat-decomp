// decomp: module=arm7 addr=0x022d70e4 name=FUN_022d70e4
// flags: -noThumb

// Copies four 0x14-byte blocks out of the 0x04805f80 register window into
// consecutive slots of `p`.

extern void FUN_037cb78c(int, void *, int);
int FUN_022d70e4(int p)
{
    FUN_037cb78c(p, (void *)0x04805f80, 0x14);
    FUN_037cb78c(p + 0x14, (void *)0x04805fa0, 0x14);
    FUN_037cb78c(p + 0x28, (void *)0x04805fc0, 0x14);
    FUN_037cb78c(p + 0x3c, (void *)0x04805fe0, 0x14);
    return 0;
}
