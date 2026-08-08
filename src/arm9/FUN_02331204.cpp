//cpp
// decomp: module=unk_autoload_0 addr=0x02331204 name=FUN_02331204
// verify: python tools/match.py --c src/arm9/FUN_02331204.cpp --func FUN_02331204 --addr 0x02331204 --size 0x14 --module unk_autoload_0 --version 2.0/sp1

// Indexes the table at G_0233a140 by whatever FUN_02332120 reports.

#pragma thumb on
extern "C" {
extern int FUN_02332120(void);
extern int G_0233a140[];
int FUN_02331204(void) { return G_0233a140[FUN_02332120()]; }
}
