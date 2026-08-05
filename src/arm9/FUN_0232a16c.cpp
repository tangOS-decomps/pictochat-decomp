//cpp
// decomp: module=unk_autoload_0 addr=0x0232a16c name=FUN_0232a16c

// Registers FUN_0232a18c as a callback through FUN_0232cce8 and reports a fault
// via FUN_02329bd8(0xc) if registration does not return 2. Registration is only
// attempted when FUN_02329c00 reports zero.
//
// The pool word is the Thumb address of the immediately following function, so
// the argument is that function itself, not data.

#pragma thumb on
extern "C" {
extern int FUN_02329c00(void);
extern int FUN_0232cce8(void (*)(void));
extern void FUN_02329bd8(int);
extern void FUN_0232a18c(void);
void FUN_0232a16c(void)
{
    if (FUN_02329c00() == 0 && FUN_0232cce8(FUN_0232a18c) != 2)
        FUN_02329bd8(0xc);
}
}
