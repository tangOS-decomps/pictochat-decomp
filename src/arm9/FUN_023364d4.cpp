//cpp
// decomp: module=unk_autoload_0 addr=0x023364d4 name=FUN_023364d4

// Sub-engine BG3 screen base - the FUN_0233648c shape against BG3CNT.

#pragma thumb on
extern "C" {
void *FUN_023364d4(void)
{
    return (void *)(((*(volatile unsigned short *)0x0400100a & 0x1f00) >> 8) * 0x800 + 0x06200000);
}
}
