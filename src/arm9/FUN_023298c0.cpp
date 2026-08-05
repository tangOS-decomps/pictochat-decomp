//cpp
// decomp: module=unk_autoload_0 addr=0x023298c0 name=FUN_023298c0

// Registers FUN_02329b70 through FUN_02329b2c when FUN_0232996c reports
// non-zero - the callback-pool-word shape of FUN_0232a16c.

#pragma thumb on
extern "C" {
extern int FUN_0232996c(void);
extern void FUN_02329b2c(void (*)(void), int);
extern void FUN_02329b70(void);
void FUN_023298c0(void)
{
    if (FUN_0232996c() != 0) FUN_02329b2c(FUN_02329b70, 1);
}
}
