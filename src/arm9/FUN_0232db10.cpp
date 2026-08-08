//cpp
// decomp: module=unk_autoload_0 addr=0x0232db10 name=FUN_0232db10
// verify: python tools/match.py --c src/arm9/FUN_0232db10.cpp --func FUN_0232db10 --addr 0x0232db10 --size 0x10 --module unk_autoload_0 --version 2.0/sp1

// Fills the six-field record: one word, three halfwords, then a trailing word
// past the alignment hole at +0xa.  The halfword fields are narrowed by the
// stores, so every parameter comes in as a plain word.

#pragma thumb on
extern "C" {
typedef struct Rec {
    int a;
    short b;
    short c;
    short d;
    int e;
} Rec;

void FUN_0232db10(Rec *r, int a, int b, int c, int d, int e)
{
    r->a = a;
    r->b = (short)b;
    r->c = (short)c;
    r->d = (short)d;
    r->e = e;
}
}
