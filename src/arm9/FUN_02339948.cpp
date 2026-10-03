//cpp
// decomp: module=unk_autoload_0 addr=0x02339948 name=FUN_02339948
#pragma thumb on
extern "C" {
extern unsigned int FUN_02332080(void);
extern void FUN_02332094(unsigned int);
extern int FUN_02339e6c(void);
extern int G_023c35a0[];

int FUN_02339948(int a, int b, int c, int d)
{
    unsigned int key = FUN_02332080();

    if (G_023c35a0[1] != 0) {
        FUN_02332094(key);
        return 1;
    }

    G_023c35a0[1] = 1;
    FUN_02332094(key);

    G_023c35a0[6] = 2;
    G_023c35a0[7] = 0;
    G_023c35a0[3] = a;
    G_023c35a0[4] = b;
    G_023c35a0[2] = c;
    G_023c35a0[5] = d;

    if (FUN_02339e6c() != 0)
        return 0;

    G_023c35a0[1] = 0;
    return 3;
}
}
