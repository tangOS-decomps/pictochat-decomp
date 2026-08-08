//cpp
// decomp: module=unk_autoload_0 addr=0x023305a8 name=FUN_023305a8
// verify: python tools/match.py --c src/arm9/FUN_023305a8.cpp --func FUN_023305a8 --addr 0x023305a8 --size 0x1e --module unk_autoload_0 --version 2.0/sp1

// Linear interpolation over the header FUN_02330590 sets up: once the elapsed
// count reaches the span, the end value stands.

#pragma thumb on
extern "C" {
typedef struct Head { int a, b, c, d; } Head;
int FUN_023305a8(Head *h)
{
    if (h->c >= h->d) return h->b;
    return h->a + h->c * (h->b - h->a) / h->d;
}
}
