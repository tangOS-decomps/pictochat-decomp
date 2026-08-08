//cpp
// decomp: module=unk_autoload_0 addr=0x0232e830 name=FUN_0232e830
// verify: python tools/match.py --c src/arm9/FUN_0232e830.cpp --func FUN_0232e830 --addr 0x0232e830 --size 0x1c --module unk_autoload_0 --version 2.0/sp1

// Releases the mask bits named by `a` from the set at G_023be560+8.

#pragma thumb on
extern "C" {
extern void FUN_02337830(int, int);
extern int G_023be560[];
void FUN_0232e830(int a)
{
    if (a != 0) {
        FUN_02337830(a, 0);
        G_023be560[2] &= ~a;
    }
}
}
