// decomp: module=arm7 addr=0x022c8600 name=FUN_022c8600
// flags: -O4,s

// Maps a 0..0x7f index onto a 16-bit period. The two topmost slots are
// saturated specials (0x7f -> 0xffff, 0x7e -> 0x3c00, which would otherwise
// divide by zero); below 0x32 the answer is the cheap linear 2*n+1, and the
// rest go through the reciprocal helper as 0x1e00 / (0x7e - n).
// Every arm funnels into one shared epilogue, so this has to be written as a
// single result variable with one return - four separate `return`s make mwcc
// emit four copies of the pop/pop/bx tail (exactly 0xc bytes too many).

#pragma thumb on

extern int FUN_022c8640(int num, int den);

unsigned short FUN_022c8600(int n)
{
    unsigned short r;
    if (n == 0x7f) {
        r = 0xffff;
    } else if (n == 0x7e) {
        r = 0x3c00;
    } else if (n < 0x32) {
        r = (unsigned short)(n * 2 + 1);
    } else {
        r = (unsigned short)FUN_022c8640(0x1e00, 0x7e - n);
    }
    return r;
}
