//cpp
// decomp: module=unk_autoload_0 addr=0x0232e9b8 name=FUN_0232e9b8
// verify: python tools/match.py --c src/arm9/FUN_0232e9b8.cpp --func FUN_0232e9b8 --addr 0x0232e9b8 --size 0x1e --module unk_autoload_0 --version 2.0/sp1

// Retargets the live object animation header, unless the slot is empty or the
// object already sits in kind 2.  The slot is re-read after the null test.

#pragma thumb on
extern "C" {
typedef struct Head { int a, b, c, d; } Head;
typedef struct Obj {
    char pad[0x1c];
    Head head;
    unsigned char kind;
} Obj;

extern void FUN_02330590(Head *, int, int);
void FUN_0232e9b8(Obj *volatile *pp, int b, int d)
{
    Obj *o;

    if (*pp == 0) return;
    o = *pp;
    if (o->kind == 2) return;
    FUN_02330590(&o->head, b << 8, d);
}
}
