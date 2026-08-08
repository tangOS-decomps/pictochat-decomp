//cpp
// decomp: module=unk_autoload_0 addr=0x02320c44 name=FUN_02320c44
// verify: python tools/match.py --c src/arm9/FUN_02320c44.cpp --func FUN_02320c44 --addr 0x02320c44 --size 0x30 --module unk_autoload_0 --version 2.0/sp1

// Blanks the two 0x400-byte layers, but only while the display is up.

#pragma thumb on
extern "C" {
extern int G_0236d4a8[];
extern char G_0236c8a8[];
extern char G_0236ced8[];
extern void FUN_023368c0(void *, int, int);
extern void FUN_02336900(void *, int, int);
void FUN_02320c44(void)
{
    if (G_0236d4a8[0x60 / 4] == 0) return;
    FUN_023368c0(G_0236c8a8, 0, 0x400);
    FUN_02336900(G_0236ced8, 0, 0x400);
}
}
