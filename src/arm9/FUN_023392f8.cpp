//cpp
// decomp: module=unk_autoload_0 addr=0x023392f8 name=FUN_023392f8
// verify: python tools/match.py --c src/arm9/FUN_023392f8.cpp --func FUN_023392f8 --addr 0x023392f8 --size 0x20 --module unk_autoload_0 --version 2.0/sp1

// Queues the request with FUN_023390b8 as its completion hook; on immediate
// success pumps the idle callback and returns what the slot was filled with.

#pragma thumb on
extern "C" {
typedef void (*VoidFn)(void);
extern int FUN_023392c0(int, void *, int *);
extern void FUN_023390b8(void);
extern VoidFn G_0236a180;
int FUN_023392f8(int a)
{
    int out;
    int rc = FUN_023392c0(a, (void *)FUN_023390b8, &out);

    if (rc != 0) return rc;
    G_0236a180();
    return out;
}
}
