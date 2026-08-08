//cpp
// decomp: module=unk_autoload_0 addr=0x0232673c name=FUN_0232673c
// verify: python tools/match.py --c src/arm9/FUN_0232673c.cpp --func FUN_0232673c --addr 0x0232673c --size 0x26 --module unk_autoload_0 --version 2.0/sp1
// flags: -O4,s

// Wraps a coordinate into [0, 0x400) a screen at a time.

#pragma thumb on
extern "C" {
int FUN_0232673c(int v)
{
    while (v < 0 || v >= 0x400) {
        if (v >= 0x400) v -= 0x400;
        else if (v < 0) v += 0x400;
    }
    return v;
}
}
