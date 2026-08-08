//cpp
// decomp: module=unk_autoload_0 addr=0x02337930 name=FUN_02337930
// verify: python tools/match.py --c src/arm9/FUN_02337930.cpp --func FUN_02337930 --addr 0x02337930 --size 0x26 --module unk_autoload_0 --version 2.0/sp1

// Fills a fresh node with the five caller words and queues it.

#pragma thumb on
extern "C" {
typedef struct Node Node;
struct Node {
    Node *next;
    int a, b, c, d, e;
};
extern Node *FUN_02337ad0(int);
extern void FUN_02337b2c(Node *);
void FUN_02337930(int a, int b, int c, int d, int e)
{
    Node *n = FUN_02337ad0(1);

    if (n == 0) return;
    n->a = a;
    n->b = b;
    n->c = c;
    n->d = d;
    n->e = e;
    FUN_02337b2c(n);
}
}
