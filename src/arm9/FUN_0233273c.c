// decomp: module=unk_autoload_0 addr=0x0233273c name=FUN_0233273c
#pragma thumb on

extern int FUN_0233831c(int cmd, int arg, int flag);
extern void FUN_02332d10(int arg);

void FUN_0233273c(int param_1, int param_2)
{
    while (FUN_0233831c(0xe, param_1, 0) != 0) {
        FUN_02332d10(param_2);
    }
}
