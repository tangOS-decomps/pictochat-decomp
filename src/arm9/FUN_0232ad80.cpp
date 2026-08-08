//cpp
// decomp: module=unk_autoload_0 addr=0x0232ad80 name=FUN_0232ad80
// verify: python tools/match.py --c src/arm9/FUN_0232ad80.cpp --func FUN_0232ad80 --addr 0x0232ad80 --size 0x28 --module unk_autoload_0 --version 2.0/sp1

// Latches the closing flag once, and only while a session is live.

#pragma thumb on
extern "C" {
extern void FUN_0232b1c0(void);
extern int G_023bd698[];
int FUN_0232ad80(void)
{
    if (G_023bd698[16] != 0) return 1;
    if (G_023bd698[12] != 0) {
        G_023bd698[16] = 1;
        FUN_0232b1c0();
        return 1;
    }
    return 0;
}
}
