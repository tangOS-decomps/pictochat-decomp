// decomp: module=arm7 addr=0x022c5c80 name=FUN_022c5c80
// flags: -O4,s -noThumb
//
// Allocator: rounds the request up to a 0x20-aligned size plus a 0x20 header,
// walks the arena's free list for the first block that fits, and either unlinks
// the block whole (when the leftover is under 0x40) or splits it in place. The
// block is then pushed onto the in-use list and its payload address returned.
// Interrupts stay masked across the whole search via the FUN_022c6d40 /
// FUN_022c6d54 pair, whose state rides in r0 on the arena-missing path.
//
// The link layout matches the already-matched src/arm7/FUN_022c5bb0.c helper,
// which is handed the free-list head and the block to unlink.

typedef struct Blk {
    struct Blk *f00;
    struct Blk *f04;
    int size;
} Blk;

typedef struct List {
    int f00;
    Blk *free;
    Blk *used;
} List;

typedef struct Heap {
    int def;
    char pad04[0x10 - 4];
    List *lists;
} Heap;

extern Heap *G_03805168[];
extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);
extern Blk *FUN_022c5bb0(Blk *head, Blk *link);

void *FUN_022c5c80(int arena, int which, int size)
{
    Heap *h;
    List *l;
    Blk *b;
    Blk *q;
    Blk *u;
    unsigned int rem;
    int state;

    state = FUN_022c6d40();
    h = G_03805168[arena];

    if (h == 0) {
        FUN_022c6d54(state);
        return 0;
    }

    if (which < 0)
        which = h->def;

    l = &h->lists[which];
    b = l->free;
    size = (size + 0x3f) & ~0x1f;

    while (b != 0) {
        if (size <= b->size)
            break;
        b = b->f04;
    }

    if (b == 0) {
        FUN_022c6d54(state);
        return 0;
    }

    rem = b->size - size;
    if (rem < 0x40) {
        l->free = FUN_022c5bb0(l->free, b);
    } else {
        b->size = size;
        q = (Blk *)((char *)b + size);
        q->size = rem;
        q->f00 = b->f00;
        u = b->f04;
        q->f04 = u;
        if (u != 0)
            u->f00 = q;
        if (q->f00 != 0)
            q->f00->f04 = q;
        else
            l->free = q;
    }

    u = l->used;
    b->f00 = 0;
    b->f04 = u;
    if (u != 0)
        u->f00 = b;
    l->used = b;
    FUN_022c6d54(state);
    return (char *)b + 0x20;
}
