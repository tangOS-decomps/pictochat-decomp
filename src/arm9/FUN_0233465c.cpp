//cpp
// decomp: module=unk_autoload_0 addr=0x0233465c name=FUN_0233465c
// verify: python tools/match.py --c src/arm9/FUN_0233465c.cpp --func FUN_0233465c --addr 0x0233465c --size 0x22 --module unk_autoload_0 --version 2.0/sp1

// Halfword string concatenate; like FUN_02334610 the copy loop tests the
// destination it just wrote rather than the source.

#pragma thumb on
extern "C" {
unsigned short *FUN_0233465c(unsigned short *dst, const unsigned short *src)
{
    volatile unsigned short *d = (volatile unsigned short *)dst;

    while (*d++ != 0)
        ;
    d--;
    while ((*d++ = *src++) != 0)
        ;
    return dst;
}
}
