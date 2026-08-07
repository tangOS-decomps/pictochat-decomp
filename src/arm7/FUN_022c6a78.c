// decomp: module=arm7 addr=0x022c6a78 name=FUN_022c6a78
// flags: -O4,s -noThumb

// Marks a wifi work item as "done" (+0x24 = 1) under an interrupt-disabled
// critical section; if a completion callback is still installed at +0x00 it is
// run once through FUN_022c688c and then cleared.

extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);
extern void FUN_022c688c(int *work);

void FUN_022c6a78(int *work)
{
    int state = FUN_022c6d40();

    work[9] = 1;
    if (work[0] == 0) {
        FUN_022c6d54(state);
    } else {
        FUN_022c688c(work);
        work[0] = 0;
        FUN_022c6d54(state);
    }
}
