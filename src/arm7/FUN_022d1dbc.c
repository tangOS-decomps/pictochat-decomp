// decomp: module=arm7 addr=0x022d1dbc name=FUN_022d1dbc
extern unsigned short *FUN_037d14bc(void);
extern void FUN_037d1464(void);

void FUN_022d1dbc(unsigned short a, unsigned short b, int c)
{
    unsigned short *p = FUN_037d14bc();
    p[0] = c ? 0x26 : 0xa;
    p[1] = 1;
    p[4] = 4;
    p[2] = a;
    p[3] = b;
    FUN_037d1464();
}
