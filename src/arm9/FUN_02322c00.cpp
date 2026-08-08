//cpp
// decomp: module=unk_autoload_0 addr=0x02322c00 name=FUN_02322c00
// verify: python tools/match.py --c src/arm9/FUN_02322c00.cpp --func FUN_02322c00 --addr 0x02322c00 --size 0x18 --module unk_autoload_0 --version 2.0/sp1

// Sibling of FUN_02322be8 with a 16-byte template at G_0238edd0.

#pragma thumb on
extern "C" {
typedef struct V4 { int b[4]; } V4;
extern void FUN_02322ba8(V4 *);
extern V4 G_0238edd0;
void FUN_02322c00(V4 *dst)
{
    FUN_02322ba8(dst);
    *dst = G_0238edd0;
}
}
