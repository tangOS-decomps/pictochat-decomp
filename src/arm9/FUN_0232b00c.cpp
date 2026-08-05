//cpp
// decomp: module=unk_autoload_0 addr=0x0232b00c name=FUN_0232b00c

// Registers FUN_0232b030 through FUN_0232cd94 and reports a fault when the
// registration does not return 2. The pool word is the Thumb address of the
// immediately following function.

#pragma thumb on
extern "C" {
extern int FUN_02329c00(void);
extern int FUN_0232cd94(void (*)(void), int);
extern void FUN_02329bd8(int);
extern void FUN_0232b030(void);
void FUN_0232b00c(int a)
{
    if (FUN_02329c00() == 0 && FUN_0232cd94(FUN_0232b030, a) != 2)
        FUN_02329bd8(0xc);
}
}
