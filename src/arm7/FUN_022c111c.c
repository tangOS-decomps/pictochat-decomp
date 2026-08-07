// decomp: module=arm7 addr=0x022c111c name=FUN_022c111c
// flags: -O4,s -noThumb
// size: 0x9c - the nominal 0x94 excludes the two trailing pool words
// (0x0380fff4 and the 0xbf1d tag).

// Allocates a message block of `size` payload bytes plus the 0xc-byte header,
// using whichever allocator the ARM7 state block selects at +0x17c: 0 = the
// built-in pool allocator FUN_022c5c80 driven by the heap pair at +0x180/+0x184,
// 1 = an indirect allocator whose function pointer sits at +0x180. Any other
// selector leaves `blk` untouched - that is the ROM's own behaviour, the
// default arm branches straight to the null test with r4 never written.
//
// On success the block is stamped with the 0xbf1d signature at +0xa, its +0x8
// word is cleared, and FUN_022c12a4 links it to `owner`.

typedef struct Ctx {
    unsigned char pad[0x17c];
    int allocator;  /* +0x17c */
    void *heap;     /* +0x180 - also the function pointer for allocator 1 */
    void *heapEnd;  /* +0x184 */
} Ctx;

typedef struct Blk {
    unsigned char pad[8];
    unsigned short state; /* +0x8 */
    unsigned short tag;   /* +0xa */
} Blk;

extern Blk *FUN_022c5c80(void *heap, void *heapEnd, unsigned int size);
extern void FUN_022c12a4(int owner, Blk *blk, int flags);

Blk *FUN_022c111c(int owner, unsigned int size)
{
    Ctx *c = *(Ctx **)0x0380fff4;
    Blk *blk;

    if (size == 0) {
        return 0;
    }

    switch (c->allocator) {
    case 0:
        blk = FUN_022c5c80(c->heap, c->heapEnd, size + 0xc);
        break;
    case 1:
        blk = ((Blk *(*)(unsigned int))c->heap)(size + 0xc);
        break;
    }

    if (blk == 0) {
        return 0;
    }

    blk->tag = 0xbf1d;
    blk->state = 0;
    FUN_022c12a4(owner, blk, 0);
    return blk;
}
