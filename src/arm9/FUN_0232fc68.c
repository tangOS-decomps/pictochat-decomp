// decomp: module=unk_autoload_0 addr=0x0232fc68 name=FUN_0232fc68
#pragma thumb on

extern int FUN_023381cc(int c, int d);
extern void FUN_023381ac(int c, int d, int e);
extern void FUN_023378ac(int a, int b);

void FUN_0232fc68(int a, int b, int c, int d) {
    if (a == FUN_023381cc(c, d)) {
        FUN_023381ac(c, d, 0);
    }
    FUN_023378ac(a, a + b);
}
