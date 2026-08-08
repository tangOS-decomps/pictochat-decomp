//cpp
// decomp: module=unk_autoload_0 addr=0x02339034 name=FUN_02339034
// verify: python tools/match.py --c src/arm9/FUN_02339034.cpp --func FUN_02339034 --addr 0x02339034 --size 0x28 --module unk_autoload_0 --version 2.0/sp1

// Test-and-set of the busy word at G_023c3564+0x2c.

#pragma thumb on
extern "C" {
extern int FUN_02332080(void);
extern void FUN_02332094(int);
extern int G_023c3564[];
int FUN_02339034(void)
{
    int s = FUN_02332080();

    if (G_023c3564[11] != 0) {
        FUN_02332094(s);
        return 0;
    }
    G_023c3564[11] = 1;
    FUN_02332094(s);
    return 1;
}
}
