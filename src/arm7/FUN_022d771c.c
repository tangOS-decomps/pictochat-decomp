// decomp: module=arm7 addr=0x022d771c name=FUN_022d771c
// flags: -O4,s -noThumb

// Stores a 10..1000 interval into +0x3b2 of the ARM7 state block and into the
// hardware register at 0x0480808c, then reprograms from the mode word at
// +0x338. Out-of-range values are rejected with code 5.
//
// Single-exit spelling is required: the ROM branches the reject path to the
// shared pop/bx epilogue instead of emitting its own.

extern void FUN_022d7e6c(unsigned short mode);

int FUN_022d771c(unsigned short v)
{
    int r;

    if (v < 10 || v > 1000) {
        r = 5;
    } else {
        *(unsigned short *)(*(int *)0x0380fff4 + 0x3b2) = v;
        *(unsigned short *)0x0480808c = v;
        FUN_022d7e6c(*(unsigned short *)(*(int *)0x0380fff4 + 0x338));
        r = 0;
    }
    return r;
}
