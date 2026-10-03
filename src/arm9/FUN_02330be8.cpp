//cpp
// decomp: module=unk_autoload_0 addr=0x02330be8 name=FUN_02330be8
// verify: python tools/match.py --c src/arm9/FUN_02330be8.cpp --func FUN_02330be8 --addr 0x02330be8 --size 0x38 --module unk_autoload_0 --version 2.0/sp1

// Insert counterpart of FUN_02330c20: places the node into the chain rooted
// at G_023c07c4+0x24, kept sorted ascending by the word at +0x70.
// The cur/prev/head declaration order (inits as statements) is load-bearing
// for the r3/r4/r5 colouring.

#pragma thumb on
extern "C" {
typedef struct Node Node;
struct Node {
    char pad[0x68];
    Node *next;          /* +0x68 */
    char pad2[4];
    unsigned int key;    /* +0x70 */
};
extern Node *G_023c07c4[];
void FUN_02330be8(Node *n)
{
    Node *cur;
    Node *prev;
    Node *head;

    prev = 0;
    head = G_023c07c4[9];
    cur = head;
    while (cur != 0 && cur->key < n->key) {
        prev = cur;
        cur = cur->next;
    }
    if (prev == 0) {
        n->next = head;
        G_023c07c4[9] = n;
    } else {
        n->next = prev->next;
        prev->next = n;
    }
}
}
