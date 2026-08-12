// decomp: module=unk_autoload_0 addr=0x02338074 name=FUN_02338074
#pragma thumb on

typedef struct Node {
    struct Node *prev;
    struct Node *next;
} Node;

extern void FUN_02337980(void);
extern void FUN_02337990(void);
extern void FUN_023314e8(void *, int);

void FUN_02338074(Node **self)
{
    Node *n;

    FUN_02337980();
    n = self[6];
    while (n != 0) {
        Node *next = n->next;
        n->prev = 0;
        n->next = 0;
        FUN_023314e8(n, 8);
        n = next;
    }
    FUN_02337990();
}
