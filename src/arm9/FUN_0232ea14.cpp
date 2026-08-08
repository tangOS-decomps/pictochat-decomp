//cpp
// decomp: module=unk_autoload_0 addr=0x0232ea14 name=FUN_0232ea14
// verify: python tools/match.py --c src/arm9/FUN_0232ea14.cpp --func FUN_0232ea14 --addr 0x0232ea14 --size 0x1a --module unk_autoload_0 --version 2.0/sp1

// Arms the pointed-to block for mode 2 at the given coordinates, doing nothing
// when the slot is empty.  The slot is re-read for every store.

#pragma thumb on
extern "C" {
typedef struct Blk {
    char pad[0x34];
    unsigned short mode;
    unsigned short pad2;
    unsigned short x;
    unsigned short y;
} Blk;

void FUN_0232ea14(Blk *volatile *pp, int x, int y)
{
    if (*pp != 0) {
        (*pp)->mode = 2;
        (*pp)->x = (unsigned short)x;
        (*pp)->y = (unsigned short)y;
    }
}
}
