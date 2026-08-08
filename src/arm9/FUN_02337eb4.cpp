//cpp
// decomp: module=unk_autoload_0 addr=0x02337eb4 name=FUN_02337eb4
// verify: python tools/match.py --c src/arm9/FUN_02337eb4.cpp --func FUN_02337eb4 --addr 0x02337eb4 --size 0x1c --module unk_autoload_0 --version 2.0/sp1

// Same shape as FUN_02337eec one word further in: refreshes the second field
// of the object behind G_023c34a0 and returns it.

#pragma thumb on
extern "C" {
extern void FUN_023314cc(void *, int);
extern int *G_023c34a0;
int FUN_02337eb4(void)
{
    FUN_023314cc(G_023c34a0 + 1, 4);
    return G_023c34a0[1];
}
}
