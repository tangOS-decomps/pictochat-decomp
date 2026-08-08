//cpp
// decomp: module=unk_autoload_0 addr=0x02339780 name=FUN_02339780
// verify: python tools/match.py --c src/arm9/FUN_02339780.cpp --func FUN_02339780 --addr 0x02339780 --size 0x14 --module unk_autoload_0 --version 2.0/sp1

// Normalises the flag to 0/1 and forwards it with the fixed (0, 0, 1) tail.

#pragma thumb on
extern "C" {
extern void FUN_023396c0(int, int, int, int);
void FUN_02339780(int a)
{
    if (a != 1) a = 0;
    FUN_023396c0(a, 0, 0, 1);
}
}
