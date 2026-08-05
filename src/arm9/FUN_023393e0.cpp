//cpp
// decomp: module=unk_autoload_0 addr=0x023393e0 name=FUN_023393e0

// Drains FUN_023393b0 until it stops reporting work, then returns 0.

#pragma thumb on
extern "C" {
extern int FUN_023393b0(void);
int FUN_023393e0(void)
{
    int r;
    do { r = FUN_023393b0(); } while (r != 0);
    return 0;
}
}
