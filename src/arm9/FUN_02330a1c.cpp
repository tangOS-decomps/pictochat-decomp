//cpp
// decomp: module=unk_autoload_0 addr=0x02330a1c name=FUN_02330a1c
// verify: python tools/match.py --c src/arm9/FUN_02330a1c.cpp --func FUN_02330a1c --addr 0x02330a1c --size 0x18 --module unk_autoload_0 --version 2.0/sp1

// Sibling of FUN_023309fc: same mailbox, different worker and callback.

#pragma thumb on
extern "C" {
extern void FUN_023309a4(int, void *, void *, int);
extern void FUN_02330a34(void);
void FUN_02330a1c(int a)
{
    FUN_023309a4(a, (void *)0x02FFFFE8, (void *)FUN_02330a34, 1);
}
}
