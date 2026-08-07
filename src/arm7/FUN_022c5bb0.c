// decomp: module=arm7 addr=0x022c5bb0 name=FUN_022c5bb0
// flags: -noThumb

typedef struct Link {
    struct Link *next;
    struct Link *prev;
} Link;

Link *FUN_022c5bb0(Link *head, Link *link)
{
    if (link->prev != 0) {
        link->prev->next = link->next;
    }

    if (link->next == 0) {
        head = link->prev;
    } else {
        link->next->prev = link->prev;
    }

    return head;
}
