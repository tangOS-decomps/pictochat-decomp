// decomp: module=arm7 addr=0x022c2ac4 name=FUN_022c2ac4
// flags: -O4,s -noThumb
// size: 0x10c - the nominal 0xfc excludes the four trailing pool words.
//
// Wireless interrupt handler for bit 0x80. Acks it; when bit 5 of the feature
// word at +0x690 is set, the RF state (0x04808214 low byte) is 3..5 and the
// counter at 0x04808268 lies inside the window given by the halved words at
// +0x42c+0x58 / +0x42c+0x30, it pulses bit 7 of 0x04808244. Then, unless the
// chip id reads 0x1440, while status bits 0x42 are both set it spins until
// 0x048082b8 changes, reporting 0x40 through the callee once 1000 polls pass.
//
// CALLEE NOTE: the `bl` decodes to 0x00dd48a8, like the placeholders in
// FUN_022c22b0 / FUN_022c2134 - FUN_00dd48a8 is a placeholder name.

typedef unsigned short u16;
typedef unsigned int u32;
typedef volatile unsigned short vu16;

typedef struct Ctx {
    char pad00[0x30];
    u32 f30;
    char pad34[0x24];
    u32 f58;
} Ctx;

extern void FUN_00dd48a8(int a);

#define ST (*(char **)0x0380fff4)

void FUN_022c2ac4(void)
{
    vu16 *io = (vu16 *)0x04808010;
    Ctx *c = (Ctx *)(ST + 0x42c);
    u16 rf;
    u16 cnt;
    u16 v;
    u32 i;

    io[0] = 0x80;
    if (*(u16 *)(ST + 0x690) & 0x20) {
        rf = *(vu16 *)0x04808214 & 0xff;
        cnt = *(vu16 *)0x04808268;
        if (rf >= 3 && rf <= 5 && cnt >= ((c->f58 >> 1) & 0xfff) &&
            cnt <= ((c->f30 >> 1) & 0xfff)) {
            *(vu16 *)0x04808244 |= 0x80;
            *(vu16 *)0x04808244 &= ~0x80;
        }
    }

    if (*(vu16 *)0x04808000 != 0x1440 && (*(vu16 *)0x0480819c & 0x42) == 0x42) {
        v = *(vu16 *)0x048082b8;
        if (v != 0) {
            i = 0;
            while (v == *(vu16 *)0x048082b8) {
                if (i++ > 1000) {
                    FUN_00dd48a8(0x40);
                    break;
                }
            }
        }
    }
}
