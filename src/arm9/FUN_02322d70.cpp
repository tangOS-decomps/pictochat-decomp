//cpp
// decomp: module=unk_autoload_0 addr=0x02322d70 name=FUN_02322d70
// verify: python tools/match.py --c src/arm9/FUN_02322d70.cpp --func FUN_02322d70 --addr 0x02322d70 --size 0x18 --module unk_autoload_0 --version 2.0/sp1

// Rearms the descriptor at G_0238ede0: clears the two counters and stores the
// caller's offset advanced by 8 and wrapped to the low nibble.

#pragma thumb on
extern "C" {
extern int G_0238ede0[];
void FUN_02322d70(int a)
{
    G_0238ede0[1] = 0;
    G_0238ede0[3] = (a + 8) & 0xf;
    G_0238ede0[2] = 0;
}
}
