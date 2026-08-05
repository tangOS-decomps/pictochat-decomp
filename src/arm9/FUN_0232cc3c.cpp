//cpp
// decomp: module=unk_autoload_0 addr=0x0232cc3c name=FUN_0232cc3c

// Opens channel 9 through slot 7 - the FUN_0232cb0c shape with different
// channel numbers.

#pragma thumb on
extern "C" {
extern int FUN_0232c520(int, int);
extern void FUN_0232c3bc(int, int);
extern int FUN_0232c408(int, int);
int FUN_0232cc3c(int a)
{
    int r = FUN_0232c520(1, 7);
    if (r == 0) {
        FUN_0232c3bc(9, a);
        r = FUN_0232c408(9, 0);
        if (r == 0) r = 2;
    }
    return r;
}
}
