// decomp: module=arm7 addr=0x022d85b4 name=FUN_022d85b4
// flags: -O4,s -noThumb
//
// Reads the mode halfword at +0x330 of the object hanging off the global at
// 0x0380fff4 and turns it into a timing value: mode 0 yields 10 only when bit
// 0 of the flags halfword at +0x3a4 is set, mode 1 always yields 10, and
// anything else (including mode 0 with the bit clear) yields 20.
//
// The two field offsets are past what a ldrh displacement can reach, so the
// object is described from its own base and mwcc hoists the shared
// `add rN,rN,#0x300` itself - writing the +0x300 as an explicit pointer local
// instead inverts the colouring of the base and the mode temp.

typedef struct Ctx {
    char pad000[0x330];
    unsigned short mode;
    char pad332[0x72];
    unsigned short flags;
} Ctx;

extern Ctx *G_0380fff4;

int FUN_022d85b4(void)
{
    switch (G_0380fff4->mode) {
    case 0:
        if (G_0380fff4->flags & 1)
            return 10;
        break;
    case 1:
        return 10;
    }
    return 20;
}
