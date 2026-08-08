//cpp
// decomp: module=unk_autoload_0 addr=0x02336404 name=FUN_02336404
// verify: python tools/match.py --c src/arm9/FUN_02336404.cpp --func FUN_02336404 --addr 0x02336404 --size 0x22 --module unk_autoload_0 --version 2.0/sp1

// Encodes a signed magnitude into the halfword: bit 14 marks positive, bit 15
// negative, zero writes a bare zero.

#pragma thumb on
extern "C" {
void FUN_02336404(unsigned short *p, int v)
{
    if (v == 0) {
        *p = 0;
        return;
    }
    if (v > 0) {
        *p = (unsigned short)(v | 0x4000);
        return;
    }
    *p = (unsigned short)(-v | 0x8000);
}
}
