// decomp: module=arm7 addr=0x022c67e8 name=FUN_022c67e8
// flags: -O4,s -noThumb

// Sorted insert into the alarm list at 0x0380520c (head +0xc, tail +0x10,
// node prev +0x14 / next +0x18).  The sort key is the unsigned tick count at
// +0xc, tie-broken by the signed scanline at +0x10.  Whenever the node lands
// at the head the hardware compare line is reprogrammed via FUN_022c69f8.
// NOTE: verify with --size 0xa4, not funcs.json's 0xa0 - the stated size
// excludes this function's own trailing pool word.

extern void FUN_022c69f8(void *node);

typedef struct Alarm {
    char pad[0xc];
    unsigned int tick; /* +0x0c */
    short line;        /* +0x10 */
    short pad12;       /* +0x12 */
    struct Alarm *prev;
    struct Alarm *next;
} Alarm;

typedef struct AlarmList {
    char pad[0xc];
    Alarm *head;
    Alarm *tail;
} AlarmList;

extern AlarmList G_0380520c;

void FUN_022c67e8(Alarm *n)
{
    Alarm *p;
    Alarm *prev;

    for (p = G_0380520c.head; p != 0; p = p->next) {
        if (p->tick < n->tick) {
            continue;
        }
        if (p->tick == n->tick && p->line <= n->line) {
            continue;
        }

        prev = p->prev;
        n->prev = prev;
        n->next = p;
        p->prev = n;
        if (prev != 0) {
            prev->next = n;
        } else {
            G_0380520c.head = n;
            FUN_022c69f8(n);
        }
        return;
    }

    prev = G_0380520c.tail;
    n->prev = prev;
    n->next = 0;
    G_0380520c.tail = n;
    if (prev != 0) {
        prev->next = n;
    } else {
        G_0380520c.head = n;
        FUN_022c69f8(n);
    }
}
