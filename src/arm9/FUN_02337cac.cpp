//cpp
// decomp: module=unk_autoload_0 addr=0x02337cac name=FUN_02337cac
// verify: python tools/match.py --c src/arm9/FUN_02337cac.cpp --func FUN_02337cac --addr 0x02337cac --size 0x20 --module unk_autoload_0 --version 2.0/sp1

// Reads whichever of the two cached words at G_023c1960 is live, with
// interrupts held off.

#pragma thumb on
extern "C" {
extern int FUN_02332080(void);
extern void FUN_02332094(int);
extern int G_023c1960[];
int FUN_02337cac(void)
{
    int v;
    int s = FUN_02332080();

    if (G_023c1960[2] == 0) v = G_023c1960[1];
    else v = G_023c1960[8];
    FUN_02332094(s);
    return v;
}
}
