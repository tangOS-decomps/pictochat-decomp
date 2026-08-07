// decomp: module=unk_autoload_0 addr=0x02330bcc name=FUN_02330bcc
struct Node {
    char pad[0x10];
    struct Node *next;
    struct Node *prev;
};

struct List {
    struct Node *head;
    struct Node *tail;
};

struct Node *FUN_02330bcc(struct List *list)
{
    struct Node *node = list->head;
    if (node != 0) {
        struct Node *next = node->next;
        list->head = next;
        if (next != 0) {
            next->prev = 0;
        } else {
            list->tail = 0;
        }
    }
    return node;
}
