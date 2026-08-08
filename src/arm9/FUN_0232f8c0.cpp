//cpp
// decomp: module=unk_autoload_0 addr=0x0232f8c0 name=FUN_0232f8c0
// verify: python tools/match.py --c src/arm9/FUN_0232f8c0.cpp --func FUN_0232f8c0 --addr 0x0232f8c0 --size 0x26 --module unk_autoload_0 --version 2.0/sp1

// Allocates a 0x14-byte node out of the handle's owner arena, initialises it
// and links it onto the handle's list.

#pragma thumb on
extern "C" {
typedef struct S {
    void *owner;
    char q[1];
} S;
extern void *FUN_0232e710(void *, int, int);
extern void FUN_0232f890(void *);
extern void FUN_0232e0ac(void *, void *);
int FUN_0232f8c0(S *s)
{
    void *p = FUN_0232e710(s->owner, 0x14, 4);

    if (p == 0) return 0;
    FUN_0232f890(p);
    FUN_0232e0ac(&s->q, p);
    return 1;
}
}
