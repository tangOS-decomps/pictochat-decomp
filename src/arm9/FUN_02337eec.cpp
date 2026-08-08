//cpp
// decomp: module=unk_autoload_0 addr=0x02337eec name=FUN_02337eec
// verify: python tools/match.py --c src/arm9/FUN_02337eec.cpp --func FUN_02337eec --addr 0x02337eec --size 0x18 --module unk_autoload_0 --version 2.0/sp1

// Hands the object behind G_023c34a0 to the 4-byte helper, then reloads it and
// returns its first word.

#pragma thumb on
extern "C" {
extern void FUN_023314cc(void *, int);
extern int *G_023c34a0;
int FUN_02337eec(void)
{
    FUN_023314cc(G_023c34a0, 4);
    return *G_023c34a0;
}
}
