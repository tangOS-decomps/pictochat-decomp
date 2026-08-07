// decomp: module=arm7 addr=0x022ce57c name=FUN_022ce57c
// flags: -O4,s -noThumb

// Fills the 32-entry log ring buffer with a single value and rewinds its write
// index back to zero.

#pragma opt_strength_reduction off

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct ConnMgr2 {
    char pad[0x574];
    u32 f574;
} ConnMgr2;

extern u8 G_023180dc[];
extern ConnMgr2 G_023190dc;

void FUN_022ce57c(u8 v)
{
    int i;
    for (i = 0; i < 0x20; i++) {
        G_023180dc[0x1554 + i] = v;
    }
    G_023190dc.f574 = 0;
}
