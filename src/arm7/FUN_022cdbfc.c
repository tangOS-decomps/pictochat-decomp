// decomp: module=arm7 addr=0x022cdbfc name=FUN_022cdbfc

// Re-codes the 6-bit selector packed at bits 8..13 of the word at *p. Codes in
// the low banks are shifted up into the extended range (by 0x12 or 0x18) but
// only when the "extended" bit 14 is already set; codes that are already in the
// extended range just set that bit; anything unrecognised is cleared out.

#pragma thumb on

typedef struct Sel {
    unsigned int low : 8;
    unsigned int code : 6;
    unsigned int ext : 1;
    unsigned int high : 17;
} Sel;

void FUN_022cdbfc(Sel *p) {
    switch (p->code) {
    case 0x00: case 0x01: case 0x02: case 0x03:
    case 0x04: case 0x05: case 0x06: case 0x07:
    case 0x10: case 0x11:
        if (p->ext) p->code = p->code + 0x12;
        break;
    case 0x08: case 0x09:
        if (p->ext) p->code = p->code + 0x18;
        break;
    case 0x12: case 0x13: case 0x14: case 0x15:
    case 0x16: case 0x17: case 0x18: case 0x19:
    case 0x20: case 0x21: case 0x22: case 0x23:
        p->ext = 1;
        break;
    default:
        p->ext = 0;
        p->code = 0;
        break;
    }
}
