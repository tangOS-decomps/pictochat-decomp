//cpp
// decomp: module=unk_autoload_0 addr=0x0232c210 name=FUN_0232c210
// verify: python tools/match.py --c src/arm9/FUN_0232c210.cpp --func FUN_0232c210 --addr 0x0232c210 --size 0x1c --module unk_autoload_0 --version 2.0/sp1

// Runs the 0xf00-byte request; on success clears the halfword at +0x16 of the
// record hanging off G_023bd8a0+4.

#pragma thumb on
extern "C" {
extern int FUN_0232c22c(int, int, int);
extern short *G_023bd8a0[];
int FUN_0232c210(int a, int b)
{
    int rc = FUN_0232c22c(a, b, 0xf00);

    if (rc == 0) G_023bd8a0[1][11] = 0;
    return rc;
}
}
