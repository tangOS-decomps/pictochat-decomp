//cpp
// decomp: module=unk_autoload_0 addr=0x02323d28 name=FUN_02323d28
// verify: python tools/match.py --c src/arm9/FUN_02323d28.cpp --func FUN_02323d28 --addr 0x02323d28 --size 0x14 --module unk_autoload_0 --version 2.0/sp1

// Clears the 0x2280-byte block at G_02393450 and hands it back.

#pragma thumb on
extern "C" {
extern void FUN_023314e8(void *, int);
extern char G_02393450[];
void *FUN_02323d28(void)
{
    FUN_023314e8(G_02393450, 0x2280);
    return G_02393450;
}
}
