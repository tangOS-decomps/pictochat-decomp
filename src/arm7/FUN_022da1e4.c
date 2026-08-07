// decomp: module=arm7 addr=0x022da1e4 name=FUN_022da1e4
// flags: -O4,s -noThumb

// Clears one bit in the DSi SD/SDIO-side register block selected by the
// half-word at +0x3d8 of the global context, but only for device class 0x40.
// `sel == 0` clears bit 0 of byte +4; otherwise the bit number returned by
// FUN_022da0e8 picks a byte at +5+(n>>3) and clears bit (n & 7).
// Both accesses go through the byte read/write helpers while the
// FUN_037c9084/FUN_037c904c critical section is held.
//
// NOTE ON SIGNATURES: FUN_022d8d40's value argument is declared unsigned char
// here (elsewhere in src/ it is int) because this call site narrows to 8 bits;
// the bl reloc is wildcarded so the two declarations do not have to agree.

extern int FUN_022d9ffc(int sel);
extern unsigned int FUN_022da0e8(int sel);
extern int FUN_037c9084(int lock);
extern void FUN_037c904c(int token);
extern int FUN_022d8d6c(unsigned char *src);
extern void FUN_022d8d40(unsigned char *dst, unsigned char v);

extern int G_0380fff4;

void FUN_022da1e4(int sel)
{
    unsigned char *reg;
    int token;
    unsigned int bit;

    if (FUN_022d9ffc(sel) != 0x40) {
        return;
    }

    reg = (unsigned char *)0x0480425c +
          *(unsigned short *)((char *)G_0380fff4 + 0x3d8);
    token = FUN_037c9084(0x01000000);

    if (sel == 0) {
        FUN_022d8d40(reg + 4, (unsigned char)(FUN_022d8d6c(reg + 4) & 0xfe));
    } else {
        bit = FUN_022da0e8(sel);
        reg = reg + 5 + (bit >> 3);
        FUN_022d8d40(reg, (unsigned char)(FUN_022d8d6c(reg) & ~(1 << (bit & 7))));
    }

    FUN_037c904c(token);
}
