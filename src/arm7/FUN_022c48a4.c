// decomp: module=arm7 addr=0x022c48a4 name=FUN_022c48a4
// flags: -O4,s -noThumb
// Same family as FUN_022c4820 / FUN_022c48e0, but the read-modify-write form:
// clears `mask` in REG_IE (0x04000210) and returns the previous REG_IE, with
// interrupts held off by FUN_022c4854 and the inlined swap-back (the old IME
// read is loaded and discarded, exactly as the ROM does). REG_IME is reached
// as REG_IE-8, so only one pool word is needed.
// NOTE: verify with --size 0x3c, not funcs.json's 0x38 - the boundary excludes
// this function's own trailing pool word.
extern unsigned short FUN_022c4854(void);

unsigned int FUN_022c48a4(unsigned int mask) {
    volatile unsigned int *ie = (volatile unsigned int *)0x04000210;
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    unsigned short saved = FUN_022c4854();
    unsigned int old = *ie;
    unsigned short dummy;

    *ie = old & ~mask;
    dummy = *ime;
    *ime = saved;
    return old;
}
