// decomp: module=unk_autoload_0 addr=0x02330b68 name=FUN_02330b68
// Pop-from-head: removes and returns list->head (NULL if empty), fixing
// up the new head's prev pointer, or clearing tail/an owner-ish field
// (+0x78) on the popped node if the list is now empty.
struct Node {
    char pad[0x78];
    void *field78;
    void *prev;
    struct Node *next;
};
struct List {
    struct Node *head;
    struct Node *tail;
};

struct Node *FUN_02330b68(struct List *list)
{
    struct Node *node = list->head;
    if (node != 0) {
        struct Node *next = node->next;
        list->head = next;
        if (next != 0) {
            next->prev = 0;
        } else {
            list->tail = 0;
            node->field78 = 0;
        }
    }
    return node;
}
