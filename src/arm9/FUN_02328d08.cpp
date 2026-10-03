//cpp
// decomp: module=unk_autoload_0 addr=0x02328d08 name=FUN_02328d08
#pragma thumb on
extern "C" {
extern void FUN_02328d60(int, int);
extern void FUN_02328d80(int, int);
extern void FUN_02336444(void *, int, int);

void FUN_02328d08(int enabled)
{
    if (enabled != 0) {
        volatile unsigned int *reg = (volatile unsigned int *)0x04001000;
        *reg = (*reg & 0xffff1fffU) | 0x8000;

        FUN_02328d60(0x1f, 1);
        FUN_02328d80(0x1f, 0);
        FUN_02336444((void *)0x04001050, 0x3f, -7);
        return;
    }

    FUN_02328d60(0x1f, 1);
    FUN_02328d80(0x1f, 1);
    *(volatile unsigned short *)0x04001050 = 0;
}
}
