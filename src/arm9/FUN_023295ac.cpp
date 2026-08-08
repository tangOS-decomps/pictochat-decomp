//cpp
// decomp: module=unk_autoload_0 addr=0x023295ac name=FUN_023295ac
// verify: python tools/match.py --c src/arm9/FUN_023295ac.cpp --func FUN_023295ac --addr 0x023295ac --size 0x38 --module unk_autoload_0 --version 2.0/sp1

// Hands out the next 0x4020-byte slab, advancing the round-robin cursor only
// while fewer than six are out.

#pragma thumb on
extern "C" {
extern unsigned char G_023bd5c0[];
extern char G_023a5500[];
void *FUN_023295ac(void)
{
    unsigned char i = G_023bd5c0[1];

    if (G_023bd5c0[3] < 6) {
        G_023bd5c0[3]++;
        G_023bd5c0[1]++;
        G_023bd5c0[1] = (unsigned char)(G_023bd5c0[1] % 6);
    }
    return G_023a5500 + 0x4020 * i;
}
}
