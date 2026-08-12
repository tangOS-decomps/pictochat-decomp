// decomp: module=unk_autoload_0 addr=0x023398b0 name=FUN_023398b0
#pragma thumb on

extern void FUN_023320fc(int value);
extern int FUN_02339794(void);
extern int FUN_02339374(int type, int value);
extern int FUN_02339780(int value);

void FUN_023398b0(void)
{
    int type = 2;
    int value = 0;

    FUN_023320fc(0x360000);
    if (FUN_02339794() == 1)
        return;

    while (FUN_02339374(type, value) != 0)
        ;

    if (FUN_02339780(1) != 0)
        return;

    type = 5;
    value = 1;
    do {
        FUN_023320fc(type);
    } while (FUN_02339780(value) == 0);
}
