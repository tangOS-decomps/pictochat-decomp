//cpp
// decomp: module=unk_autoload_0 addr=0x0232f89c name=FUN_0232f89c
// verify: python tools/match.py --c src/arm9/FUN_0232f89c.cpp --func FUN_0232f89c --addr 0x0232f89c --size 0x22 --module unk_autoload_0 --version 2.0/sp1

// Sets the handle's owner word and reports whether the follow-up pass took.

#pragma thumb on
extern "C" {
typedef struct S {
    int owner;
    char q[1];
} S;
extern void FUN_0232e084(void *, int);
extern int FUN_0232f8c0(S *);
int FUN_0232f89c(S *s, int owner)
{
    FUN_0232e084(&s->q, 0xc);
    s->owner = owner;
    if (FUN_0232f8c0(s) != 0) return 1;
    return 0;
}
}
