//cpp
// decomp: module=unk_autoload_0 addr=0x0232acd8 name=FUN_0232acd8
// verify: python tools/match.py --c src/arm9/FUN_0232acd8.cpp --func FUN_0232acd8 --addr 0x0232acd8 --size 0x38 --module unk_autoload_0 --version 2.0/sp1

// Sibling of FUN_0232ade8: tears down via FUN_0232b9e4 / FUN_0232a648(0,0),
// then unless the +0x30 word is set, marks +0x14 when the machine sits in
// state 6 and re-arms FUN_0232b270 through FUN_02329b2c.

#pragma thumb on
extern "C" {
extern void FUN_0232b9e4(void);
extern void FUN_0232a648(int, int);
extern int FUN_0232996c(void);
extern void FUN_02329b2c(void (*)(void), int);
extern void FUN_0232b270(void);
extern int G_023bd698[];
void FUN_0232acd8(void)
{
    FUN_0232b9e4();
    FUN_0232a648(0, 0);
    if (G_023bd698[0xc] == 0) {
        if (FUN_0232996c() == 6) {
            G_023bd698[5] = 1;
        }
        FUN_02329b2c(FUN_0232b270, 0);
    }
}
}
