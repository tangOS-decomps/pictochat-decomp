//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x0232e13c name=FUN_0232e13c
// Intrusive doubly-linked list unlink: removes `obj` from `list`. Unlike
// FUN_0232e298/FUN_0233142c's lists (which embed next/prev directly in the
// node struct), this one's link fields live at a per-list byte offset
// (`list->off`) within each linked object - a classic embedded-list_head
// pattern, with prev/next storing pointers to the *owning* object rather
// than to the link struct itself.
typedef struct {
    int head;
    int tail;
    unsigned short count;
    unsigned short off;
} List;

typedef struct { int prev; int next; } Link;

void FUN_0232e13c(List *list, void *obj)
{
    unsigned short off = list->off;
    Link *link = (Link *)((char *)obj + off);
    void *prev = (void *)(long)link->prev;
    if (prev == 0) {
        list->head = link->next;
    } else {
        Link *prevLink = (Link *)((char *)prev + off);
        prevLink->next = link->next;
    }
    void *next = (void *)(long)link->next;
    if (next == 0) {
        list->tail = link->prev;
    } else {
        unsigned short off2 = list->off;
        Link *nextLink = (Link *)((char *)next + off2);
        nextLink->prev = link->prev;
    }
    link->prev = 0;
    link->next = 0;
    list->count--;
}

}
