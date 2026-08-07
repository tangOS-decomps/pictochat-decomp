// decomp: module=arm7 addr=0x022c5bd8 name=FUN_022c5bd8
// flags: -O4,s -noThumb

// Free-list insert with coalescing. Walks the address-ordered list to find the
// first block at or above `blk`, links `blk` in, then merges forward into the
// successor and backward into the predecessor when they are adjacent. Returns
// the (possibly new) list head.

typedef struct Blk {
    struct Blk *prev;   /* +0x00 */
    struct Blk *next;   /* +0x04 */
    unsigned int size;  /* +0x08 */
} Blk;

Blk *FUN_022c5bd8(Blk *head, Blk *blk)
{
    Blk *prev = 0;
    Blk *cur = head;

    while (cur != 0) {
        if (blk <= cur) {
            break;
        }
        prev = cur;
        cur = cur->next;
    }

    blk->prev = prev;
    blk->next = cur;

    if (cur != 0) {
        cur->prev = blk;
        if ((Blk *)((char *)blk + blk->size) == cur) {
            blk->size += cur->size;
            cur = cur->next;
            blk->next = cur;
            if (cur != 0) {
                cur->prev = blk;
            }
        }
    }

    if (prev != 0) {
        prev->next = blk;
        if ((Blk *)((char *)prev + prev->size) == blk) {
            prev->size += blk->size;
            prev->next = cur;
            if (cur != 0) {
                cur->prev = prev;
            }
        }
    } else {
        head = blk;
    }

    return head;
}
