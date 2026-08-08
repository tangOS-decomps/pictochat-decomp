//cpp
// decomp: module=unk_autoload_0 addr=0x02334610 name=FUN_02334610
// verify: python tools/match.py --c src/arm9/FUN_02334610.cpp --func FUN_02334610 --addr 0x02334610 --size 0x18 --module unk_autoload_0 --version 2.0/sp1

// Halfword string copy: the terminator test reads the destination back rather
// than the source.

#pragma thumb on
extern "C" {
unsigned short *FUN_02334610(unsigned short *dst, const unsigned short *src)
{
    volatile unsigned short *d = (volatile unsigned short *)dst;

    while ((*d++ = *src++) != 0)
        ;
    return dst;
}
}
