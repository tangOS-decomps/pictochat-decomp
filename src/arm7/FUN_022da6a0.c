// decomp: module=arm7 addr=0x022da6a0 name=FUN_022da6a0
// flags: -O4,s -noThumb

// Drains the pending-entry list at +0x1f4 of the ARM7 state block: each entry
// is handed to the queue at +0x304 and, once accepted, unlinked. Stops early
// if the queue refuses an entry.

extern int FUN_037c9e90(void *q, int item, int block);
extern void FUN_037c583c(void *list, int item);

void FUN_022da6a0(void)
{
    char *base = *(char **)0x0380fff4;
    int item = *(int *)(base + 0x1f4);

    while (item != -1) {
        if (FUN_037c9e90(*(void **)(base + 0x304), item, 0) == 0) break;
        base = *(char **)0x0380fff4;
        FUN_037c583c(base + 0x1f4, item);
        base = *(char **)0x0380fff4;
        item = *(int *)(base + 0x1f4);
    }
}
