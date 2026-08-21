// decomp: module=unk_autoload_0 addr=0x023213b4 name=FUN_023213b4
#pragma thumb on

extern int FUN_02321a94(int);
extern void FUN_023217ec(void *, int, int, int, int, int, int, int);

void FUN_023213b4(void *a, int b, int c, int d)
{
    int r = FUN_02321a94(d);
    FUN_023217ec(a, b, c, r, d, 0, 1, -1);
}
