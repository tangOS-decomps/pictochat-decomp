//cpp
// decomp: module=unk_autoload_0 addr=0x02336790 name=FUN_02336790

// Sub-engine BG1 character base getter - the FUN_02336764 shape with a two-sided
// mode range: the pointer is valid below mode 3, or below mode 6 when the BG1CNT
// bit-7 flag is clear.

#pragma thumb on
extern "C" {
void *FUN_02336790(void)
{
    int mode = *(volatile int *)0x04001000 & 7;
    unsigned int cnt = *(volatile unsigned short *)0x0400100e;
    if (mode < 3 || (mode < 6 && (cnt & 0x80) == 0))
        return (void *)(((cnt & 0x3c) >> 2) * 0x4000 + 0x06200000);
    return 0;
}
}
