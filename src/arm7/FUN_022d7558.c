// decomp: module=arm7 addr=0x022d7558 name=FUN_022d7558
// flags: -O4,s -noThumb
// Sets a 1-bit flag (bit 7 of the halfword at +0x33a of the global WiFi
// context) and, when enabling, copies a WiFi register.
// The bit insert must come from an `unsigned short` BITFIELD store, not from
// `(f & ~0x80) | ((mode & 1) << 7)`: the bitfield container type is what makes
// mwcc first zero-extend the argument to 16 bits (lsl #16 / lsr #16) before
// the lsl #31 / lsr #24 insert. The plain expression folds those two shifts
// into a single lsl #31 and comes out one word short.
// mwccarm allocates unsigned-short bitfields LSB-first here, so `a:7` then
// `flag:1` lands flag on bit 7 (mask 0x80) - `a:8, flag:1` gives 0x100.
typedef struct Ctx7558 {
    char pad[0x33a];
    unsigned short a : 7;
    unsigned short flag : 1;
    unsigned short b : 8;
} Ctx7558;

extern Ctx7558 *G_0380fff4;

unsigned int FUN_022d7558(unsigned int mode) {
    Ctx7558 *c;
    if (mode > 1) {
        return 5;
    }
    c = G_0380fff4;
    c->flag = mode;
    if (mode == 1) {
        *(volatile unsigned short *)0x04808028 = *(volatile unsigned short *)0x0480802a;
    }
    return 0;
}
