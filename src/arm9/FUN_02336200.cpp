//cpp
// decomp: module=unk_autoload_0 addr=0x02336200 name=FUN_02336200
// verify: python tools/match.py --c src/arm9/FUN_02336200.cpp --func FUN_02336200 --addr 0x02336200 --size 0x1c --module unk_autoload_0 --version 2.0/sp1

// Runs the null-terminated initialiser table parked at 0x02001094.

#pragma thumb on
extern "C" {
typedef void (*VoidFn)(void);
void FUN_02336200(void)
{
    VoidFn *p = (VoidFn *)0x02001094;
    while (p != 0 && *p != 0) {
        (*p)();
        p++;
    }
}
}
