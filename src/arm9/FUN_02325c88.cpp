//cpp
// decomp: module=unk_autoload_0 addr=0x02325c88 name=FUN_02325c88
// NONMATCHING: byte-identical except two adjacent instructions are swapped - the target copies the parameter-register base into r2 before the store, mwcc schedules the store first. Pure instruction ordering. (div=1). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.

// Distance between two points via the hardware square-root unit.

#pragma thumb on
extern "C" {
int FUN_02325c88(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    *(volatile unsigned int *)0x040002B8 = dx * dx + dy * dy;
    while (*(volatile unsigned short *)0x040002B0 & 0x8000)
        ;
    return *(volatile int *)0x040002B4;
}
}
