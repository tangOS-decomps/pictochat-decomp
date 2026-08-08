//cpp
// decomp: module=unk_autoload_0 addr=0x0232a5f8 name=FUN_0232a5f8
// verify: python tools/match.py --c src/arm9/FUN_0232a5f8.cpp --func FUN_0232a5f8 --addr 0x0232a5f8 --size 0x28 --module unk_autoload_0 --version 2.0/sp1

// Only in state 1: tears the current session down, raises event 4, records the
// value and restarts.

#pragma thumb on
extern "C" {
extern int FUN_0232996c(void);
extern void FUN_0232aabc(void);
extern void FUN_02329bd8(int);
extern void FUN_0232a57c(void);
extern void FUN_0232ada8(void);
extern int G_023bd698[];
void FUN_0232a5f8(int v)
{
    if (FUN_0232996c() != 1) return;
    FUN_0232aabc();
    FUN_02329bd8(4);
    G_023bd698[0x2c / 4] = v;
    FUN_0232a57c();
    FUN_0232ada8();
}
}
