//cpp
// decomp: module=unk_autoload_0 addr=0x0233210c name=FUN_0233210c

// Two-step init: FUN_02332d10(1) then FUN_023305e8(1, 1).

#pragma thumb on
extern "C" {
extern void FUN_02332d10(int);
extern void FUN_023305e8(int, int);
void FUN_0233210c(void)
{
    FUN_02332d10(1);
    FUN_023305e8(1, 1);
}
}
