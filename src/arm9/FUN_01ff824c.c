// decomp: module=itcm addr=0x01ff824c name=FUN_01ff824c
extern int FUN_02339250(int, int, int, int, int);
extern void FUN_02332080(void);

int FUN_01ff824c(void)
{
    int zero = 0;

    if (FUN_02339250(0x15, zero, zero, zero, zero) == 0) {
        FUN_02332080();
        for (;;) {}
    }
    return 1;
}
