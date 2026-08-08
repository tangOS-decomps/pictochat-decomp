//cpp
// decomp: module=unk_autoload_0 addr=0x02327990 name=FUN_02327990
// verify: python tools/match.py --c src/arm9/FUN_02327990.cpp --func FUN_02327990 --addr 0x02327990 --size 0x14 --module unk_autoload_0 --version 2.0/sp1

// Measures with mode 2 off the halfword at G_023a060c+0xc, then biases the
// result by 0x37.

#pragma thumb on
extern "C" {
extern unsigned short G_023a060c[];
extern int FUN_023279a4(int, int);
int FUN_02327990(void) { return FUN_023279a4(G_023a060c[6], 2) + 0x37; }
}
