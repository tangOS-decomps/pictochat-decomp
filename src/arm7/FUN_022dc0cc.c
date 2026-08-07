// decomp: module=arm7 addr=0x022dc0cc name=FUN_022dc0cc
// flags: -O4,p -noThumb

extern unsigned char *G_0380fff4;
extern void FUN_037fea24(int, void *, int);

void FUN_022dc0cc(void)
{
    FUN_037fea24(0, G_0380fff4 + 0x404, 0x20);
}
