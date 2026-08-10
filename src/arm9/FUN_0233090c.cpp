//cpp
// decomp: module=unk_autoload_0 addr=0x0233090c name=FUN_0233090c
#pragma thumb on
extern "C" {
extern int FUN_023309a4(int, int, int, int);
extern void FUN_02332d10(int);
void FUN_0233090c(int a, int b, int c, int d)
{
    while (FUN_023309a4(a, b, c, d) > 0) {
        FUN_02332d10(0x400);
    }
}
}
