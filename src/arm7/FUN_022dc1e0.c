// decomp: module=arm7 addr=0x022dc1e0 name=FUN_022dc1e0
// flags: -noThumb

// Stamps 1 into the caller's status halfword and reports success. Only when
// the ARM7 state block's mode word at +0x34c reads 0x10 is the real handler
// FUN_022d6e98 run on the payload at +0x10, and its result becomes the answer.

extern int FUN_022d6e98(void *);

int FUN_022dc1e0(char *pkt, unsigned short *status)
{
    int r = 1;
    status[1] = 1;
    if (*(unsigned short *)((char *)*(int *)0x0380fff4 + 0x34c) == 0x10) {
        r = FUN_022d6e98(pkt + 0x10);
    }
    return r;
}
