//cpp
// decomp: module=unk_autoload_0 addr=0x0232aa0c name=FUN_0232aa0c
// verify: python tools/match.py --c src/arm9/FUN_0232aa0c.cpp --func FUN_0232aa0c --addr 0x0232aa0c --size 0x30 --module unk_autoload_0 --version 2.0/sp1

// Blanks whichever of the two 0x60-byte tables the live flag selects.

#pragma thumb on
extern "C" {
extern void FUN_0233740c(int, void *, int);
extern int G_023bd698[];
extern char G_023bd754[];
extern char G_023bd7b4[];
void FUN_0232aa0c(void)
{
    if (G_023bd698[5] != 0) FUN_0233740c(0, G_023bd754, 0x60);
    else FUN_0233740c(0, G_023bd7b4, 0x60);
}
}
