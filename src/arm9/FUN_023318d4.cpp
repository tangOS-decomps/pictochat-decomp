//cpp
// decomp: module=unk_autoload_0 addr=0x023318d4 name=FUN_023318d4
// verify: python tools/match.py --c src/arm9/FUN_023318d4.cpp --func FUN_023318d4 --addr 0x023318d4 --size 0x28 --module unk_autoload_0 --version 2.0/sp1
// flags: -noThumb

// Packs the argument down to the field width implied by `c` and dispatches it.

extern "C" {
extern void FUN_02331838(int, int);
void FUN_023318d4(int i, int a, int c)
{
    FUN_02331838(i, (a & (-0x1000 << ((unsigned int)(c - 0x16) >> 1))) | c | 1);
}
}
