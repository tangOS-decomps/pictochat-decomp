// decomp: module=arm7 addr=0x022c2f08 name=FUN_022c2f08
// flags: -O4,s -noThumb
// size: 0x68 - includes the two trailing pool words.

// Under an interrupt lock: kicks the wifi block at +0x34 of 0x04808210, spins
// up to 100 times waiting for the status halfword to change, then clears
// 0x04808244 and runs FUN_022c29d4.
//
// 0x04808244 is reached two different ways - once as +0x34 off the 0x04808210
// base, once through its own pool word - so the two accesses have to be spelled
// differently in source or mwcc folds them onto one base.
//
// FUN_022c29d4 TAKES AN ARGUMENT, and that is what pins the registers: the ROM
// puts the store's address in r1 and the zero in r0, because the same zero is
// still live in r0 across the following `bl` - it is the call's argument, not
// just the value being stored. Declared `void FUN_022c29d4(void)` the colouring
// comes out inverted and nothing else fixes it.

extern unsigned int FUN_022c48a4(unsigned int mask);
extern unsigned int FUN_022c486c(unsigned int mask);
extern void FUN_022c29d4(int mode);

void FUN_022c2f08(void)
{
    volatile unsigned short *p = (volatile unsigned short *)0x04808210;
    volatile unsigned short *q = (volatile unsigned short *)0x04808244;
    unsigned int saved;
    unsigned short v;
    int i;

    saved = FUN_022c48a4(0x1000000);
    v = p[0];
    p[0x1a] = 0x1000;
    i = 0x64;
    while (i != 0) {
        if (v != p[0]) break;
        i--;
    }
    *q = 0;
    FUN_022c29d4(0);
    FUN_022c486c(saved);
}
