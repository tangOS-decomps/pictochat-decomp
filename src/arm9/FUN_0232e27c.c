// decomp: module=unk_autoload_0 addr=0x0232e27c name=FUN_0232e27c
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

struct Node *FUN_0232e27c(struct List *list, struct Node *node)
{
    struct Node *prev = node->prev;
    struct Node *next = node->next;

    if (prev != 0) {
        prev->next = next;
    } else {
        list->head = next;
    }

    if (next != 0) {
        next->prev = prev;
    } else {
        list->tail = prev;
    }

    return prev;
}
