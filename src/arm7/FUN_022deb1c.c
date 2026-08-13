// decomp: module=arm7 addr=0x022deb1c name=FUN_022deb1c
// flags: -noThumb
// size: 0x74 - the stated 0x6c excludes the two trailing pool words.

// Power-off half of FUN_022deb90: with the source's interrupts masked, kicks
// FUN_022d80f8(0) unless bit 7 of the halfword at +0x33a is set, writes 0xc0
// to the 0x048080b4 control halfword and clears the pending +0x47c/+0x490
// halfwords before restoring the mask.

typedef struct Pendeb1c {
    char pad[0x50];
    unsigned short f50;  /* +0x47c in the state block */
    char pad2[0x64 - 0x52];
    unsigned short f64;  /* +0x490 in the state block */
} Pendeb1c;

typedef struct Stateeb1c {
    char pad[0x33a];
    unsigned short f33a_lo : 7;  /* +0x33a */
    unsigned short f33a_b7 : 1;
    unsigned short f33a_hi : 8;
    char pad2[0x42c - 0x33c];
    Pendeb1c pending;
} Stateeb1c;

extern unsigned int FUN_037c9084(unsigned int mask);
extern void FUN_037c904c(unsigned int mask);
extern void FUN_022d80f8(int arg);

void FUN_022deb1c(void) {
    Pendeb1c *pending = &(*(Stateeb1c **)0x0380fff4)->pending;
    unsigned int old = FUN_037c9084(0x1000000);
    if ((*(Stateeb1c **)0x0380fff4)->f33a_b7 == 0) {
        FUN_022d80f8(0);
    }
    *(volatile unsigned short *)0x048080b4 = 0xc0;
    pending->f50 = 0;
    pending->f64 = 0;
    FUN_037c904c(old);
}
