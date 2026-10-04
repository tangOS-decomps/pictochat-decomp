// decomp: module=arm7 addr=0x022c2134 name=FUN_022c2134
// flags: -O4,s -noThumb
// size: 0x17c - the nominal 0x160 excludes the seven trailing pool words.
//
// Wireless interrupt handler for bit 2. Acks it, then (when bit 3 of the
// feature word at +0x690 is set and the status register at 0x048081a8 reports
// 0x400) checks whether any of the three TX queues in the block at +0x42c
// still holds a frame, or the RF busy bit is up. If nothing is pending the
// watchdog counter at +0x4de is reset after pulsing 0x04808032; otherwise it
// is advanced, and past 12 ticks it is reset, the register pulsed and the
// error counter at +0x3fe bumped.
//
// Then, with bit 0 of +0x690 set and status bits 0x60 present, the RX read
// pointer is resynced when it lies outside the half-window, and the RX
// handler is called.
//
// CALLEE NOTE: the final `bl` decodes to 0x00dd47ac, like the placeholder in
// FUN_022c22b0 - FUN_00dd47ac is a placeholder name, not a resolved callee.

typedef unsigned short u16;
typedef volatile unsigned short vu16;

extern void FUN_00dd47ac(void);

#define ST (*(char **)0x0380fff4)

void FUN_022c2134(void)
{
    vu16 *io = (vu16 *)0x04808010;
    u16 *cnt = (u16 *)(ST + 0x4dc);
    u16 *q = (u16 *)(ST + 0x42c);
    u16 sts;
    u16 f;
    u16 rd;

    io[0] = 4;
    sts = *(vu16 *)0x048081a8;

    if ((*(u16 *)(ST + 0x690) & 8) && (sts & 0x400)) {
        f = io[0x50];
        if (!(((f & 1) && q[0] != 0) || ((f & 4) && q[10] != 0) ||
              ((f & 8) && q[20] != 0) || (*(vu16 *)0x0480819c & 1))) {
            *(vu16 *)0x04808032 = 0;
            *(vu16 *)0x04808032 = 0x8000;
            cnt[1] = 0;
        } else if (cnt[1]++ > 12) {
            cnt[1] = 0;
            *(vu16 *)0x04808032 = 0;
            *(vu16 *)0x04808032 = 0x8000;
            (*(u16 *)(ST + 0x3fe))++;
        }
    }

    if ((*(u16 *)(ST + 0x690) & 1) && (sts & 0x60)) {
        rd = *(vu16 *)0x04808054;
        if (rd >= (*(vu16 *)0x04808052 - 0x4000) / 2 ||
            rd < (*(vu16 *)0x04808050 - 0x4000) / 2) {
            *(vu16 *)0x04808056 = *(vu16 *)0x0480805a;
            *(vu16 *)0x04808030 = 0x8001;
        }
        FUN_00dd47ac();
    }
}
