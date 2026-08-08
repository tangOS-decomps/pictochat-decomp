//cpp
// decomp: module=unk_autoload_0 addr=0x0232c098 name=FUN_0232c098
// verify: python tools/match.py --c src/arm9/FUN_0232c098.cpp --func FUN_0232c098 --addr 0x0232c098 --size 0x1c --module unk_autoload_0 --version 2.0/sp1

// Resets the counter at G_023bd874 and tail-calls the initialiser for the
// 0x10 x 0x40 pool that follows it.

#pragma thumb on
extern "C" {
extern int G_023bd874;
extern char G_023bd878[];
extern void FUN_0232b74c(void *, int, int);
void FUN_0232c098(void)
{
    G_023bd874 = 0;
    FUN_0232b74c(G_023bd878, 0x10, 0x40);
}
}
