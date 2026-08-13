//cpp
// decomp: module=unk_autoload_0 addr=0x02329570 name=FUN_02329570
// verify: python tools/match.py --c src/arm9/FUN_02329570.cpp --func FUN_02329570 --addr 0x02329570 --size 0x3c --module unk_autoload_0 --version 2.0/sp1

// The take side of FUN_023295ac's round-robin slab pool: hands out the slab at
// the cursor and advances it, or returns null when the credit at +2 is spent.

#pragma thumb on
extern "C" {
extern unsigned char G_023bd5c0[];
extern char G_023a5500[];

void *FUN_02329570(void)
{
    unsigned char left = G_023bd5c0[2];
    unsigned char i = G_023bd5c0[0];

    if (left != 0) {
        G_023bd5c0[2] = left - 1;
        G_023bd5c0[0]++;
        G_023bd5c0[0] = (unsigned char)(G_023bd5c0[0] % 6);
        return G_023a5500 + 0x4020 * i;
    }
    return 0;
}
}
