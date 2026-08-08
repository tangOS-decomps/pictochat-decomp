//cpp
// decomp: module=unk_autoload_0 addr=0x0232b74c name=FUN_0232b74c
// verify: python tools/match.py --c src/arm9/FUN_0232b74c.cpp --func FUN_0232b74c --addr 0x0232b74c --size 0x2c --module unk_autoload_0 --version 2.0/sp1

// Sets up a ring of `n` records of `size` bytes, allocating its backing store
// through the installed allocator when there is one.

#pragma thumb on
extern "C" {
typedef void *(*Alloc)(int, int);
typedef struct Ring {
    void *buf;
    int n;
    unsigned short head;
    unsigned short tail;
    unsigned short size;
} Ring;
extern Alloc G_023bd5fc;
void FUN_0232b74c(Ring *r, int n, int size)
{
    if (G_023bd5fc != 0) r->buf = G_023bd5fc(size * n, 4);
    r->head = 0;
    r->tail = 0;
    r->n = n;
    r->size = (unsigned short)size;
}
}
