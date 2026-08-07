// decomp: module=unk_autoload_0 addr=0x0232cbf4 name=FUN_0232cbf4
extern int FUN_0232c520(int, int);
extern void *FUN_0232c4d0(void);
extern void FUN_0232c3bc(int, int);
extern int FUN_0232c408(int, int, int);

int FUN_0232cbf4(int a, int b)
{
    int r = FUN_0232c520(1, 2);
    if (r == 0) {
        char *p = FUN_0232c4d0();
        *(short *)(p + 0x150) = 0;
        *(int *)(p + 0x14c) = 0;
        FUN_0232c3bc(8, a);
        r = FUN_0232c408(8, 1, b);
        if (r == 0) r = 2;
    }
    return r;
}
