// decomp: module=arm7 addr=0x022d540c name=FUN_022d540c
// flags: -O4,s -noThumb

// Allocates a send descriptor off the free list at +0x6f8, fills it in from the
// caller's parameters and appends it to the per-index queue at +0x70c, all
// inside the +0x71c lock. Returns 6 for a bad length, 0xa when the free list is
// empty and 2 once the entry is queued.

typedef struct Entry {
    unsigned short next;        /* 0x00 */
    unsigned short f02;         /* 0x02 */
    unsigned short f04;         /* 0x04 */
    unsigned short f06;         /* 0x06 */
    unsigned short f08;         /* 0x08 */
    unsigned short f0a;         /* 0x0a */
    unsigned short f0c;         /* 0x0c */
    unsigned short len;         /* 0x0e */
    unsigned short f10;         /* 0x10 */
    unsigned short f12;         /* 0x12 */
    int f14;                    /* 0x14 */
    int f18;                    /* 0x18 */
    int f1c;                    /* 0x1c */
} Entry;                        /* 0x20 */

typedef struct Queue {
    unsigned short head;
    unsigned short tail;
} Queue;

typedef struct Root {
    unsigned char pad000[0x550];
    unsigned char *block;       /* 0x550 */
} Root;

extern Root G_023190dc;

extern void FUN_037ca044(void *lock);
extern void FUN_037ca0c8(void *lock);

int FUN_022d540c(unsigned short mask, int index, unsigned short flags,
                 unsigned short port, int a4, unsigned short len,
                 int a6, int a7)
{
    Entry *entries;
    Queue *q;
    Entry *e;
    unsigned short slot;
    unsigned char *base;

    base = G_023190dc.block;
    q = (Queue *)(base + 0x70c) + index;
    entries = (Entry *)(base + 0x2f8);

    if (len == 0) {
        return 6;
    }
    if ((int)len + ((flags & 8) ? 2 : 0) > 0x204) {
        return 6;
    }

    FUN_037ca044(base + 0x71c);
    slot = *(unsigned short *)(base + 0x6f8);
    if (slot == 0xffff) {
        FUN_037ca0c8(base + 0x71c);
        return 0xa;
    }

    e = &entries[slot];
    *(unsigned short *)(base + 0x6f8) = entries[slot].next;
    if (*(unsigned short *)(base + 0x6fa) == slot) {
        *(unsigned short *)(base + 0x6fa) = 0xffff;
    }

    e->f02 = flags;
    e->f04 = port;
    e->f06 = port & mask;
    e->f08 = 0;
    e->f0a = 0;
    e->f14 = a4;
    e->len = len;
    e->f18 = a6;
    e->f1c = a7;
    e->next = 0xffff;
    e->f10 = 0xffff;
    e->f12 = *(unsigned short *)(base + 0x7ca);

    if (q->tail == 0xffff) {
        q->head = slot;
    } else {
        entries[q->tail].next = slot;
    }
    q->tail = slot;

    FUN_037ca0c8(base + 0x71c);
    return 2;
}
