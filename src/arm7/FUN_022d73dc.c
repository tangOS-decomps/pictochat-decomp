// decomp: module=arm7 addr=0x022d73dc name=FUN_022d73dc
// flags: -noThumb

// Sets bit 3 of the mode word at +0x33a of the ARM7 state block - the
// FUN_022d7144/FUN_022d717c shape - then republishes bit3 ^ bit5 of the
// updated word to the hardware register at 0x04808290.
//
// Spelled with 1-bit fields rather than hand shifts: the ROM extracts each bit
// with its own lsl/lsr pair, which the plain `(t << 28) >> 31 ^ (t << 26) >> 31`
// spelling gets factored into a single shared >>31.

typedef struct Mode {
    unsigned short b0 : 1;
    unsigned short b1 : 1;
    unsigned short b2 : 1;
    unsigned short b3 : 1;
    unsigned short b4 : 1;
    unsigned short b5 : 1;
    unsigned short rest : 10;
} Mode;

int FUN_022d73dc(unsigned int v)
{
    Mode *m;

    if (v > 1) return 5;

    m = (Mode *)(*(int *)0x0380fff4 + 0x33a);
    m->b3 = v;

    m = (Mode *)(*(int *)0x0380fff4 + 0x33a);
    *(unsigned short *)0x04808290 = m->b5 ^ m->b3;
    return 0;
}
