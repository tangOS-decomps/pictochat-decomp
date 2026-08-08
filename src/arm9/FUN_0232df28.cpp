//cpp
// decomp: module=unk_autoload_0 addr=0x0232df28 name=FUN_0232df28
// verify: python tools/match.py --c src/arm9/FUN_0232df28.cpp --func FUN_0232df28 --addr 0x0232df28 --size 0x18 --module unk_autoload_0 --version 2.0/sp1

// Recomputes the cached halfword at +0x12 and reports whether it moved.

#pragma thumb on
extern "C" {
typedef struct Cache {
    char pad[0x12];
    unsigned short v;
} Cache;
extern int FUN_0232db60(Cache *);
int FUN_0232df28(Cache *c)
{
    int v = FUN_0232db60(c);

    if (v != c->v) {
        c->v = (unsigned short)v;
        return 1;
    }
    return 0;
}
}
