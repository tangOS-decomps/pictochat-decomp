//cpp
// decomp: module=unk_autoload_0 addr=0x02336428 name=FUN_02336428

// Packs five fields into one 32-bit control word: bit 6 always set, `a` in the
// low byte, `b` at bit 8, and `c`/`d` packed into the high halfword.

#pragma thumb on
extern "C" {
void FUN_02336428(unsigned int *p, unsigned int a, unsigned int b,
                  unsigned int c, unsigned int d)
{
    *p = (0x40 | a) | (b << 8) | ((d << 8 | c) << 16);
}
}
