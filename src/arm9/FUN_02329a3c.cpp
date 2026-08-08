//cpp
// decomp: module=unk_autoload_0 addr=0x02329a3c name=FUN_02329a3c
// verify: python tools/match.py --c src/arm9/FUN_02329a3c.cpp --func FUN_02329a3c --addr 0x02329a3c --size 0x20 --module unk_autoload_0 --version 2.0/sp1

// Snapshots the eight bytes at +0x70 and hands back byte 5 of the copy.

#pragma thumb on
extern "C" {
extern void FUN_02337584(void *, void *, int);
int FUN_02329a3c(char *p)
{
    unsigned char tmp[8];

    if (p != 0) {
        FUN_02337584(p + 0x70, tmp, 8);
        return tmp[5];
    }
    return 0;
}
}
