// decomp: module=arm7 addr=0x022cfb24 name=FUN_022cfb24
// flags: -O4,s -noThumb
// size: 0x80 - the stated 0x7c excludes the trailing pool word (0x023180dc).

// Sibling of FUN_022d40d8 without the busy-flag guard: allocates a packet
// slot, stamps opcode 0x2b plus the caller's word and enqueues it on the
// 0x88 queue; if the allocation or the enqueue fails and a connection is
// live, an error indication {0x80, 8, 0x16, 0x2b} is pushed instead.
// 0x023180dc + 0x154c is G_023190dc.f54c reached off the shared base, same
// as in the sibling.

extern unsigned char G_023180dc[];

extern void *FUN_022ce718(void);
extern int func_037c9e90(void *q, void *pkt, int block);
extern void *func_037d14bc(void);
extern void func_037d1464(void *ind);

void FUN_022cfb24(unsigned int a)
{
    unsigned char *base;
    int *pkt;
    int r;

    pkt = (int *)FUN_022ce718();
    base = G_023180dc;
    if (pkt != 0) {
        pkt[0] = 0x2b;
        pkt[1] = a;
        r = func_037c9e90(base + 0x88, pkt, 0);
    } else {
        r = 0;
    }

    if (r == 0) {
        if (*(int *)(base + 0x1000 + 0x54c) != 0) {
            unsigned short *ind = (unsigned short *)func_037d14bc();
            ind[0] = 0x80;
            ind[1] = 8;
            ind[2] = 0x16;
            ind[3] = 0x2b;
            func_037d1464(ind);
        }
    }
}
