//cpp
// decomp: module=unk_autoload_0 addr=0x02334680 name=FUN_02334680
// verify: python tools/match.py --c src/arm9/FUN_02334680.cpp --func FUN_02334680 --addr 0x02334680 --size 0x26 --module unk_autoload_0 --version 2.0/sp1

// Halfword strncmp.

#pragma thumb on
extern "C" {
int FUN_02334680(const unsigned short *a, const unsigned short *b, int n)
{
    if (n != 0) {
        do {
            unsigned short vb = *b++;
            unsigned short va = *a++;

            if (va != vb) return va - vb;
            if (va == 0) break;
        } while (--n != 0);
    }
    return 0;
}
}
