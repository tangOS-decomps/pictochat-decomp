// decomp: module=arm7 addr=0x022d378c name=FUN_022d378c
// flags: -noThumb

// Posts a type-0x1a, length-4 message into the buffer returned by the external
// allocator at 0x037d14bc and sends it.

extern unsigned short *FUN_037d14bc(void);
extern void FUN_037d1464(void);
void FUN_022d378c(void)
{
    unsigned short *p = FUN_037d14bc();
    p[0] = 0x1a;
    p[1] = 4;
    FUN_037d1464();
}
