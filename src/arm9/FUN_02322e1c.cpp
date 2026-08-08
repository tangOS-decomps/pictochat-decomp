//cpp
// decomp: module=unk_autoload_0 addr=0x02322e1c name=FUN_02322e1c
// verify: python tools/match.py --c src/arm9/FUN_02322e1c.cpp --func FUN_02322e1c --addr 0x02322e1c --size 0x30 --module unk_autoload_0 --version 2.0/sp1

// Points the current-entry slot at the fixed default for kind 1, at the
// caller's record when it validates, and at nothing otherwise.

#pragma thumb on
extern "C" {
extern int FUN_02322e4c(void *);
extern char *G_0238ee3c;
extern char G_0233ae70[];
void FUN_02322e1c(unsigned char *p)
{
    if (*p == 1) {
        G_0238ee3c = G_0233ae70;
        return;
    }
    if (FUN_02322e4c(p) != 0) {
        G_0238ee3c = (char *)p;
        return;
    }
    G_0238ee3c = 0;
}
}
