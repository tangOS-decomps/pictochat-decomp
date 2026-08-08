//cpp
// decomp: module=unk_autoload_0 addr=0x0232e6cc name=FUN_0232e6cc
// verify: python tools/match.py --c src/arm9/FUN_0232e6cc.cpp --func FUN_0232e6cc --addr 0x0232e6cc --size 0x1a --module unk_autoload_0 --version 2.0/sp1

// Pushes the owner's current value down the whole item chain, then caches it
// in the chain's own slot.

#pragma thumb on
extern "C" {
typedef struct Item Item;
struct Item {
    char pad[8];
    int v;
    Item *next;
};

typedef struct Chain {
    int pad;
    int cur;
    Item *head;
} Chain;

typedef struct Owner {
    char pad[0x1c];
    int v;
    int pad2;
    Chain chain;
} Owner;

void FUN_0232e6cc(Owner *o)
{
    Item *it;
    Chain *c = &o->chain;

    it = c->head;
    while (it != 0) {
        it->v = o->v;
        it = it->next;
    }
    c->cur = o->v;
}
}
