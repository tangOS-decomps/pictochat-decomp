// decomp: module=unk_autoload_0 addr=0x023367c0 name=FUN_023367c0
extern void FUN_023372b0(int, int, int, unsigned int, int);
extern void FUN_02337424(int, int, unsigned int);
extern int G_0236a17c[];

void FUN_023367c0(int a, int b, unsigned int n, int d)
{
    if (G_0236a17c[0] != -1 && n > 0x1c) {
        FUN_023372b0(G_0236a17c[0], a, b + 0x05000000, n, 1);
        return;
    }
    FUN_02337424(a, b + 0x05000000, n);
}
