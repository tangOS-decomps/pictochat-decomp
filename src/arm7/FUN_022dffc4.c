// decomp: module=arm7 addr=0x022dffc4 name=FUN_022dffc4
// flags: -O4,s -noThumb
//
// Zeroes the 0x2c-byte record at `p`, stamps its +0x10 halfword with the
// timing value from FUN_022d85b4, then arms the sub-object at +0x18 with
// FUN_022d816c, handing it the caller's argument plus two fields of the
// object behind the global at 0x0380fff4 (+0x324 and +0x3a8).

extern void func_037cb774(int value, void *dst, int size);
extern int FUN_022d85b4(void);
extern void FUN_022d816c(void *dst, void *arg, void *a, void *b);

extern char *G_0380fff4;

void FUN_022dffc4(void *p, void *arg)
{
    char *base;

    func_037cb774(0, p, 0x2c);
    *(unsigned short *)((char *)p + 0x10) = FUN_022d85b4();

    base = G_0380fff4;
    FUN_022d816c((char *)p + 0x18, arg, base + 0x324, base + 0x3a8);
}
