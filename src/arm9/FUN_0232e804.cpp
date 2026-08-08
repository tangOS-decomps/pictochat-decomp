//cpp
// decomp: module=unk_autoload_0 addr=0x0232e804 name=FUN_0232e804
// verify: python tools/match.py --c src/arm9/FUN_0232e804.cpp --func FUN_0232e804 --addr 0x0232e804 --size 0x2c --module unk_autoload_0 --version 2.0/sp1

// Claims the mask bits in the set at G_023be560+8, refusing if any are already
// out.  An empty request always succeeds.

#pragma thumb on
extern "C" {
extern void FUN_02337818(int, int);
extern int G_023be560[];
int FUN_0232e804(int mask)
{
    if (mask == 0) return 1;
    if ((G_023be560[2] & mask) != 0) return 0;
    FUN_02337818(mask, 0);
    G_023be560[2] |= mask;
    return 1;
}
}
