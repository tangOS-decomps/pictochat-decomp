// decomp: module=arm7 addr=0x022d14e4 name=FUN_022d14e4
// flags: -noThumb

// Posts a type-9, length-1 message carrying two halfword arguments - the
// FUN_022d378c shape with a payload.

extern unsigned short *FUN_037d14bc(void);
extern void FUN_037d1464(void);
void FUN_022d14e4(unsigned short a, unsigned short b)
{
    unsigned short *p = FUN_037d14bc();
    p[0] = 9;
    p[1] = 1;
    p[2] = a;
    p[3] = b;
    FUN_037d1464();
}
