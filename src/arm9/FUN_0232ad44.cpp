//cpp
// decomp: module=unk_autoload_0 addr=0x0232ad44 name=FUN_0232ad44
// verify: python tools/match.py --c src/arm9/FUN_0232ad44.cpp --func FUN_0232ad44 --addr 0x0232ad44 --size 0x3c --module unk_autoload_0 --version 2.0/sp1

// Big sibling of FUN_0232ac90: snapshots eight bytes, copies the following
// 0x60 into G_023bd7b4, runs the refresh, and raises event 6 from state 8
// or 9.

#pragma thumb on
extern "C" {
extern void FUN_02337584(void *, void *, int);
extern void FUN_0232a9f8(void);
extern int FUN_0232996c(void);
extern void FUN_02329bd8(int);
extern char G_023bd7b4[];
void FUN_0232ad44(char *src)
{
    char tmp[8];

    FUN_02337584(src, tmp, 8);
    src += 8;
    FUN_02337584(src, G_023bd7b4, 0x60);
    FUN_0232a9f8();
    if (FUN_0232996c() == 8 || FUN_0232996c() == 9) FUN_02329bd8(6);
}
}
