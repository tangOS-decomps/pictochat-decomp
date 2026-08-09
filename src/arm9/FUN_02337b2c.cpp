//cpp
// decomp: module=unk_autoload_0 addr=0x02337b2c name=FUN_02337b2c
// NONMATCHING: identical apart from base-pointer caching: the target keeps the queue base live across the if/else merge, mwcc reloads it from the pool afterwards. This is the base-pointer caching floor already documented in notes/tooling.md. (div=4). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.

// Appends the node to the singly-linked queue at G_023c1960 with interrupts
// held off.

#pragma thumb on
extern "C" {
typedef struct Node Node;
struct Node {
    Node *next;
};
typedef struct Q {
    char pad[8];
    Node *head;
    Node *tail;
} Q;
extern int FUN_02332080(void);
extern void FUN_02332094(int);
extern Q G_023c1960;
void FUN_02337b2c(Node *n)
{
    int s = FUN_02332080();
    Q *q = &G_023c1960;
    Node *tail = q->tail;

    if (tail == 0) q->head = n;
    else tail->next = n;
    q->tail = n;
    n->next = 0;
    FUN_02332094(s);
}
}
