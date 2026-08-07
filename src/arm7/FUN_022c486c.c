// decomp: module=arm7 addr=0x022c486c name=FUN_022c486c
// flags: -noThumb

// OS_EnableIrqMask: disables interrupts, ORs the requested bits into REG_IE
// (0x04000210), restores the previous REG_IME and returns the old REG_IE.
// The restore helper's own return value (the REG_IME read) is discarded here,
// which is why an otherwise dead ldrh survives.

extern unsigned short FUN_022c4854(void);

unsigned int FUN_022c486c(unsigned int mask)
{
    volatile unsigned int *ie = (volatile unsigned int *)0x04000210;
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    unsigned short e = FUN_022c4854();
    unsigned int old = *ie;
    unsigned short prev;
    *ie = old | mask;
    prev = *ime;
    *ime = e;
    return old;
}
