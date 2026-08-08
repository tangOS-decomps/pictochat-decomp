//cpp
// decomp: module=unk_autoload_0 addr=0x023390c0 name=FUN_023390c0
// verify: python tools/match.py --c src/arm9/FUN_023390c0.cpp --func FUN_023390c0 --addr 0x023390c0 --size 0x1c --module unk_autoload_0 --version 2.0/sp1

// Fires the one-shot completion hook parked at G_023c3564+0x30, clearing both
// it and the busy word before the call so a re-entrant hook sees a clean slot.

#pragma thumb on
extern "C" {
typedef void (*Cb)(int, int);
extern int G_023c3564[];
void FUN_023390c0(int a)
{
    Cb cb = (Cb)G_023c3564[12];
    int arg = G_023c3564[13];

    G_023c3564[11] = 0;
    if (cb != 0) {
        G_023c3564[12] = 0;
        cb(a, arg);
    }
}
}
