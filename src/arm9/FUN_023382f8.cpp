//cpp
// decomp: module=unk_autoload_0 addr=0x023382f8 name=FUN_023382f8
// verify: python tools/match.py --c src/arm9/FUN_023382f8.cpp --func FUN_023382f8 --addr 0x023382f8 --size 0x24 --module unk_autoload_0 --version 2.0/sp1

// Tests one bit of the shared-WRAM mask table at 0x02fffc00+0x388.

#pragma thumb on
extern "C" {
typedef struct Shared {
    char pad[0x388];
    unsigned int mask[1];
} Shared;

int FUN_023382f8(int bit, int idx)
{
    Shared *s = (Shared *)0x02FFFC00;
    int r = 1;

    if ((s->mask[idx] & (1u << bit)) == 0) r = 0;
    return r;
}
}
