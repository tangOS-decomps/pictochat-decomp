// decomp: module=unk_autoload_0 addr=0x02336b50 name=FUN_02336b50
#pragma thumb on
extern void *FUN_023365d8(void);
extern void FUN_023372b0(int, int, int, unsigned int, int);
extern void FUN_02337424(int, int, unsigned int);
extern int G_0236a17c[];

void FUN_02336b50(int a, int b, unsigned int n, int d)
{
    void *p = FUN_023365d8();
    if (G_0236a17c[0] != -1 && n > 0x1c) {
        FUN_023372b0(G_0236a17c[0], a, (int)p + b, n, 1);
        return;
    }
    FUN_02337424(a, (int)p + b, n);
}
