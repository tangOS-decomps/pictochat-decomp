//cpp
// decomp: module=unk_autoload_0 addr=0x023301a0 name=FUN_023301a0

// Runs FUN_0233791c(0) when the flag at G_02369d18 is 1, then FUN_0232f050
// unconditionally.

#pragma thumb on
extern "C" {
extern void FUN_0233791c(int);
extern void FUN_0232f050(void);
extern int G_02369d18[];
void FUN_023301a0(void)
{
    if (G_02369d18[0] == 1) FUN_0233791c(0);
    FUN_0232f050();
}
}
