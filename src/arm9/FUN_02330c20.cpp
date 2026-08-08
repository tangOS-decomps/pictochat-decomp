//cpp
// decomp: module=unk_autoload_0 addr=0x02330c20 name=FUN_02330c20
// verify: python tools/match.py --c src/arm9/FUN_02330c20.cpp --func FUN_02330c20 --addr 0x02330c20 --size 0x2c --module unk_autoload_0 --version 2.0/sp1

// Unlinks the node from the chain rooted at G_023c07c4+0x24.

#pragma thumb on
extern "C" {
typedef struct Node Node;
struct Node {
    char pad[0x68];
    Node *next;
};
extern Node *G_023c07c4[];
void FUN_02330c20(Node *n)
{
    Node *prev = 0;
    Node *cur = G_023c07c4[9];

    while (cur != 0 && cur != n) {
        prev = cur;
        cur = cur->next;
    }
    if (prev == 0) G_023c07c4[9] = n->next;
    else prev->next = n->next;
}
}
