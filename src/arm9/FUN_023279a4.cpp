//cpp
// decomp: module=unk_autoload_0 addr=0x023279a4 name=FUN_023279a4

// Scales `b` by however far `a` exceeds 0x32, halved; zero at or below 0x32.
//
// The multiply operands are ordered `b * (a - 0x32)`. The other order is the same
// value but drops the register move the ROM has, one instruction short.

#pragma thumb on
extern "C" {
int FUN_023279a4(int a, int b)
{
    if (a <= 0x32) return 0;
    return (b * (a - 0x32)) / 2;
}
}
