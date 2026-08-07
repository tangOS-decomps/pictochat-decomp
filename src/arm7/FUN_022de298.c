// decomp: module=arm7 addr=0x022de298 name=FUN_022de298
// flags: -O4,s -noThumb
//
// Decides whether a received frame is still inside the lifetime window: the
// beacon interval at +0x8c is scaled up by 8, then scaled back down again for
// the frame types that carry the short timestamp, and compared against the age
// derived from the running timer at +0xa8.

typedef struct Pkt298 {
    char pad0[4];
    unsigned short f04;
    char pad1[0x14 - 0x06];
    unsigned short kind : 2;
    unsigned short mode : 2;
    unsigned short sub : 4;
} Pkt298;

typedef struct Ctx298 {
    char pad0[0x0c];
    unsigned short f0c;
    char pad1[0x8c - 0x0e];
    unsigned short f8c;
    char pad2[0xa8 - 0x8e];
    unsigned int fa8;
} Ctx298;

int FUN_022de298(Pkt298 *p)
{
    Ctx298 *c = (Ctx298 *)(*(char **)0x0380fff4 + 0x344);
    unsigned short v;

    v = (unsigned short)(c->f8c << 3);
    if (p->mode == 0) {
        if (c->f0c == 1) {
            unsigned int k = p->sub;
            if (k == 1 || k == 3 || k == 0xb) {
                v = (unsigned short)(v >> 3);
            }
        }
    } else {
        v = (unsigned short)(v >> 3);
    }
    return v < (unsigned short)(c->fa8 - p->f04);
}
