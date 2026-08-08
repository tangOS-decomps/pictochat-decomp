//cpp
// decomp: module=unk_autoload_0 addr=0x02322d30 name=FUN_02322d30
// verify: python tools/match.py --c src/arm9/FUN_02322d30.cpp --func FUN_02322d30 --addr 0x02322d30 --size 0x34 --module unk_autoload_0 --version 2.0/sp1

// Formats the two counters into a scratch line and hands the first one on.

#pragma thumb on
extern "C" {
extern int FUN_02334564(char *, const char *, ...);
extern void FUN_02328e04(int);
extern int G_0238ede0[];
extern char G_0233ae48[];
extern char G_0233ae58[];
void FUN_02322d30(void)
{
    char buf[0x20];

    FUN_02334564(buf, G_0233ae48, G_0238ede0[3]);
    FUN_02334564(buf, G_0233ae58, G_0238ede0[1]);
    FUN_02328e04(G_0238ede0[3]);
}
}
