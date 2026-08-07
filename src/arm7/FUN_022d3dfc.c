// decomp: module=arm7 addr=0x022d3dfc name=FUN_022d3dfc
// flags: -O4,s -noThumb
//
// Beacon/VBlank clock skew corrector.  While the scanline counter is inside the
// 0xd0..0xd1 window it drains an accumulated tick debt (ctx +0xd8) in units of
// 63, pulls REG_VCOUNT back by however many units it drained, and clears the
// +0x1c flag once the debt is still at/over the 0x7f threshold.  Then it hands
// the (signed) +0x42 counter to the shared WRAM routine at 0x037cb0b8.

typedef struct Ctx {
    char pad0[0x1c];
    int f1c;                // +0x1c
    char pad1[0x22];
    short f42;              // +0x42
    char pad2[0x94];
    volatile unsigned int debt;  // +0xd8 - reloaded at every read in the ROM
} Ctx;

typedef struct ConnMgr {
    char pad[0x550];
    Ctx *ctx;               // +0x550
} ConnMgr;

extern ConnMgr G_023190dc;

extern void func_037cb0b8(void *a, int b, int c, void *d, int e);

void FUN_022d3dfc(void)
{
    int i;
    int vc = *(volatile unsigned short *)0x04000006;
    Ctx *c = G_023190dc.ctx;

    if (vc >= 0xd0 && vc < 0xd2 && c->debt >= 0x7f) {
        for (i = 1; i < 7; i++) {
            if (c->debt < (unsigned int)(i * 63 + 0x7f)) {
                break;
            }
        }
        *(volatile unsigned short *)0x04000006 = (unsigned short)(vc + (1 - i));
        c->debt -= i * 63;
    }

    if (c->debt >= 0x7f) {
        c->f1c = 0;
    }

    func_037cb0b8((void *)0x03807230, c->f42, 0x107, (void *)0x0230716c, 4);
}
