//cpp
// decomp: module=unk_autoload_0 addr=0x02330590 name=FUN_02330590
// verify: python tools/match.py --c src/arm9/FUN_02330590.cpp --func FUN_02330590 --addr 0x02330590 --size 0x18 --module unk_autoload_0 --version 2.0/sp1

// Initialises the four-word header in place: the helper's verdict, the two
// caller-supplied fields, and a cleared counter.

#pragma thumb on
extern "C" {
typedef struct Head { int a, b, c, d; } Head;
extern int FUN_023305a8(Head *);
void FUN_02330590(Head *h, int b, int d)
{
    h->a = FUN_023305a8(h);
    h->b = b;
    h->d = d;
    h->c = 0;
}
}
