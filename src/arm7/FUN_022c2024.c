// decomp: module=arm7 addr=0x022c2024 name=FUN_022c2024
// flags: -O4,s -noThumb
//
// Per-frame WiFi housekeeping.  Kicks the register at 0x04808010, optionally
// flips the low bit of 0x04808290 when the state block asks for it, and - when
// bit 3 of the +0x690 status word is set - walks the three transmit slots at
// +0x42c and retires any queued frame whose trailer has already been cleared
// by the hardware.
// The slot walk recomputes `base + i * 0x14` every iteration instead of
// bumping a cursor, so strength reduction has to be off.
// Verify with size 0x110, not 0x104 - the stated size excludes this function's
// own three trailing pool words.

#pragma opt_strength_reduction off

typedef struct Flags2024 {
    unsigned short pad0 : 4;
    unsigned short toggle : 1;
    unsigned short pad5 : 11;
} Flags2024;

typedef struct Slot2024 {
    unsigned short active;
    char pad2[6];
    unsigned char *frame;
    char padc[8];
} Slot2024;

// The WiFi registers are spelled as literal addresses, not as an extern symbol:
// that is what puts real literals (0x04808010, 0x04808032) in the pool and lets
// mwcc reach 0x0480819c / 0x04808290 with an `add` off the base it already
// materialised, instead of emitting relocated pool words of its own.

void FUN_022c2024(void) {
    unsigned char *base;
    unsigned char *chan;
    unsigned int i;
    Slot2024 *slots;
    unsigned char *frame;
    unsigned short *trailer;

    *(volatile unsigned short *)0x04808010 = 8;
    if (((Flags2024 *)(*(unsigned char **)0x0380fff4 + 0x33a))->toggle) {
        if ((*(volatile unsigned short *)0x0480819c & 1) == 0) {
            *(volatile unsigned short *)0x04808290 =
                *(volatile unsigned short *)0x04808290 ^ 1;
        }
    }

    base = *(unsigned char **)0x0380fff4;
    if ((*(unsigned short *)(base + 0x690) & 8) != 0) {
        chan = base + 0x344;
        slots = (Slot2024 *)(base + 0x42c);

        for (i = 0; i < 3; i++) {
            if (slots[i].active != 0) {
                frame = slots[i].frame;
                if ((*(unsigned short *)(frame + 0xc) & 0x4000) != 0 &&
                    (*(unsigned short *)(frame + 4) & 0xff) != 0) {
                    trailer = (unsigned short *)(((unsigned int)(frame + 0xc +
                                                                *(unsigned short *)(frame + 0xa)) -
                                                  7) &
                                                 ~1);
                    if (trailer[0] == 0 && trailer[1] == 0) {
                        *(unsigned short *)(frame + 4) = 0;
                        *(volatile unsigned short *)0x04808032 = 0;
                        *(volatile unsigned short *)0x04808032 = 0x8000;
                        *(unsigned short *)(chan + 0xba) =
                            *(unsigned short *)(chan + 0xba) + 1;
                    }
                }
            }
        }
    }
}
