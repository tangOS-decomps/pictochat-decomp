//cpp
// decomp: module=unk_autoload_0 addr=0x023298a0 name=FUN_023298a0
// verify: python tools/match.py --c src/arm9/FUN_023298a0.cpp --func FUN_023298a0 --addr 0x023298a0 --size 0x20 --module unk_autoload_0 --version 2.0/sp1

// Runs the registered teardown hook over the live object, drains the two
// subsystems behind it, then clears both slots.

#pragma thumb on
extern "C" {
typedef void (*Fn)(void *);
extern void *G_023bd5e0[];
extern void FUN_0232a304(void);
extern void FUN_02329c94(void);
void FUN_023298a0(void)
{
    ((Fn)G_023bd5e0[3])(G_023bd5e0[1]);
    FUN_0232a304();
    FUN_02329c94();
    G_023bd5e0[7] = 0;
    G_023bd5e0[3] = 0;
}
}
