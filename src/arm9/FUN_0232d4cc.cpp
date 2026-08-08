//cpp
// decomp: module=unk_autoload_0 addr=0x0232d4cc name=FUN_0232d4cc
// verify: python tools/match.py --c src/arm9/FUN_0232d4cc.cpp --func FUN_0232d4cc --addr 0x0232d4cc --size 0x30 --module unk_autoload_0 --version 2.0/sp1

// Posts the 0xb8000000 message and re-stamps the DMA control word with the
// 0xa7 top byte.

#pragma thumb on
extern "C" {
extern void FUN_0232d4fc(int *);
extern int G_023be3f8[];
void FUN_0232d4cc(void)
{
    int msg[2];

    msg[0] = 0;
    msg[1] = 0xB8000000;
    FUN_0232d4fc(msg);
    *(volatile unsigned int *)0x040001A4 = G_023be3f8[1] | 0xA7000000;
}
}
