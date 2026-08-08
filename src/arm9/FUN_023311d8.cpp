//cpp
// decomp: module=unk_autoload_0 addr=0x023311d8 name=FUN_023311d8
// verify: python tools/match.py --c src/arm9/FUN_023311d8.cpp --func FUN_023311d8 --addr 0x023311d8 --size 0x2c --module unk_autoload_0 --version 2.0/sp1

// Lazily computes the cached mask at G_02369e00+4, seeding it with the
// top-and-bottom bits before folding in what the probe reports.

#pragma thumb on
extern "C" {
extern int G_02369e00[];
extern int FUN_02331204(void);
int FUN_023311d8(void)
{
    if (G_02369e00[1] == -1) {
        G_02369e00[1] = 0x80000001;
        G_02369e00[1] = FUN_02331204() | G_02369e00[1];
    }
    return G_02369e00[1];
}
}
