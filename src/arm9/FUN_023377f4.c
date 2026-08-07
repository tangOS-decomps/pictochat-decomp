// decomp: module=unk_autoload_0 addr=0x023377f4 name=FUN_023377f4
#pragma thumb on

extern int FUN_02337e68(int a, int b, int c, int d);
extern void FUN_02337930(int op, int a, int b, int c, int d);

void FUN_023377f4(int a, int b, int c, int d, int e)
{
    int t = FUN_02337e68(a, d, e, d);
    FUN_02337930(0x12, a, b, c, t);
}
