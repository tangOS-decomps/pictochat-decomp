// decomp: module=unk_autoload_0 addr=0x0233291c name=FUN_0233291c
#pragma thumb on
extern void FUN_02330a14(int a);
#pragma thumb off
extern void FUN_02332094(int a);
#pragma thumb on
void FUN_0233291c(int a, int *p)
{
    if (p[0] == 0)
        FUN_02330a14(a);
    FUN_02332094(p[1]);
}
