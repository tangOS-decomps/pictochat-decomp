// decomp: module=unk_autoload_0 addr=0x0232a0b8 name=FUN_0232a0b8
#pragma thumb on
extern int FUN_02329c00(void);
extern void FUN_02329e9c(void);
extern int FUN_0232cc64(void (*)(void), int);
extern void FUN_02329bd8(int);
extern void FUN_0232a0e4(void);
extern int G_023bd60c[];

void FUN_0232a0b8(void)
{
    if (FUN_02329c00() == 0 && (FUN_02329e9c(), FUN_0232cc64(FUN_0232a0e4, G_023bd60c[6]) != 2))
        FUN_02329bd8(0xc);
}
