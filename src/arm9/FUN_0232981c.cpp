//cpp
// decomp: module=unk_autoload_0 addr=0x0232981c name=FUN_0232981c
// verify: python tools/match.py --c src/arm9/FUN_0232981c.cpp --func FUN_0232981c --addr 0x0232981c --size 0x3c --module unk_autoload_0 --version 2.0/sp1

// Busy test: reports 1 outright while the +0x10 word is set, otherwise runs
// the per-mode step (1/2/3) and reports 1, or 0 when the mode is idle.

#pragma thumb on
extern "C" {
extern void FUN_023298c0(void);
extern void FUN_02329858(void);
extern void FUN_0232987c(void);
extern int G_023bd5e0[];
int FUN_0232981c(void)
{
    int r = 0;
    if (G_023bd5e0[4] != 0) {
        r = 1;
    } else {
        switch (G_023bd5e0[6]) {
        case 1:
            FUN_023298c0();
            r = 1;
            break;
        case 2:
            FUN_02329858();
            r = 1;
            break;
        case 3:
            FUN_0232987c();
            r = 1;
            break;
        }
    }
    return r;
}
}
