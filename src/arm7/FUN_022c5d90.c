// decomp: module=arm7 addr=0x022c5d90 name=FUN_022c5d90
// flags: -O4,s -noThumb
// size: 0x6c - the stated 0x68 excludes the trailing pool word (0x03805168).

// Returns a freed block (already shrunk by the 0x20-byte header) to heap
// `idx`'s arena `i` under the interrupt lock: unlinks it from the allocated
// list at +8 (FUN_022c5bb0) and coalesces it into the address-ordered free
// list at +4 (FUN_022c5bd8). A negative arena index means the heap's current
// arena.

typedef struct Arena5d90 {
    int f0;
    void *free;  /* +0x4 */
    void *used;  /* +0x8 */
} Arena5d90;

typedef struct Heap5d90 {
    int cur;             /* +0x00 */
    char pad[0x10 - 4];
    Arena5d90 *arenas;   /* +0x10 */
} Heap5d90;

extern Heap5d90 *G_03805168[];

extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);
extern void *FUN_022c5bb0(void *head, void *blk);
extern void *FUN_022c5bd8(void *head, void *blk);

void FUN_022c5d90(int idx, int i, char *blk)
{
    Heap5d90 *h;
    Arena5d90 *a;
    char *p;
    int state;

    state = FUN_022c6d40();
    h = G_03805168[idx];
    if (i < 0) {
        i = h->cur;
    }
    a = &h->arenas[i];
    p = blk - 0x20;
    a->used = FUN_022c5bb0(a->used, p);
    a->free = FUN_022c5bd8(a->free, p);
    FUN_022c6d54(state);
}
