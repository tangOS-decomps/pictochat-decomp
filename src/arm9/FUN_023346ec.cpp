//cpp
// decomp: module=unk_autoload_0 addr=0x023346ec name=FUN_023346ec
// verify: python tools/match.py --c src/arm9/FUN_023346ec.cpp --func FUN_023346ec --addr 0x023346ec --size 0x18 --module unk_autoload_0 --version 2.0/sp1

// fabs: clears the sign bit in the high word of the homed double and hands it
// straight back.

#pragma thumb on
extern "C" {
double FUN_023346ec(double x)
{
    ((unsigned int *)&x)[1] &= 0x7fffffff;
    return x;
}
}
