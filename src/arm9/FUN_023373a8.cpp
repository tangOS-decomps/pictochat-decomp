//cpp
// decomp: module=unk_autoload_0 addr=0x023373a8 name=FUN_023373a8

// Calls FUN_02337358 for channels 0 through 3.

#pragma thumb on
extern "C" {
extern void FUN_02337358(int);
void FUN_023373a8(void)
{
    FUN_02337358(0);
    FUN_02337358(1);
    FUN_02337358(2);
    FUN_02337358(3);
}
}
