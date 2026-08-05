//cpp
// decomp: module=unk_autoload_0 addr=0x02329ad4 name=FUN_02329ad4

// Registers FUN_02329af4 through FUN_0232cb0c, reporting a fault and returning 0
// when the registration does not return 2.

#pragma thumb on
extern "C" {
extern int FUN_0232cb0c(void (*)(void));
extern void FUN_02329bd8(int);
extern void FUN_02329af4(void);
int FUN_02329ad4(void)
{
    if (FUN_0232cb0c(FUN_02329af4) != 2) {
        FUN_02329bd8(0xc);
        return 0;
    }
    return 1;
}
}
