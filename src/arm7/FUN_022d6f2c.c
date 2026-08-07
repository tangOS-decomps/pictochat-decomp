// decomp: module=arm7 addr=0x022d6f2c name=FUN_022d6f2c
// flags: -O4,s -noThumb
//
// Records a requested channel mask. Rejects a mask with no bit in 0x7ffe with
// error 5; otherwise stores it at +0x32c of the object behind the global at
// 0x0380fff4 and raises the pending-request bit 2 in the flag word at +0x340.
// The global is reloaded for the second access - the halfword store may alias
// it - which is what the target's two `ldr r?,[r2]` are.

typedef struct Ctx300 {
    char pad00[0x2c];
    unsigned short chan;
} Ctx300;

extern char *G_0380fff4;

int FUN_022d6f2c(int mask)
{
    Ctx300 *c;

    if ((mask & 0x7ffe) == 0)
        return 5;

    c = (Ctx300 *)(G_0380fff4 + 0x300);
    c->chan = (unsigned short)mask;

    *(unsigned int *)(G_0380fff4 + 0x340) |= 4;
    return 0;
}
