//cpp
// decomp: module=unk_autoload_0 addr=0x0232cb0c name=FUN_0232cb0c

// Opens channel 2: claims it through FUN_0232c520, configures it with `a`, then
// reports 2 when the configure step returns 0.

#pragma thumb on
extern "C" {
extern int FUN_0232c520(int, int);
extern void FUN_0232c3bc(int, int);
extern int FUN_0232c408(int, int);
int FUN_0232cb0c(int a)
{
    int r = FUN_0232c520(1, 2);
    if (r == 0) {
        FUN_0232c3bc(2, a);
        r = FUN_0232c408(2, 0);
        if (r == 0) r = 2;
    }
    return r;
}
}
