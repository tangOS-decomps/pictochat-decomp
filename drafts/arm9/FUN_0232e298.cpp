// decomp: module=unk_autoload_0 addr=0x0232e298 name=FUN_0232e298
// Doubly-linked list insertion: links `node` into `list` immediately after
// `after`, or at the head of the list if `after` is NULL. Returns `node`.
struct Node {
    void *pad0;
    void *pad4;
    struct Node *prev;
    struct Node *next;
};
struct List {
    struct Node *head;
    struct Node *tail;
};

struct Node *FUN_0232e298(struct List *list, struct Node *node, struct Node *after)
{
    struct Node *next;
    node->prev = after;
    if (after != 0) {
        next = after->next;
        after->next = node;
    } else {
        next = list->head;
        list->head = node;
    }
    node->next = next;
    if (next != 0) {
        next->prev = node;
    } else {
        list->tail = node;
    }
    return node;
}
