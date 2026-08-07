// decomp: module=arm7 addr=0x022d24b8 name=FUN_022d24b8
extern unsigned short *FUN_037d14bc(void);
extern void FUN_037d1464(void);

void FUN_022d24b8(unsigned short a, unsigned short b, unsigned short c)
{
    unsigned short *p = FUN_037d14bc();
    p[0] = 12;
    p[1] = 1;
    p[2] = a;
    p[3] = b;
    p[7] = c;
    FUN_037d1464();
}
