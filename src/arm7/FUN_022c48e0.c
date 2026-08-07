// decomp: module=arm7 addr=0x022c48e0 name=FUN_022c48e0
// flags: -O4,s -noThumb
// Same shape as FUN_022c4820 but for REG_IF (0x04000214): atomically replaces
// it and returns the previous value, with interrupts held off by the
// FUN_022c4854 / inlined-swap-back pair.
// NOTE: verify with --size 0x34, not funcs.json's 0x30 - the stated size
// excludes this function's own trailing pool word.
extern unsigned short FUN_022c4854(void);

unsigned int FUN_022c48e0(unsigned int value) {
    volatile unsigned int *irqflags = (volatile unsigned int *)0x04000214;
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    unsigned short saved = FUN_022c4854();
    unsigned int old = *irqflags;
    unsigned short dummy;

    *irqflags = value;
    dummy = *ime;
    *ime = saved;
    return old;
}
