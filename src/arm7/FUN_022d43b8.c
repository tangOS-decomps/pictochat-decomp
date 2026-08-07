// decomp: module=arm7 addr=0x022d43b8 name=FUN_022d43b8
// flags: -O4,s -noThumb

// Resets the 32-entry TX descriptor pool: clears the whole 0x400-byte table,
// rebuilds the free list (entry i -> i+1, last -> 0xffff), points head/tail at
// 0/0x1f and invalidates the eight per-queue head/tail pairs.  Held under the
// pool's own critical section (FUN_037ca044 / FUN_037ca0c8).

extern void FUN_037ca044(void *cs);
extern void FUN_037ca0c8(void *cs);
extern void MIi_CpuClear16(unsigned short data, void *dest, unsigned int size);

typedef struct TxEntry {
    unsigned short next;   /* 0x00 */
    char pad[0x1e];
} TxEntry;

typedef struct TxQueue {
    unsigned short head;
    unsigned short tail;
} TxQueue;

typedef struct TxPool {
    char pad0[0x2f8];
    TxEntry entries[0x20]; /* 0x2f8 */
    unsigned short free;   /* 0x6f8 */
    unsigned short last;   /* 0x6fa */
    TxQueue q[4];          /* 0x6fc */
    TxQueue r[4];          /* 0x70c */
    int cs;                /* 0x71c */
} TxPool;

// The ROM keeps 0x023190dc whole in the pool word and reaches the pool pointer
// with a +0x550 displacement, so the base has to be a real extern object.
extern TxPool *G_023190dc[];

void FUN_022d43b8(void)
{
    TxPool *p = G_023190dc[0x154];
    unsigned short i;
    unsigned short j;

    FUN_037ca044(&p->cs);
    MIi_CpuClear16(0, p->entries, 0x400);

    i = 0;
    do {
        unsigned short n = i + 1;
        p->entries[i].next = n;
        i = n;
    } while (i < 0x1f);

    p->entries[i].next = 0xffff;
    p->free = 0;
    p->last = i;

    j = 0;
    do {
        p->r[j].head = 0xffff;
        p->r[j].tail = 0xffff;
        p->q[j].head = 0xffff;
        p->q[j].tail = 0xffff;
        j = j + 1;
    } while (j < 4);

    FUN_037ca0c8(&p->cs);
}
