// decomp: module=unk_autoload_0 addr=0x0232cae8 name=FUN_0232cae8
#pragma thumb on
extern int FUN_0232c4f0(int);
extern void FUN_0232c3bc(int, int);
extern int FUN_0232c408(int, int);

int FUN_0232cae8(int a)
{
    int r = FUN_0232c4f0(a);
    if (r == 0) {
        FUN_0232c3bc(1, a);
        r = FUN_0232c408(1, 0);
        if (r == 0) r = 2;
    }
    return r;
}
