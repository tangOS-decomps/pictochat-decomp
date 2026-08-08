//cpp
// decomp: module=unk_autoload_0 addr=0x02332274 name=FUN_02332274
// verify: python tools/match.py --c src/arm9/FUN_02332274.cpp --func FUN_02332274 --addr 0x02332274 --size 0x1c --module unk_autoload_0 --version 2.0/sp1

// Fires and clears the one-shot hook at G_023c0b2c, then runs the fixed
// follow-up.

#pragma thumb on
extern "C" {
typedef void (*Cb)(int);
extern int G_023c0b2c[];
extern void FUN_02332290(void);
void FUN_02332274(void)
{
    Cb cb = (Cb)G_023c0b2c[0];

    if (cb != 0) {
        G_023c0b2c[0] = 0;
        cb(G_023c0b2c[1]);
    }
    FUN_02332290();
}
}
