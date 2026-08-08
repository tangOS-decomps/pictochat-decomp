//cpp
// decomp: module=unk_autoload_0 addr=0x0232ac90 name=FUN_0232ac90
// verify: python tools/match.py --c src/arm9/FUN_0232ac90.cpp --func FUN_0232ac90 --addr 0x0232ac90 --size 0x22 --module unk_autoload_0 --version 2.0/sp1

// Takes an eight-byte snapshot, runs the refresh, and raises event 7 when the
// machine has reached state 0xa.

#pragma thumb on
extern "C" {
extern void FUN_02337584(void *, void *, int);
extern void FUN_0232a824(void);
extern int FUN_0232996c(void);
extern void FUN_02329bd8(int);
void FUN_0232ac90(void *src)
{
    char tmp[8];

    FUN_02337584(src, tmp, 8);
    FUN_0232a824();
    if (FUN_0232996c() == 0xa) FUN_02329bd8(7);
}
}
