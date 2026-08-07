// decomp: module=arm7 addr=0x022c6600 name=FUN_022c6600
// flags: -O4,s -noThumb
// NOTE: verify with --size 0x88, not the nominal 0x84 - the stated size
// excludes this function's own trailing 1-word literal pool.

// Unlinks a wifi work item from the global doubly-linked queue at 0x03805200
// under an interrupt-disabled critical section, then clears its in-queue
// marker (+0x00) and its two result words (+0x1c, +0x20).
//
// A cleared +0x00 means the item is not queued; that path just re-enables
// interrupts and leaves.  When the unlinked item was the queue head and a
// successor exists, the new head is handed to FUN_022c6300 to be started.
//
// FUN_022c6300 taking the new head as its argument (inferred from register
// liveness at the bl) is what pins `next` to r0; spelled void() every register
// in the body shifts by one against the ROM.  Its declaration elsewhere in
// src/ (src/arm7/FUN_022c1ae0.c-style void externs) does not cover this callee.

typedef struct Item {
    int queued;             /* +0x00 */
    unsigned char pad[0x10];
    struct Item *prev;      /* +0x14 */
    struct Item *next;      /* +0x18 */
    int result0;            /* +0x1c */
    int result1;            /* +0x20 */
} Item;

typedef struct Queue {
    int unused;             /* 0x03805200 */
    Item *head;             /* 0x03805204 */
    Item *tail;             /* 0x03805208 */
} Queue;

extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);
extern void FUN_022c6300(Item *item);

void FUN_022c6600(Item *item)
{
    Queue *q = (Queue *)0x03805200;
    int state = FUN_022c6d40();

    if (item->queued == 0) {
        FUN_022c6d54(state);
    } else {
        Item *next = item->next;

        if (next == 0) {
            q->tail = item->prev;
        } else {
            next->prev = item->prev;
        }

        if (item->prev != 0) {
            item->prev->next = next;
        } else {
            q->head = next;
            if (next != 0) {
                FUN_022c6300(next);
            }
        }

        item->queued = 0;
        item->result0 = 0;
        item->result1 = 0;
        FUN_022c6d54(state);
    }
}
