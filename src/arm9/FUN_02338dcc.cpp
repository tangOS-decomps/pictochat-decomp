//cpp
// decomp: module=unk_autoload_0 addr=0x02338dcc name=FUN_02338dcc
// verify: python tools/match.py --c src/arm9/FUN_02338dcc.cpp --func FUN_02338dcc --addr 0x02338dcc --size 0x2c --module unk_autoload_0 --version 2.0/sp1

// Copies the four cached halfwords out, unless the busy bit says they are
// mid-update.

#pragma thumb on
extern "C" {
typedef struct St {
    char pad[8];
    unsigned short v[4];
    char pad2[0x28];
    unsigned short flags;
} St;
extern void FUN_02339024(int);
extern St G_023c3528;
int FUN_02338dcc(unsigned short *out)
{
    FUN_02339024(1);
    if ((G_023c3528.flags & 1) != 0) return 1;
    out[0] = G_023c3528.v[0];
    out[1] = G_023c3528.v[1];
    out[2] = G_023c3528.v[2];
    out[3] = G_023c3528.v[3];
    return 0;
}
}
