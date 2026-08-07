// decomp: module=unk_autoload_0 addr=0x02329d24 name=FUN_02329d24
#pragma thumb on
extern int FUN_0232996c(void);
extern unsigned short G_023bd60C[];

void FUN_02329d24(unsigned short v)
{
    if (FUN_0232996c() == 0 || FUN_0232996c() == 1)
        G_023bd60C[2] = v;
}
