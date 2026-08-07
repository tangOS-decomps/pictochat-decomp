// decomp: module=arm7 addr=0x022c22b0 name=FUN_022c22b0
// flags: -O4,s -noThumb
// size: 0x250 - the stated 0x248 excludes the trailing pool words.
//
// Wireless frame-end interrupt handler. Acknowledges the interrupt, bails out
// to the fatal handler in state 0x12, then dispatches on the 0xf00 field of
// the status register at 0x048080b8:
//   0x300 - abort/retry path: optionally runs the abort hook, bumps the global
//           error counter and reports event 8;
//   0x800 - CCA path: raises the retry-limit flag when the retry count has
//           reached the descriptor's limit, and bumps the per-link counter;
//   0xb00 - ack/beacon path: resets the four ack registers to 0xffff, clears a
//           stale broadcast descriptor, optionally toggles the antenna bit,
//           and walks the per-peer bitmask crediting each acknowledged peer.
// The tail then, for everything except 0x800, kicks the next transmission and
// finally reports event 0xe.
//
// CALLEE NOTE: the `bl` at +0x34 decodes to 0x00dd8cfc, which is not a
// plausible ARM7 code address (neither 0x02xxxxxx nor 0x037xxxxx). It is
// almost certainly a veneer/unresolved slot rather than a real target, so
// FUN_00dd8cfc below is a placeholder name and NOT a resolved callee.

typedef struct {
    unsigned char  pad00[2];
    unsigned short f02;
    unsigned short f04;
    unsigned char  pad06[0x1c];
    unsigned short f22;
} Desc;

typedef struct {
    unsigned char  pad00[6];
    unsigned short f06;
} Elem;

typedef struct {
    unsigned char  pad00[0x16];
    unsigned short f16;
    unsigned short f18;
} Blk;

typedef struct {
    unsigned char  pad00[0x3c];
    unsigned short f3c;
    unsigned char  pad3e[6];
    Desc          *f44;
    unsigned char  pad48[0x44];
    unsigned int   f8c;
    Blk           *f90;
    unsigned char  pad94[4];
    unsigned short f98;
    unsigned char  pad9a[4];
    unsigned short f9e;
    unsigned char  pada0[8];
    unsigned short fa8;
    unsigned short faa;
    unsigned short fac;
} Ctx;

typedef struct {
    unsigned short b0 : 4;
    unsigned short b4 : 1;
    unsigned short b5 : 11;
} Flags33a;

typedef struct {
    unsigned char  pad000[0x33a];
    Flags33a       f33a;
    unsigned char  pad33c[0x10];
    unsigned short f34c;
    unsigned char  pad34e[0x20a];
    unsigned int   f558;
    unsigned char  pad55c[0x134];
    unsigned short f690;
} State;

extern void FUN_00dd8cfc(void); /* placeholder - see CALLEE NOTE above */
extern void FUN_022c2e40(void);
// Declared with an argument on purpose: the `2` stored to 0x048080b4 is still
// live in r0 at this call, i.e. mwcc materialised it once as the call's
// argument and reused it for the store. Declaring it void inverts the
// colouring of the whole surrounding block (see the batch lever notes).
extern void FUN_022c29d4(int mode);
extern void FUN_022c0e48(int a, int b);

void FUN_022c22b0(void)
{
    volatile unsigned short *io = (volatile unsigned short *)0x04808010;
    volatile unsigned short *ack;
    volatile unsigned short *ant;
    Ctx *c;
    Desc *d;
    unsigned short lim;
    unsigned short m0;
    unsigned short m1;
    Elem *p;
    int kind;

    c = (Ctx *)(*(char **)0x0380fff4 + 0x42c);
    io[0] = 2;

    if ((*(State **)0x0380fff4)->f34c == 0x12) {
        FUN_00dd8cfc();
        return;
    }

    kind = io[0x54] & 0xf00;

    switch (kind) {
    case 0x300:
        if (c->f8c & 2) {
            FUN_022c2e40();
        }
        (*(State **)0x0380fff4)->f558++;
        FUN_022c0e48(0, 8);
        break;

    case 0x800:
        d = c->f44;
        lim = d->f04 & 0xff;
        if (c->f9e <= lim) {
            io[0x4e] = 2;
            c->fa8++;
        }
        c->f90->f18++;
        break;

    case 0xb00:
        ack = (volatile unsigned short *)0x04805f70;
        ack[0] = 0xffff;
        ack[1] = 0xffff;
        *(volatile unsigned short *)0x0480824c = 0xffff;
        *(volatile unsigned short *)0x0480824e = 0xffff;

        if (c->f3c != 0) {
            d = c->f44;
            if (d->f22 == 0xffff) {
                if (d->f04 != 0) {
                    d->f04 = 0;
                    c->f44->f02 = c->f98;
                }
            }
        }

        m1 = c->f44->f02;
        m0 = c->f98;
        p = (Elem *)((char *)c->f90 + 0x1a);

        if (m1 > 1) {
            if ((*(State **)0x0380fff4)->f33a.b4) {
                ant = (volatile unsigned short *)0x0480819c;
                if (!(ant[0] & 1)) {
                    ant[0x7a] ^= 1;
                }
            }
        }

        if ((*(State **)0x0380fff4)->f690 & 0x40) {
            while (m1 > 1) {
                m1 >>= 1;
                if (m1 & 1) {
                    p->f06++;
                }
                m0 >>= 1;
                if (m0 & 1) {
                    p = (Elem *)((char *)p + c->f90->f16);
                }
            }
        }
        break;
    }

    if (kind != 0x800) {
        if (!(*(volatile unsigned short *)0x048080b0 & 2)) {
            if (c->f3c != 0) {
                *(volatile unsigned short *)0x048080b4 = 2;
                *(volatile unsigned short *)0x04808048 = 0;
                if (*(volatile unsigned short *)0x04808010 & 0x1000) {
                    c->fac++;
                } else {
                    FUN_022c29d4(2);
                }
                c->faa++;
            }
            *(volatile unsigned short *)0x048080ae = 2;
        }
    }

    FUN_022c0e48(0, 0xe);
}
