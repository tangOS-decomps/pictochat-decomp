//cpp
// decomp: module=unk_autoload_0 addr=0x023307f8 name=FUN_023307f8
// verify: python tools/match.py --c src/arm9/FUN_023307f8.cpp --func FUN_023307f8 --addr 0x023307f8 --size 0x24 --module unk_autoload_0 --version 2.0/sp1

// Drops bits from the interrupt-enable mask, returning the mask that was there
// before.

#pragma thumb on
extern "C" {
unsigned int FUN_023307f8(unsigned int mask)
{
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    volatile unsigned int *ie = (volatile unsigned int *)0x04000210;
    unsigned short saved = *ime;
    unsigned int prev;

    *ime = 0;
    prev = *ie;
    *ie = ~mask & prev;
    (void)*ime;
    *ime = saved;
    return prev;
}
}
