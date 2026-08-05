//cpp
// decomp: module=unk_autoload_0 addr=0x02322cb8 name=FUN_02322cb8

// True when G_0233ae40 holds -1. The ROM builds the -1 with `mvns` rather than
// loading it.

#pragma thumb on
extern "C" {
extern int G_0233ae40[];
int FUN_02322cb8(void)
{
    if (G_0233ae40[0] == -1) return 1;
    return 0;
}
}
