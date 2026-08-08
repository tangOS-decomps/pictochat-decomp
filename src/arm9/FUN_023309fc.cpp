//cpp
// decomp: module=unk_autoload_0 addr=0x023309fc name=FUN_023309fc
// verify: python tools/match.py --c src/arm9/FUN_023309fc.cpp --func FUN_023309fc --addr 0x023309fc --size 0x18 --module unk_autoload_0 --version 2.0/sp1

// Registers FUN_02330a44 against the shared-WRAM mailbox at 0x02FFFFE8.

#pragma thumb on
extern "C" {
extern void FUN_02330944(int, void *, void *, int);
extern void FUN_02330a44(void);
void FUN_023309fc(int a)
{
    FUN_02330944(a, (void *)0x02FFFFE8, (void *)FUN_02330a44, 1);
}
}
