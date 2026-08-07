// decomp: module=arm7 addr=0x022c0fb4 name=FUN_022c0fb4
// flags: -O4,s -noThumb

// If the request word at *p is non-zero, hands it to the queue at +0x200 of the
// ARM7 state block and raises event (2, 0xb).

extern void FUN_022c0fec(void *queue, int req);
extern void FUN_022c0e48(int a, int b);

void FUN_022c0fb4(int *p)
{
    if (*p != 0) {
        FUN_022c0fec((void *)(*(int *)0x0380fff4 + 0x200), *p);
        FUN_022c0e48(2, 0xb);
    }
}
