// decomp: module=unk_autoload_0 addr=0x0232d050 name=FUN_0232d050

// Sibling of FUN_0232cb0c for channel 0x10: claims (2, 9, 0xa), invalidates
// the context word at ctx[1]+0xc and reports 3 when it stayed null, otherwise
// configures with `a` and submits.

#pragma thumb on
extern int *FUN_0232c4d0(void);
extern int FUN_0232c520(int, int, int);
extern void FUN_023314cc(void *, int);
extern void FUN_0232c3bc(int, int);
extern int FUN_0232c408(int, int);

int FUN_0232d050(int a)
{
    int *p;
    int r;

    p = FUN_0232c4d0();
    r = FUN_0232c520(2, 9, 0xa);
    if (r == 0) {
        FUN_023314cc((int *)p[1] + 3, 4);
        if (*((int *)p[1] + 3) == 0) {
            return 3;
        }
        FUN_0232c3bc(0x10, a);
        r = FUN_0232c408(0x10, 0);
        if (r == 0) r = 2;
    }
    return r;
}
