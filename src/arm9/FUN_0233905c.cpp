//cpp
// decomp: module=unk_autoload_0 addr=0x0233905c name=FUN_0233905c
// NONMATCHING: identical instruction stream; the target hoists the `ldr r4, [pc]` for the loop variable's address above the entry guard, mwcc sinks it past the branch. (div=2). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.

// Spins the pending queue out while running in IRQ mode (0x12).

#pragma thumb on
extern "C" {
extern int FUN_023320e4(void);
extern void FUN_02338390(void);
extern int G_023c3564[];
extern int G_023c3590[];
void FUN_0233905c(void)
{
    if (G_023c3564[11] == 0) return;
    do {
        if (FUN_023320e4() == 0x12) FUN_02338390();
    } while (G_023c3590[0] != 0);
}
}
