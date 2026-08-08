//cpp
// decomp: module=unk_autoload_0 addr=0x0233142c name=FUN_0233142c
// verify: python tools/match.py --c src/arm9/FUN_0233142c.cpp --func FUN_0233142c --addr 0x0233142c --size 0x20 --module unk_autoload_0 --version 2.0/sp1

// Appends a node to the doubly-linked queue kept at +0x88/+0x8c.

#pragma thumb on
extern "C" {
typedef struct Node Node;
struct Node {
    char pad[0x10];
    Node *next;
    Node *prev;
};
typedef struct List {
    char pad[0x88];
    Node *head;
    Node *tail;
} List;

void FUN_0233142c(List *l, Node *n)
{
    Node *tail = l->tail;

    if (tail == 0) l->head = n;
    else tail->next = n;
    n->prev = tail;
    n->next = 0;
    l->tail = n;
}
}
