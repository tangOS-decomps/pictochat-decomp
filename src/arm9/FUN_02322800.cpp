//cpp
// decomp: module=unk_autoload_0 addr=0x02322800 name=FUN_02322800
// verify: python tools/match.py --c src/arm9/FUN_02322800.cpp --func FUN_02322800 --addr 0x02322800 --size 0x20 --module unk_autoload_0 --version 2.0/sp1

// Posts command 0x14 with the port and channel packed into one halfword.

#pragma thumb on
extern "C" {
extern int FUN_02339250(int, int, int, int, int);
void FUN_02322800(int port, int chan, int c, int d)
{
    FUN_02339250(0x14, (unsigned short)((port << 8) | (unsigned char)chan), 0, c, d);
}
}
