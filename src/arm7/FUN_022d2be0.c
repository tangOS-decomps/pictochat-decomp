// decomp: module=arm7 addr=0x022d2be0 name=FUN_022d2be0
extern unsigned short *FUN_037d14bc(void);
extern void FUN_037d1464(void);

void FUN_022d2be0(unsigned short a, unsigned short b, unsigned short c, unsigned short d)
{
    unsigned short *p = FUN_037d14bc();
    p[0] = 0x25;
    p[1] = 1;
    p[2] = a;
    p[3] = b;
    p[4] = c;
    p[5] = d;
    FUN_037d1464();
}
