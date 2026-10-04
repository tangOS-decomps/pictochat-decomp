// decomp: module=arm7 addr=0x022c105c name=FUN_022c105c
// flags: -O4,s -noThumb
// size: 0xc0 - the nominal 0xbc excludes the trailing pool word (0xbf1d tag).
//
// Unlinks a message block from its owner's doubly-linked list. Blocks without
// the 0xbf1d signature are refused with 1, blocks owned by another list (+0x8
// vs the list id at +0xa) with 2. Under the FUN_022c48a4/FUN_022c486c mask
// critical section the list count is decremented and the block is spliced
// out (head/tail sentinels are -1), then its owner field is cleared; returns 0.

typedef struct Blk {
    struct Blk *prev;      /* +0x0 */
    struct Blk *next;      /* +0x4 */
    unsigned short state;  /* +0x8 */
    unsigned short tag;    /* +0xa */
} Blk;

typedef struct List {
    Blk *head;             /* +0x0 */
    Blk *tail;             /* +0x4 */
    unsigned short count;  /* +0x8 */
    unsigned short id;     /* +0xa */
} List;

extern int FUN_022c48a4(unsigned int mask);
extern void FUN_022c486c(int token);

int FUN_022c105c(List *list, Blk *blk)
{
    int token;

    if (blk->tag != 0xbf1d) {
        return 1;
    }
    if (blk->state != list->id) {
        return 2;
    }

    token = FUN_022c48a4(0x01000000);
    list->count--;
    if (list->count == 0) {
        list->head = (Blk *)-1;
        list->tail = (Blk *)-1;
    } else if (blk == list->head) {
        Blk *n = blk->next;
        list->head = n;
        n->prev = (Blk *)-1;
    } else if (blk == list->tail) {
        Blk *p = blk->prev;
        list->tail = p;
        p->next = (Blk *)-1;
    } else {
        blk->next->prev = blk->prev;
        blk->prev->next = blk->next;
    }
    blk->state = 0;
    FUN_022c486c(token);
    return 0;
}
