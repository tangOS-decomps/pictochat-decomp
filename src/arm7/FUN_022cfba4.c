// decomp: module=arm7 addr=0x022cfba4 name=FUN_022cfba4
// flags: -O4,s -noThumb
// size: 0x98 - the stated 0x88 excludes the four trailing pool words.

// Allocates a 0x40-byte type-0x185 packet from the pool named by the manager
// words at +0x544/+0x548 and enqueues it on the 0x02318104 queue; when the
// enqueue reports 0 the packet is recycled through FUN_022cfa44 and, if a
// connection is live, an error indication {0x80, 8, 0x16, 0x80} is pushed.

typedef struct Mgrfba4 {
    char pad[0x544];
    void *f544;
    void *f548;
} Mgrfba4;

extern Mgrfba4 G_023190dc;
extern unsigned char G_023180dc[];
extern unsigned char G_02318104[];

extern unsigned short *FUN_037ca460(void *a, void *b, int size);
extern int func_037c9e90(void *q, void *pkt, int block);
extern void FUN_022cfa44(void *pkt);
extern void *func_037d14bc(void);
extern void func_037d1464(void *ind);

void FUN_022cfba4(void)
{
    unsigned char *base = G_023180dc;
    unsigned short *pkt;

    pkt = FUN_037ca460(G_023190dc.f544, G_023190dc.f548, 0x40);
    pkt[6] = 0x185;
    pkt[7] = 0;
    if (func_037c9e90(G_02318104, pkt, 0) == 0) {
        FUN_022cfa44(pkt);
        if (*(int *)(base + 0x1000 + 0x54c) != 0) {
            unsigned short *ind = (unsigned short *)func_037d14bc();
            ind[0] = 0x80;
            ind[1] = 8;
            ind[2] = 0x16;
            ind[3] = 0x80;
            func_037d1464(ind);
        }
    }
}
