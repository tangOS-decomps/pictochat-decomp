// decomp: module=arm7 addr=0x022c1b84 name=FUN_022c1b84
// flags: -O4,s -noThumb

// Wireless interrupt dispatcher. Loops while (W_IE & W_IF) at 0x04808010 has
// any pending bit set, invoking the handler for each cause in a fixed priority
// order, then sets bit 24 of the ARM7 status word at 0x0380fff8 on the way out.

extern void FUN_022c2ac4(void);
extern void FUN_022c2bd0(void);
extern void FUN_022c1c58(void);
extern void FUN_022c1ce4(void);
extern void FUN_022c1f88(void);
extern void FUN_00dd506c(void);
extern void FUN_022c2024(void);
extern void FUN_022c2134(void);
extern void FUN_022c2518(void);
extern void FUN_022c1ff4(void);
extern void FUN_022c22b0(void);
extern void FUN_022c29d4(int);

void FUN_022c1b84(void)
{
    unsigned int pend;

    for (;;) {
        pend = *(volatile unsigned short *)0x04808010 &
               *(volatile unsigned short *)0x04808012;
        if (pend == 0) {
            break;
        }
        if (pend & 0x0080) {
            FUN_022c2ac4();
        }
        if (pend & 0x0040) {
            FUN_022c2bd0();
        }
        if (pend & 0x8000) {
            FUN_022c1c58();
        }
        if (pend & 0x4000) {
            FUN_022c1ce4();
        }
        if (pend & 0x2000) {
            FUN_022c1f88();
        }
        if (pend & 0x0800) {
            FUN_00dd506c();
        }
        if (pend & 0x0008) {
            FUN_022c2024();
        }
        if (pend & 0x0004) {
            FUN_022c2134();
        }
        if (pend & 0x0001) {
            FUN_022c2518();
        }
        if (pend & 0x0030) {
            FUN_022c1ff4();
        }
        if (pend & 0x0002) {
            FUN_022c22b0();
        }
        if (pend & 0x1000) {
            FUN_022c29d4(1);
        }
    }

    *(unsigned int *)0x0380fff8 |= 0x01000000;
}
