//cpp
// decomp: module=unk_autoload_0 addr=0x02332670 name=FUN_02332670

// Resets the three-word block at G_023c1300 and re-registers FUN_02332698 on
// vector 0xe. The third word is cleared after the registration, not with the
// other two.

#pragma thumb on
extern "C" {
extern void FUN_023381f8(void);
extern void FUN_023382ac(int, void (*)(void));
extern void FUN_02332698(void);
extern int G_023c1300[];
void FUN_02332670(void)
{
    FUN_023381f8();
    G_023c1300[0] = 0;
    G_023c1300[1] = 0;
    FUN_023382ac(0xe, FUN_02332698);
    G_023c1300[2] = 0;
}
}
