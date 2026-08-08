//cpp
// decomp: module=unk_autoload_0 addr=0x0232a620 name=FUN_0232a620
// verify: python tools/match.py --c src/arm9/FUN_0232a620.cpp --func FUN_0232a620 --addr 0x0232a620 --size 0x28 --module unk_autoload_0 --version 2.0/sp1

// Only in state 1: raises event 5, records the value at G_023bd698+0x48 and
// runs the follow-up over the caller's sub-record at +0x20.

#pragma thumb on
extern "C" {
extern int FUN_0232996c(void);
extern void FUN_02329bd8(int);
extern void FUN_0232af28(void *);
extern int G_023bd698[];
void FUN_0232a620(char *o, int v)
{
    if (FUN_0232996c() != 1) return;
    FUN_02329bd8(5);
    G_023bd698[0x48 / 4] = v;
    FUN_0232af28(o + 0x20);
}
}
