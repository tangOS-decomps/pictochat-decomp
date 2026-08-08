//cpp
// decomp: module=unk_autoload_0 addr=0x02322940 name=FUN_02322940
// verify: python tools/match.py --c src/arm9/FUN_02322940.cpp --func FUN_02322940 --addr 0x02322940 --size 0x28 --module unk_autoload_0 --version 2.0/sp1

// Blanks the four-word block at G_0238eda0 and re-registers its tail as both
// channel 0 and channel 1.

#pragma thumb on
extern "C" {
extern void FUN_02339ac0(int, void *);
extern int G_0238eda0[];
extern int G_0238eda4[];
void FUN_02322940(void)
{
    G_0238eda0[0] = 0;
    G_0238eda0[2] = 0;
    G_0238eda0[3] = 0;
    G_0238eda0[1] = 0;
    FUN_02339ac0(0, G_0238eda4);
    FUN_02339ac0(1, G_0238eda4);
}
}
