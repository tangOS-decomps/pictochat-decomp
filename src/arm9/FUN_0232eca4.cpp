//cpp
// decomp: module=unk_autoload_0 addr=0x0232eca4 name=FUN_0232eca4
// verify: python tools/match.py --c src/arm9/FUN_0232eca4.cpp --func FUN_0232eca4 --addr 0x0232eca4 --size 0x3c --module unk_autoload_0 --version 2.0/sp1

// Takes a node from slot `i`'s free pool at G_023be9c4 (0x24-byte per-slot
// entries, pool head at +0xc), cross-links it with `b`, then announces the
// node's +8 word through FUN_0232f7dc and returns it.

#pragma thumb on
extern "C" {
typedef struct Nodeca4 {
    char pad[8];
    void *f8;
    void *fc;
} Nodeca4;
typedef struct Enteca4 {
    char pad[0xc];
    char f0c[0x18];
} Enteca4;
extern Enteca4 G_023be9c4[];
extern Nodeca4 *FUN_0232e178(char *, int);
extern void FUN_0232e13c(char *, Nodeca4 *);
extern void FUN_0232f7dc(void *);
void *FUN_0232eca4(int i, Nodeca4 *b)
{
    Nodeca4 *n = FUN_0232e178(G_023be9c4[i].f0c, 0);

    if (n == 0) return 0;
    FUN_0232e13c(G_023be9c4[i].f0c, n);
    n->fc = b;
    b->f8 = n;
    FUN_0232f7dc(n->f8);
    return n->f8;
}
}
