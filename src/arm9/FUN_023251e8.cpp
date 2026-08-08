//cpp
// decomp: module=unk_autoload_0 addr=0x023251e8 name=FUN_023251e8
// verify: python tools/match.py --c src/arm9/FUN_023251e8.cpp --func FUN_023251e8 --addr 0x023251e8 --size 0x18 --module unk_autoload_0 --version 2.0/sp1

// Resets the record at G_0239c108, then stamps the caller's value into the
// halfword at +8 and clears the one at +0xa.

#pragma thumb on
extern "C" {
extern void FUN_0232517c(void *);
extern short G_0239c108[];
void FUN_023251e8(int a)
{
    FUN_0232517c(G_0239c108);
    G_0239c108[4] = (short)a;
    G_0239c108[5] = 0;
}
}
