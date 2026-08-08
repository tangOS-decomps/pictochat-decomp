//cpp
// decomp: module=unk_autoload_0 addr=0x02325c2c name=FUN_02325c2c
// verify: python tools/match.py --c src/arm9/FUN_02325c2c.cpp --func FUN_02325c2c --addr 0x02325c2c --size 0x1e --module unk_autoload_0 --version 2.0/sp1

// True when the whole len-byte block reads back as zero words.

#pragma thumb on
extern "C" {
int FUN_02325c2c(int *p, int len)
{
    len = (len + 3) >> 2;

    goto test;
body:
    if (*p != 0) return 0;
    p++;
test:
    if (len-- != 0) goto body;
    return 1;
}
}
