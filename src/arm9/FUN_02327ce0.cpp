//cpp
// decomp: module=unk_autoload_0 addr=0x02327ce0 name=FUN_02327ce0
#pragma thumb on
extern "C" {
extern int FUN_023271c0(int, int);
extern void FUN_02320978(int);
extern int FUN_023212ec(void);
extern int FUN_023212f8(void);
extern int FUN_02321304(void);
extern int FUN_0232e004(int *, int, int);
extern int G_0233b4d8[];
void FUN_02327ce0(void)
{
    if (FUN_023271c0(-8, 1) != 0) {
        FUN_02320978(0xc);
        return;
    }
    if (FUN_023212ec() == 1) {
        int a = FUN_023212f8();
        int b = FUN_02321304();
        if (FUN_0232e004(G_0233b4d8, a, b) == 3) {
            FUN_02320978(0xf);
        }
    }
}
}
