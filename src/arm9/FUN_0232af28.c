// decomp: module=unk_autoload_0 addr=0x0232af28 name=FUN_0232af28
#pragma thumb on

extern int FUN_02329c00(void);
extern int FUN_0232cd10(void (*)(void), int, int, int, int);
extern void FUN_02329bd8(int);
extern void FUN_0232af58(void);

void FUN_0232af28(int a)
{
    if (FUN_02329c00() == 0 && FUN_0232cd10(FUN_0232af58, a, 0, 1, 0) != 2)
        FUN_02329bd8(0xc);
}
