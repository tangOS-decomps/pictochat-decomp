//cpp
// decomp: module=unk_autoload_0 addr=0x023251cc name=FUN_023251cc
// verify: python tools/match.py --c src/arm9/FUN_023251cc.cpp --func FUN_023251cc --addr 0x023251cc --size 0x16 --module unk_autoload_0 --version 2.0/sp1

// True when the first halfword of the triple repeats in either of the other
// two slots.

#pragma thumb on
extern "C" {
int FUN_023251cc(unsigned short *p)
{
    if (p[0] == p[1] || p[0] == p[2]) return 1;
    return 0;
}
}
