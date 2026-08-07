// decomp: module=arm7 addr=0x022c0e48 name=FUN_022c0e48
// flags: -O4,s -noThumb

// Appends slot `id` to the singly-linked pending list for class `cls` inside
// the global block at *0x0380fff4, under the FUN_022c48a4/FUN_022c486c mask
// critical section (the mask token rides in r0 across the whole body, which is
// why FUN_022c48a4 has to be declared as returning it and FUN_022c486c as
// taking it).  Already-linked slots (marker != 0) are skipped.  Finally, if
// this was not class 3 and the block's class-3 flag is set, an empty message
// is posted to the queue at +0x308 - and that read of the global is a fresh
// one, distinct from the cached pointer, so it reloads the pool word.
// The global has to be spelled as a literal-address dereference rather than an
// `extern PendBlock *`; the extern colours `b`/`slots` as r5/r4 instead of the
// ROM's r4/r5 and nothing else shifts it back.

typedef struct Slot {
    unsigned short next;
    unsigned short linked;
    unsigned short pad[2];
} Slot;

typedef struct PendBlock {
    unsigned short head[4];
    unsigned short tail[4];
    unsigned short lowest;
    unsigned short f12;
    char pad0[0xbc - 0x14];
    Slot slots[0x49];
    char pad1[0x308 - 0xbc - 0x49 * 8];
    void *queue;
} PendBlock;

extern int FUN_022c48a4(unsigned int mask);
extern void FUN_022c486c(int token);
extern int FUN_022c56b0(void *q, void *msg, int flags);

#define G_0380fff4 (*(PendBlock **)0x0380fff4)

void FUN_022c0e48(int cls, int id)
{
    PendBlock *b = G_0380fff4;
    Slot *slots = b->slots;
    int token = FUN_022c48a4(0x01000010);

    if (slots[id].linked == 0) {
        unsigned short prev;

        slots[id].linked = 1;
        slots[id].next = 0xffff;

        prev = b->tail[cls];
        if (prev == 0xffff) {
            b->head[cls] = id;
        } else {
            b->slots[prev].next = id;
        }
        b->tail[cls] = id;

        if (cls < b->lowest) {
            b->lowest = cls;
        }
    }

    FUN_022c486c(token);

    if (cls != 3 && b->f12 == 3) {
        FUN_022c56b0(G_0380fff4->queue, 0, 0);
    }
}
