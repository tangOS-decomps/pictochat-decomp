// decomp: module=arm7 addr=0x022da490 name=FUN_022da490
// flags: -O4,s -noThumb

// Wipes the peer table hanging off +0x31c (count entries of 0x1c bytes) plus
// the 0x10-byte block at +0x52c, stamps every slot's id field at +0x1a back to
// 0xffff, re-arms the poll callback and drops the port-0 state back to 0x40.
//
// The ROM recomputes base + i*0x1c inside the wipe loop instead of walking a
// pointer, so strength reduction has to stay off here.

#pragma opt_strength_reduction off

typedef struct Peer {
    unsigned char pad00[0x1a];
    unsigned short id;          /* 0x1a */
} Peer;

extern unsigned char *G_0380fff4;

extern void func_037cb774(int value, void *dst, int size);
extern void FUN_022da5b4(int port, void *fn);
extern void FUN_022d9c60(int port, int state);

void FUN_022da490(void)
{
    Peer *tbl;
    unsigned short count;
    unsigned int i;

    count = *(unsigned short *)(G_0380fff4 + 0x322);
    tbl = *(Peer **)(G_0380fff4 + 0x31c);
    func_037cb774(0, tbl, count * sizeof(Peer));
    func_037cb774(0, G_0380fff4 + 0x52c, 0x10);

    tbl[0].id = 0xffff;
    for (i = 1; i < count; i++) {
        tbl[i].id = 0xffff;
    }

    FUN_022da5b4(0, (void *)0x023165dc);
    FUN_022d9c60(0, 0x40);
}
