// decomp: module=arm7 addr=0x022c688c name=FUN_022c688c
// flags: -O4,s -noThumb
// Unlinks a node from a doubly linked list whose head/tail live at
// 0x03805218 / 0x0380521c (base 0x0380520c, fields +0xc / +0x10).
// Node layout: prev at +0x14, next at +0x18.  A null node is ignored.
// NOTE: verify with --size 0x38, not funcs.json's 0x34 - the stated size
// excludes this function's own trailing pool word.
typedef struct Node {
    char pad[0x14];
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct NodeList {
    char pad[0xc];
    Node *head;
    Node *tail;
} NodeList;

extern NodeList G_0380520c;

void FUN_022c688c(Node *n) {
    Node *prev;
    Node *next;

    if (n == 0) {
        return;
    }
    next = n->next;
    prev = n->prev;
    if (next != 0) {
        next->prev = prev;
    } else {
        G_0380520c.tail = prev;
    }
    if (prev != 0) {
        prev->next = next;
    } else {
        G_0380520c.head = next;
    }
}
