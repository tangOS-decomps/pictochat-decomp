// decomp: module=arm7 addr=0x022d71b4 name=FUN_022d71b4
// flags: -O4,s -noThumb

// Range-checks a byte-sized setting and parks it at +0x3c2 of the ARM7 state
// block pointed to by 0x0380fff4, first clearing the companion halfword at
// +0x3c4.  Out-of-range input is rejected with error 5, success reports 0.
// The block pointer is re-read for the second store because the first store
// may alias it.

typedef struct Arm7State {
    char pad[0x3c2];
    unsigned short value;   // +0x3c2
    unsigned short aux;     // +0x3c4
} Arm7State;

int FUN_022d71b4(unsigned int v)
{
    if (v > 0xff) return 5;

    (*(Arm7State **)0x0380fff4)->aux = 0;
    (*(Arm7State **)0x0380fff4)->value = (unsigned short)v;
    return 0;
}
