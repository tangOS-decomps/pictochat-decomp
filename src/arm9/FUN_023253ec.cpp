//cpp
// decomp: module=unk_autoload_0 addr=0x023253ec name=FUN_023253ec
// verify: python tools/match.py --c src/arm9/FUN_023253ec.cpp --func FUN_023253ec --addr 0x023253ec --size 0x1c --module unk_autoload_0 --version 2.0/sp1

// Folds the byte at +0x571 down to one of thirteen buckets, offset by 3.

#pragma thumb on
extern "C" {
int FUN_023253ec(unsigned char *p)
{
    return (p[0x571] / 6) % 13 + 3;
}
}
