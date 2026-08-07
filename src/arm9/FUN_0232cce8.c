// decomp: module=unk_autoload_0 addr=0x0232cce8 name=FUN_0232cce8
#pragma thumb on
extern int FUN_0232c520(int, int);
extern void FUN_0232c3bc(int, int);
extern int FUN_0232c408(int, int);

int FUN_0232cce8(int a)
{
    int r = FUN_0232c520(1, 5);
    if (r == 0) {
        FUN_0232c3bc(11, a);
        r = FUN_0232c408(11, 0);
        if (r == 0) r = 2;
    }
    return r;
}
