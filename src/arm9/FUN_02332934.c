// decomp: module=unk_autoload_0 addr=0x02332934 name=FUN_02332934
#pragma thumb on

extern int FUN_0233831c(int cmd, int arg, int flag);
extern void FUN_02332d10(int arg);

void FUN_02332934(int param_1)
{
    while (FUN_0233831c(0xd, param_1, 0) != 0) {
        FUN_02332d10(1);
    }
}
