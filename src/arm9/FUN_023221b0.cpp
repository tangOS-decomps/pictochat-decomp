//cpp
// decomp: module=unk_autoload_0 addr=0x023221b0 name=FUN_023221b0
// verify: python tools/match.py --c src/arm9/FUN_023221b0.cpp --func FUN_023221b0 --addr 0x023221b0 --size 0x24 --module unk_autoload_0 --version 2.0/sp1

// Registers the two adjacent tables against the same handler under ids 0x2d
// and 0x2e.

#pragma thumb on
extern "C" {
extern void FUN_02321684(void *, void *, int);
extern char G_0238e09c[];
extern char G_0238e0dc[];
extern char G_0233b8c4[];
void FUN_023221b0(void)
{
    FUN_02321684(G_0238e09c, G_0233b8c4, 0x2d);
    FUN_02321684(G_0238e0dc, G_0233b8c4, 0x2e);
}
}
