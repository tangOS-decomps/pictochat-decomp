//cpp
// decomp: module=unk_autoload_0 addr=0x02322420 name=FUN_02322420

// True when `a` equals the first word of entry `i` of the 0x54-byte table at
// G_0238e134.

#pragma thumb on
extern "C" {
extern char G_0238e134[];
int FUN_02322420(int a, int i)
{
    if (a == *(int *)(G_0238e134 + i * 0x54)) return 1;
    return 0;
}
}
