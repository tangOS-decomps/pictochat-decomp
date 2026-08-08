//cpp
// decomp: module=unk_autoload_0 addr=0x023346cc name=FUN_023346cc
// verify: python tools/match.py --c src/arm9/FUN_023346cc.cpp --func FUN_023346cc --addr 0x023346cc --size 0x20 --module unk_autoload_0 --version 2.0/sp1

// copysign: keeps the magnitude of x and takes the sign bit from y.

#pragma thumb on
extern "C" {
double FUN_023346cc(double x, double y)
{
    ((unsigned int *)&x)[1] = (((unsigned int *)&x)[1] & 0x7fffffff)
                            | (((unsigned int *)&y)[1] & 0x80000000);
    return x;
}
}
