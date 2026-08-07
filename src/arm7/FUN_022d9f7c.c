// decomp: module=arm7 addr=0x022d9f7c name=FUN_022d9f7c
// flags: -O4,s -noThumb
// size: 0x80 - the stated 0x7c excludes the trailing pool word (0x0380fff4).
//
// Tears down slot `idx`: releases it, and if it owned a bit in the active
// mask, clears the slot's state word, drops the bit, and decrements the live
// count - running the all-idle hook when the count reaches zero.

typedef struct {
    unsigned short f00;
    unsigned short f02;
    unsigned char  pad04[0x18];
} Slot;

typedef struct {
    unsigned char  pad000[0x31c];
    Slot          *f31c;
    unsigned char  pad320[0x218];
    unsigned short f538;
    unsigned short f53a;
} State;

extern State *G_0380fff4;
extern void FUN_022da1e4(int idx);
extern int FUN_022da0e8(int idx);
extern void FUN_022d7ed0(void);

void FUN_022d9f7c(int idx)
{
    State *s = G_0380fff4;
    int bit;

    FUN_022da1e4(idx);

    bit = FUN_022da0e8(idx);
    if (bit != 0) {
        G_0380fff4->f31c[idx].f02 = 0;
        s->f53a &= ~(1 << bit);
        s->f538--;
        if (s->f538 == 0) {
            FUN_022d7ed0();
        }
    }
}
