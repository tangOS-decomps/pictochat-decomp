//cpp
// decomp: module=unk_autoload_0 addr=0x02339084 name=FUN_02339084
// NONMATCHING: the drain loop and both guards match; the target hoists the IME and queue-address pool loads above the entry guard, mwcc sinks them past the branch. (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.

// Drains the pending queue, pumping it by hand whenever the CPU is in the
// wrong mode or interrupts are masked off.

#pragma thumb on
extern "C" {
extern int FUN_023320d8(void);
extern void FUN_02338390(void);
extern int G_023c3564[];
extern int G_023c3590;
void FUN_02339084(void)
{
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;

    if (G_023c3564[11] == 0) return;
    do {
        if (FUN_023320d8() == 0x80 || *ime == 0) FUN_02338390();
    } while (G_023c3590 != 0);
}
}
