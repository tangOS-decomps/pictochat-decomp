// decomp: module=arm7 addr=0x022d6ef8 name=FUN_022d6ef8
// flags: -O4,s -noThumb

// Publishes an 8-bit level both into the shadow halfword at +0x32a of the ARM7
// state block (0x0380fff4) and into the hardware register at 0x0480802c.
// Rejects anything wider than 8 bits with error 5.
//
// The parameter has to be typed `unsigned short`: with a wider type the two
// stores share one implicit u16 conversion, which mwcc CSEs into a materialised
// `lsl #16 / lsr #16` pair the ROM does not have.

int FUN_022d6ef8(unsigned short level)
{
    if (level > 0xff) return 5;
    *(unsigned short *)(*(char **)0x0380fff4 + 0x32a) = level;
    *(unsigned short *)0x0480802c = level;
    return 0;
}
