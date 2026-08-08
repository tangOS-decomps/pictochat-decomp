//cpp
// decomp: module=unk_autoload_0 addr=0x0232e734 name=FUN_0232e734
// verify: python tools/match.py --c src/arm9/FUN_0232e734.cpp --func FUN_0232e734 --addr 0x0232e734 --size 0x1e --module unk_autoload_0 --version 2.0/sp1

// Runs whichever of the two refresh passes the flag word asks for.

#pragma thumb on
extern "C" {
extern void FUN_0232e6bc(void *);
extern void FUN_0232e6cc(void *);
void FUN_0232e734(void *o, int flags)
{
    if (flags & 1) FUN_0232e6bc(o);
    if (flags & 2) FUN_0232e6cc(o);
}
}
