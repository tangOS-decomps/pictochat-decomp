//cpp
// decomp: module=unk_autoload_0 addr=0x02336728 name=FUN_02336728
#pragma thumb on
extern "C" int FUN_02336728(void)
{
    volatile int *disp = (volatile int *)0x04000000;
    volatile unsigned short *dispstat = (volatile unsigned short *)0x0400000c;

    int mode = *disp & 7;
    unsigned int stat = *dispstat;

    if (mode < 5 || (stat & 0x80) == 0) {
        return (((*(volatile unsigned int *)disp & 0x07000000) >> 24) << 16) +
               0x06000000 + (((stat & 0x3c) >> 2) << 14);
    }
    return 0;
}
