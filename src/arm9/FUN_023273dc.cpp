//cpp
// decomp: module=unk_autoload_0 addr=0x023273dc name=FUN_023273dc
// verify: python tools/match.py --c src/arm9/FUN_023273dc.cpp --func FUN_023273dc --addr 0x023273dc --size 0x20 --module unk_autoload_0 --version 2.0/sp1
// flags: -O4,s

// Clears the flag byte at +0x59 of all ten 0x5c-byte entries.

#pragma thumb on
extern "C" {
typedef struct Ent {
    char pad[0x59];
    char flag;
    char pad2[2];
} Ent;
extern Ent G_0239f15c[];
void FUN_023273dc(void)
{
    int i;

    for (i = 0; i < 10; i++) G_0239f15c[i].flag = 0;
}
}
