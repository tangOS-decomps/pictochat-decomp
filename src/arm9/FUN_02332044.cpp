//cpp
// decomp: module=unk_autoload_0 addr=0x02332044 name=FUN_02332044
// verify: python tools/match.py --c src/arm9/FUN_02332044.cpp --func FUN_02332044 --addr 0x02332044 --size 0x28 --module unk_autoload_0 --version 2.0/sp1

// One-shot shutdown of the second channel: latches the flag, clears the two
// tail words, drops interrupt bit 2, then clears the two head words.

#pragma thumb on
extern "C" {
typedef struct Ctl {
    unsigned short on;
    unsigned short pad;
    int a;
    int b;
    int c;
    int d;
} Ctl;
extern Ctl G_023c0afc;
extern unsigned int FUN_023307f8(unsigned int);
void FUN_02332044(void)
{
    if (G_023c0afc.on != 0) return;
    G_023c0afc.on = 1;
    G_023c0afc.c = 0;
    G_023c0afc.d = 0;
    FUN_023307f8(4);
    G_023c0afc.b = 0;
    G_023c0afc.a = 0;
}
}
