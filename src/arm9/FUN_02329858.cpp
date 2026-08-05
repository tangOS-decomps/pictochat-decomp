//cpp
// decomp: module=unk_autoload_0 addr=0x02329858 name=FUN_02329858

// Clears the state word at G_023bd5e0+8 and re-arms the FUN_02329b70 callback,
// but only while FUN_0232996c reports active.

#pragma thumb on
extern "C" {
extern int FUN_0232996c(void);
extern void FUN_02329b2c(void (*)(void), int);
extern void FUN_02329b70(void);
extern int G_023bd5e0[];
void FUN_02329858(void)
{
    if (FUN_0232996c() != 0) {
        G_023bd5e0[2] = 0;
        FUN_02329b2c(FUN_02329b70, 1);
    }
}
}
