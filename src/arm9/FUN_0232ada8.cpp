//cpp
// decomp: module=unk_autoload_0 addr=0x0232ada8 name=FUN_0232ada8

// Registers FUN_0232add0 through FUN_0232cb34, passing the field at
// G_023bd698+0x50 as the argument.

#pragma thumb on
extern "C" {
extern int FUN_02329c00(void);
extern int FUN_0232cb34(void (*)(void), int);
extern void FUN_02329bd8(int);
extern void FUN_0232add0(void);
extern int G_023bd698[];
void FUN_0232ada8(void)
{
    if (FUN_02329c00() == 0 && FUN_0232cb34(FUN_0232add0, G_023bd698[0x14]) != 2)
        FUN_02329bd8(0xc);
}
}
