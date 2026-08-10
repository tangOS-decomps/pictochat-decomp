//cpp
// decomp: module=unk_autoload_0 addr=0x02336310 name=FUN_02336310
#pragma thumb on
extern "C" unsigned int FUN_02336310(int enabled)
{
    volatile unsigned short *reg = (volatile unsigned short *)0x04000004;
    unsigned int old = *reg & 8;
    if (enabled != 0) {
        *reg = *reg | 8;
    } else {
        *reg = *reg & ~8;
    }
    return old;
}
