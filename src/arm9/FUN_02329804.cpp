//cpp
// decomp: module=unk_autoload_0 addr=0x02329804 name=FUN_02329804

// Sets the state word at G_023bd5e0+8 to 1, then runs FUN_02329a5c and
// FUN_023298d8(0).

#pragma thumb on
extern "C" {
extern void FUN_02329a5c(void);
extern void FUN_023298d8(int);
extern int G_023bd5e0[];
void FUN_02329804(void)
{
    G_023bd5e0[2] = 1;
    FUN_02329a5c();
    FUN_023298d8(0);
}
}
