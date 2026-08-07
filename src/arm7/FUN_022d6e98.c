// decomp: module=arm7 addr=0x022d6e98 name=FUN_022d6e98
// flags: -O4,s -noThumb

// Queues one descriptor: rejects it with code 5 if bit 0 of its flags word is
// already set (still owned by hardware), otherwise links it onto the software
// list at +0x324 of the ARM7 state block *and* the hardware list at 0x04808018,
// then raises bit 1 of the pending mask at +0x340.

extern void FUN_022d811c(void *list, unsigned short *desc);

int FUN_022d6e98(unsigned short *desc)
{
    if (*desc & 1) return 5;

    FUN_022d811c((void *)(*(int *)0x0380fff4 + 0x324), desc);
    FUN_022d811c((void *)0x04808018, desc);

    *(int *)(*(int *)0x0380fff4 + 0x340) |= 2;
    return 0;
}
