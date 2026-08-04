// decomp: module=arm7 addr=0x022c4854 name=FUN_022c4854
// flags: -noThumb
// Reads REG_IME (0x04000208), clears it, and returns the previous value -
// the standard "disable interrupts, remember old state" primitive; the
// matching restore is presumably a sibling that writes the value back.
// NOTE: verify with --size 0x18, not funcs.json's 0x14 - Ghidra's boundary
// excludes this function's own trailing pool word (see funcs.true_size).
unsigned short FUN_022c4854(void) {
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    unsigned short old = *ime;
    *ime = 0;
    return old;
}
