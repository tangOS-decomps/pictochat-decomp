//cpp
// decomp: module=unk_autoload_0 addr=0x0232519c name=FUN_0232519c

// Advances a ring cursor and flags wrap conditions in a four-halfword control
// block.
//
// The last test is written `p[0] > p[2]` rather than `p[2] < p[0]`. Same
// condition, but the ROM loads p[0] first, and the other spelling swaps the two
// loads and inverts the branch.

#pragma thumb on
extern "C" {
void FUN_0232519c(unsigned short *p)
{
    p[0] = p[0] + 1;
    if (p[0] == p[1] || p[0] == p[2]) p[3] = 1;
    if (p[0] > p[2]) p[0] = p[1] + 1;
}
}
