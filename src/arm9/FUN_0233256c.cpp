//cpp
// decomp: module=unk_autoload_0 addr=0x0233256c name=FUN_0233256c
// verify: python tools/match.py --c src/arm9/FUN_0233256c.cpp --func FUN_0233256c --addr 0x0233256c --size 0x2c --module unk_autoload_0 --version 2.0/sp1

// Posts command 0xb7, then re-stamps the DMA control word from the shared-WRAM
// template with the 0xa1 top byte.

#pragma thumb on
extern "C" {
extern void FUN_023324f8(int, int);
void FUN_0233256c(int a)
{
    unsigned int v;

    FUN_023324f8(0xb7, a);
    v = (*(volatile unsigned int *)0x02FFFAE0 & 0xF8FFFFFF) | 0xA1000000;
    *(volatile unsigned int *)0x040001A4 = v;
}
}
