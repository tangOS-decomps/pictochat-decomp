//cpp
// decomp: module=unk_autoload_0 addr=0x023346a8 name=FUN_023346a8
// verify: python tools/match.py --c src/arm9/FUN_023346a8.cpp --func FUN_023346a8 --addr 0x023346a8 --size 0x24 --module unk_autoload_0 --version 2.0/sp1

// Halfword strchr: searching for the terminator finds it, anything else past
// the end returns null.

#pragma thumb on
extern "C" {
unsigned short *FUN_023346a8(unsigned short *s, int c)
{
    unsigned short *p = s + 1;
    int v = *s;

    if (v != 0) {
        do {
            if (v == c) return p - 1;
            v = *p++;
        } while (v != 0);
    }
    if (c != 0) return 0;
    return p - 1;
}
}
