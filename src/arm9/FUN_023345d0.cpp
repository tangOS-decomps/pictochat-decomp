//cpp
// decomp: module=unk_autoload_0 addr=0x023345d0 name=FUN_023345d0
// verify: python tools/match.py --c src/arm9/FUN_023345d0.cpp --func FUN_023345d0 --addr 0x023345d0 --size 0x2c --module unk_autoload_0 --version 2.0/sp1

// Byte strchr, the narrow sibling of FUN_023346a8: searching for the
// terminator finds it, anything else past the end returns null.
// The def order (k, then v, then p built as `p = s; p++;`) is load-bearing:
// initialising p in its declaration swaps the r2/r3 colouring of k and p.

#pragma thumb on
extern "C" {
char *FUN_023345d0(char *s, int c)
{
    int k;
    char *p;
    int v;

    k = (char)c;
    v = *s;
    p = s;
    p++;

    if (v != 0) {
        do {
            if (v == k) return p - 1;
            v = *p++;
        } while (v != 0);
    }
    if (k != 0) return 0;
    return p - 1;
}
}
