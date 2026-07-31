//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x0233144c name=FUN_0233144c
// Doubly-linked list remove: the counterpart to FUN_0233142c's append-at-
// tail (same list/node layout - head at +0x88, tail at +0x8c, next/prev
// at +0x10/+0x14). Unlinks `node` from `list`.
struct Node {
    char pad[0x10];
    struct Node *next;
    struct Node *prev;
};
struct List {
    char pad[0x88];
    struct Node *head;
    struct Node *tail;
};
void FUN_0233144c(struct List *list, struct Node *node)
{
    struct Node *next = node->next;
    struct Node *prev = node->prev;
    if (next == 0) {
        list->tail = prev;
    } else {
        next->prev = prev;
    }
    if (prev == 0) {
        list->head = next;
    } else {
        prev->next = next;
    }
}

}
