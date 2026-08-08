//cpp
// decomp: module=unk_autoload_0 addr=0x023307b4 name=FUN_023307b4
// verify: python tools/match.py --c src/arm9/FUN_023307b4.cpp --func FUN_023307b4 --addr 0x023307b4 --size 0x20 --module unk_autoload_0 --version 2.0/sp1

// Swaps the interrupt-enable mask with interrupts held off, returning the mask
// that was there.

#pragma thumb on
extern "C" {
unsigned int FUN_023307b4(unsigned int mask)
{
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    volatile unsigned int *ie = (volatile unsigned int *)0x04000210;
    unsigned short saved = *ime;
    unsigned int prev;

    *ime = 0;
    prev = *ie;
    *ie = mask;
    (void)*ime;
    *ime = saved;
    return prev;
}
}
