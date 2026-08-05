//cpp
// decomp: module=unk_autoload_0 addr=0x02331dac name=FUN_02331dac

// Under the lock, tears down through FUN_02331bfc(1) and clears the halfword
// flag at G_023c0af0 if it was set.

#pragma thumb on
extern "C" {
extern int FUN_02332080(void);
extern void FUN_02331bfc(int);
extern void FUN_02332094(int);
extern unsigned short G_023c0af0[];
void FUN_02331dac(void)
{
    int v = FUN_02332080();
    if (G_023c0af0[0] != 0) {
        FUN_02331bfc(1);
        G_023c0af0[0] = 0;
    }
    FUN_02332094(v);
}
}
