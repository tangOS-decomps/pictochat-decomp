// decomp: module=unk_autoload_0 addr=0x023368c0 name=FUN_023368c0
extern void FUN_02337240(int, int, int, unsigned int, int);
extern void FUN_02337454(int, int, unsigned int);
extern int G_0236a17c[];

void FUN_023368c0(int a, int b, unsigned int n, int d)
{
    if (G_0236a17c[0] != -1 && n > 0x30) {
        FUN_02337240(G_0236a17c[0], a, b + 0x07000000, n, 1);
        return;
    }
    FUN_02337454(a, b + 0x07000000, n);
}
