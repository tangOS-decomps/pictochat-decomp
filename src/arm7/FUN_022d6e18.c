// decomp: module=arm7 addr=0x022d6e18 name=FUN_022d6e18
// flags: -O4,s -noThumb
// size: 0x80 - the nominal 0x7c excludes the trailing pool word (0x0380fff4).

// Resets the ARM7 state block's link-session area: saves the word at +0x3e0,
// zeroes +0x31c..+0x344 and +0x344..+0x404, then re-seeds +0x31c with the new
// descriptor and +0x320/+0x322 with `count`, and restores +0x3e0.
//
// The block base is re-read from the global on every access - each helper call
// and each store may alias it - which is what spelling the global as a literal
// deref (rather than caching it in a local) reproduces. The literal form is
// also what colours the pool address r3 and the narrowed count r1; an
// `extern unsigned char *G_0380fff4;` gets the same shape with r1/r3 swapped.

#define G_0380fff4 (*(unsigned char **)0x0380fff4)

// Signature inferred from register liveness at the bl: r0 = fill value,
// r1 = destination, r2 = byte count.
extern void FUN_037cb774(int value, void *dst, unsigned int len);

void FUN_022d6e18(int desc, int count)
{
    int saved;
    unsigned short n;

    saved = *(int *)(G_0380fff4 + 0x3e0);
    FUN_037cb774(0, G_0380fff4 + 0x31c, 0x28);
    FUN_037cb774(0, G_0380fff4 + 0x344, 0xc0);
    *(int *)(G_0380fff4 + 0x31c) = desc;
    *(unsigned short *)(G_0380fff4 + 0x320) = (unsigned short)count;
    *(unsigned short *)(G_0380fff4 + 0x322) = (unsigned short)count;
    *(int *)(G_0380fff4 + 0x3e0) = saved;
}
