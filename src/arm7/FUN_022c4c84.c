// decomp: module=arm7 addr=0x022c4c84 name=FUN_022c4c84
// flags: -O4,s -noThumb

// Priority-ordered insert into a doubly linked queue: walks from the head while
// the listed entry's key at +0x54 is not greater than the new entry's, bailing
// out if the entry is already linked, then splices before the stopping point
// (or onto the tail when the walk ran off the end).

typedef struct Entry {
    unsigned char pad00[0x54];
    unsigned int key;           /* 0x54 */
    unsigned char pad58[8];
    struct Entry *prev;         /* 0x60 */
    struct Entry *next;         /* 0x64 */
} Entry;

typedef struct Queue {
    Entry *head;
    Entry *tail;
} Queue;

void FUN_022c4c84(Queue *q, Entry *e)
{
    Entry *p;
    Entry *link;

    p = q->head;
    while (p != 0 && p->key <= e->key) {
        if (p == e) {
            return;
        }
        p = p->next;
    }

    if (p == 0) {
        link = q->tail;
        if (link == 0) {
            q->head = e;
        } else {
            link->next = e;
        }
        e->prev = link;
        e->next = 0;
        q->tail = e;
    } else {
        link = p->prev;
        if (link == 0) {
            q->head = e;
        } else {
            link->next = e;
        }
        e->prev = link;
        e->next = p;
        p->prev = e;
    }
}
