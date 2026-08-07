// decomp: module=arm7 addr=0x022c63f0 name=FUN_022c63f0
// flags: -O4,s -noThumb

// Arms one timer node and links it into the global due-ordered list at
// 0x03805200.  For a periodic node (non-zero 64-bit interval at +0x1c) the
// caller's `when` is DISCARDED and replaced by the node's own start stamp,
// rolled forward by whole intervals if that stamp has already gone by - that
// roll-forward is the 64-bit divide plus the umull/mla widening multiply.
// Overwriting the parameter is what lets mwcc keep `when` and the p->start
// temp in the same r7:r6 pair.  The list walk inserts before the first node
// the new one is due ahead of, using the wrap-safe signed test on the 64-bit
// difference; if it lands at the head (or the list was empty) FUN_022c6300
// reprograms the hardware.

typedef struct TNode {
    char pad0[0xc];
    unsigned long long due;      /* +0x0c */
    struct TNode *prev;          /* +0x14 */
    struct TNode *next;          /* +0x18 */
    unsigned long long interval; /* +0x1c */
    unsigned long long start;    /* +0x24 */
} TNode;

typedef struct TList {
    char pad0[4];
    TNode *head;                 /* +0x04 */
    TNode *tail;                 /* +0x08 */
} TList;

extern unsigned long long FUN_022c625c(void);
extern void FUN_022c6300(TNode *n);

extern TList G_03805200;

void FUN_022c63f0(TNode *p, unsigned long long when)
{
    TNode *cur;
    TNode *last;

    if (p->interval != 0) {
        unsigned long long now = FUN_022c625c();
        when = p->start;
        if (when < now) {
            when = when + p->interval * ((now - when) / p->interval + 1);
        }
    }

    p->due = when;

    cur = G_03805200.head;
    while (cur != 0) {
        if ((long long)(when - cur->due) < 0) {
            p->prev = cur->prev;
            cur->prev = p;
            p->next = cur;
            if (p->prev != 0) {
                p->prev->next = p;
            } else {
                G_03805200.head = p;
                FUN_022c6300(p);
            }
            return;
        }
        cur = cur->next;
    }

    p->next = 0;
    last = G_03805200.tail;
    G_03805200.tail = p;
    p->prev = last;
    if (last != 0) {
        last->next = p;
    } else {
        G_03805200.tail = p;
        G_03805200.head = p;
        FUN_022c6300(p);
    }
}
