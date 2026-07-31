// decomp: module=unk_autoload_0 addr=0x0233142c name=FUN_0233142c
// NONMATCHING: instruction-scheduling floor: the three independent final field stores (node->prev, node->next, list->tail) always land in a different order than the real binary (one word/2-instruction transposition) under every statement ordering tried (6 permutations) and other structural variants (struct literal, conditional-lvalue, tail-write-first) (div=1). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
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
void FUN_0233142c(struct List *list, struct Node *node)
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
