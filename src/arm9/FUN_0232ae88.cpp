//cpp
// decomp: module=unk_autoload_0 addr=0x0232ae88 name=FUN_0232ae88

// The FUN_0232a16c shape without the FUN_02329c00 guard, registering
// FUN_0232aea0 through FUN_0232cc3c.

#pragma thumb on
extern "C" {
extern int FUN_0232cc3c(void (*)(void));
extern void FUN_02329bd8(int);
extern void FUN_0232aea0(void);
void FUN_0232ae88(void)
{
    if (FUN_0232cc3c(FUN_0232aea0) != 2) FUN_02329bd8(0xc);
}
}
