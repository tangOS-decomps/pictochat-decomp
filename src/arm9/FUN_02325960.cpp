//cpp
// decomp: module=unk_autoload_0 addr=0x02325960 name=FUN_02325960
// verify: python tools/match.py --c src/arm9/FUN_02325960.cpp --func FUN_02325960 --addr 0x02325960 --size 0x2c --module unk_autoload_0 --version 2.0/sp1
// flags: -O4,s

// Reserves one more page, refusing once four are out or the combined extent
// would pass 0x3d.

#pragma thumb on
extern "C" {
int FUN_02325960(char *p)
{
    unsigned short n = *(unsigned short *)(p + 0x56a);
    unsigned short m;

    if (n == 4) return 0;
    m = *(unsigned short *)(p + 0x56c);
    if (m + n * 16 > 0x3d) return 0;
    *(unsigned short *)(p + 0x56a) = (unsigned short)(n + 1);
    return 1;
}
}
