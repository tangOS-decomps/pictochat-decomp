// decomp: module=arm7 addr=0x022d7518 name=FUN_022d7518
// flags: -noThumb

// Sets bit 6 of the mode word at +0x33a of the ARM7 state block, rejecting
// anything above 1 with code 5 - the FUN_022d7144 / FUN_022d717c shape.
//
// Unlike those two, the bit here has to be written as a real 1-bit BITFIELD,
// not as a hand-rolled mask/shift on the halfword. The ROM converts the
// argument to the bitfield's `unsigned short` container first (lsl #16 / lsr
// #16) and only then shifts it into place (lsl #31 / lsr #25); every spelling
// that shifts `v` directly lets the optimizer drop the zero-extension, which
// comes out two instructions short.

typedef struct {
    char pad[0x33a];
    unsigned short b0 : 1;
    unsigned short b1 : 1;
    unsigned short b2 : 1;
    unsigned short b3 : 1;
    unsigned short b4 : 1;
    unsigned short b5 : 1;
    unsigned short b6 : 1;
    unsigned short b7 : 1;
} State022d7518;

int FUN_022d7518(unsigned int v)
{
    State022d7518 *s;
    if (v > 1) return 5;
    s = (State022d7518 *)*(int *)0x0380fff4;
    s->b6 = v;
    return 0;
}
