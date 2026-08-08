//cpp
// decomp: module=unk_autoload_0 addr=0x0233081c name=FUN_0233081c
// verify: python tools/match.py --c src/arm9/FUN_0233081c.cpp --func FUN_0233081c --addr 0x0233081c --size 0x20 --module unk_autoload_0 --version 2.0/sp1

// Same critical section as FUN_023307b4, over the interrupt-request word.

#pragma thumb on
extern "C" {
unsigned int FUN_0233081c(unsigned int mask)
{
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    volatile unsigned int *ie = (volatile unsigned int *)0x04000214;
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
