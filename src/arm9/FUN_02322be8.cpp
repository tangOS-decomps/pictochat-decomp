//cpp
// decomp: module=unk_autoload_0 addr=0x02322be8 name=FUN_02322be8
// verify: python tools/match.py --c src/arm9/FUN_02322be8.cpp --func FUN_02322be8 --addr 0x02322be8 --size 0x18 --module unk_autoload_0 --version 2.0/sp1

// Runs the shared setup over the caller's record, then blits the 12-byte
// template kept at G_0238edc4 over it.

#pragma thumb on
extern "C" {
typedef struct V3 { int b[3]; } V3;
extern void FUN_02322ba8(V3 *);
extern V3 G_0238edc4;
void FUN_02322be8(V3 *dst)
{
    FUN_02322ba8(dst);
    *dst = G_0238edc4;
}
}
