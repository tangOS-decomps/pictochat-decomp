//cpp
// decomp: module=unk_autoload_0 addr=0x02328d80 name=FUN_02328d80

// Writes a 6-bit field into sub BG2CNT (0x0400104a) and optionally sets bit 13.
//
// The ROM never materialises 0x2000: it reuses the pool word holding the register
// address and shifts it right by 13, which happens to produce exactly 0x2000.
// That is the compiler's own constant reuse, so the C just says `| 0x2000`.

#pragma thumb on
extern "C" {
void FUN_02328d80(int a, int b)
{
    unsigned short *p = (unsigned short *)0x0400104a;
    int v = (~0x3f00 & *p) | (a << 8);
    if (b != 0) v |= 0x2000;
    *p = (unsigned short)v;
}
}
