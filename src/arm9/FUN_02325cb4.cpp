//cpp
// decomp: module=unk_autoload_0 addr=0x02325cb4 name=FUN_02325cb4
// verify: python tools/match.py --c src/arm9/FUN_02325cb4.cpp --func FUN_02325cb4 --addr 0x02325cb4 --size 0x2c --module unk_autoload_0 --version 2.0/sp1

// Returns the last item of the currently-selected 0x104-byte page, or 0 when
// the page is empty.

#pragma thumb on
extern "C" {
unsigned short FUN_02325cb4(char *p)
{
    unsigned short n = *(unsigned short *)(p + 0x56a);
    char *e = p + n * 0x104;
    unsigned short c = *(unsigned short *)(e + 0x156);

    if (c == 0) return 0;
    return *(unsigned short *)(e + 0x56 + (c - 1) * 2);
}
}
