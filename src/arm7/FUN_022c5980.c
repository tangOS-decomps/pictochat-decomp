// decomp: module=arm7 addr=0x022c5980 name=FUN_022c5980
// flags: -noThumb

struct Node {
    char pad[0x10];
    struct Node *next;
    struct Node *prev;
};

struct List {
    char pad[0x6c];
    struct Node *head;
    struct Node *tail;
};

void FUN_022c5980(struct List *list, struct Node *node)
{
    struct Node *tail = list->tail;

    if (tail == 0) {
        list->head = node;
    } else {
        tail->next = node;
    }
    node->prev = tail;
    node->next = 0;
    list->tail = node;
}
