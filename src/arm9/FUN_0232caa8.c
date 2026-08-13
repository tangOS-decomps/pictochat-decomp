// decomp: module=unk_autoload_0 addr=0x0232caa8 name=FUN_0232caa8

// Sibling of FUN_0232cae8 for channel 0: checks with FUN_0232c210, configures,
// runs FUN_0232c884, then submits with the three context words and `d`.

#pragma thumb on
extern int FUN_0232c210(int, int);
extern void FUN_0232c3bc(int, int);
extern void FUN_0232c884(void);
extern int *FUN_0232c4d0(void);
extern int FUN_0232c408(int, int, int, int, int, int);

int FUN_0232caa8(int a, int b, int c, int d)
{
    int r = FUN_0232c210(a, c);
    if (r == 0) {
        int *p;
        FUN_0232c3bc(0, b);
        FUN_0232c884();
        p = FUN_0232c4d0();
        r = FUN_0232c408(0, 4, p[0], p[1], p[4], d);
        if (r == 0) r = 2;
    }
    return r;
}
