//cpp
// decomp: module=unk_autoload_0 addr=0x0232ade8 name=FUN_0232ade8

// Registers FUN_0232ae14 through FUN_0232cc30, zeroing the field at
// G_023bd698+0x58 before registering.

#pragma thumb on
extern "C" {
extern int FUN_02329c00(void);
extern int FUN_0232cc30(void (*)(void), int);
extern void FUN_02329bd8(int);
extern void FUN_0232ae14(void);
extern int G_023bd698[];
void FUN_0232ade8(void)
{
    if (FUN_02329c00() == 0)
    {
        G_023bd698[0x16] = 0;
        if (FUN_0232cc30(FUN_0232ae14, 0) != 2)
            FUN_02329bd8(0xc);
    }
}
}
