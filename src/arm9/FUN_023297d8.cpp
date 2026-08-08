//cpp
// decomp: module=unk_autoload_0 addr=0x023297d8 name=FUN_023297d8
// verify: python tools/match.py --c src/arm9/FUN_023297d8.cpp --func FUN_023297d8 --addr 0x023297d8 --size 0x2a --module unk_autoload_0 --version 2.0/sp1

// Tears the session down and spins the state machine until it settles on 0xb.

#pragma thumb on
extern "C" {
extern int FUN_0232996c(void);
extern void FUN_0232a428(void);
extern void FUN_023298d8(int);
extern void FUN_0232987c(void);
void FUN_023297d8(void)
{
    if (FUN_0232996c() == 0xb) return;
    FUN_0232a428();
    FUN_023298d8(1);
    if (FUN_0232996c() == 0) return;
    FUN_0232987c();
    while (FUN_0232996c() != 0xb)
        ;
}
}
