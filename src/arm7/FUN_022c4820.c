// decomp: module=arm7 addr=0x022c4820 name=FUN_022c4820
// flags: -O4,s -noThumb
// Atomically replaces REG_IE (0x04000210) and returns its previous value.
// FUN_022c4854 is the "read REG_IME and clear it" primitive; the restore is
// the inlined swap-back (the old IME read is loaded and discarded, exactly
// as the ROM does).
// NOTE: verify with --size 0x34, not funcs.json's 0x30 - the stated size
// excludes this function's own trailing pool word.
extern unsigned short FUN_022c4854(void);

unsigned int FUN_022c4820(unsigned int mask) {
    volatile unsigned int *ie = (volatile unsigned int *)0x04000210;
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    unsigned short saved = FUN_022c4854();
    unsigned int old = *ie;
    unsigned short dummy;

    *ie = mask;
    dummy = *ime;
    *ime = saved;
    return old;
}
