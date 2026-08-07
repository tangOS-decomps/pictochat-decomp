// decomp: module=arm7 addr=0x022d0eac name=FUN_022d0eac
extern unsigned short *FUN_037d14bc(void);
extern void FUN_037d1464(void);
void FUN_022d0eac(unsigned short a, unsigned short b)
{
    unsigned short *p = FUN_037d14bc();
    p[0] = 1;
    p[1] = 1;
    p[2] = a;
    p[3] = b;
    FUN_037d1464();
}
