//cpp
// decomp: module=unk_autoload_0 addr=0x02326718 name=FUN_02326718
// verify: python tools/match.py --c src/arm9/FUN_02326718.cpp --func FUN_02326718 --addr 0x02326718 --size 0x24 --module unk_autoload_0 --version 2.0/sp1
// flags: -O4,s

// Wraps a coordinate up by a screen when it falls below the live limit, which
// only applies in mode 0x380.

#pragma thumb on
extern "C" {
extern int G_0239c930[];
int FUN_02326718(int v)
{
    int limit = 0;

    if (G_0239c930[1] == 0x380) limit = G_0239c930[8];
    if (v < limit) v += 0x400;
    return v;
}
}
