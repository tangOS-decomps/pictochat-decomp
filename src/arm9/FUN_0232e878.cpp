//cpp
// decomp: module=unk_autoload_0 addr=0x0232e878 name=FUN_0232e878
// NONMATCHING: byte-identical except the first pool load targets r1 in the ROM and r0 in every candidate phrasing; the loop, the mask walk and the -1 tail all match exactly. (div=2). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.

// Claims the lowest free bit of the eight-slot mask at G_023be560+4, or -1
// when they are all taken.

#pragma thumb on
extern "C" {
extern int G_023be560[];
int FUN_0232e878(void)
{
    int i;
    int mask = 1;
    int used = G_023be560[1];

    for (i = 0; i < 8; i++) {
        if ((used & mask) == 0) {
            G_023be560[1] |= mask;
            return i;
        }
        mask <<= 1;
    }
    return -1;
}
}
