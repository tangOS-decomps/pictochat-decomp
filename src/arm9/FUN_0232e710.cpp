//cpp
// decomp: module=unk_autoload_0 addr=0x0232e710 name=FUN_0232e710
// verify: python tools/match.py --c src/arm9/FUN_0232e710.cpp --func FUN_0232e710 --addr 0x0232e710 --size 0x22 --module unk_autoload_0 --version 2.0/sp1

// Word-rounds the request (never zero) and routes it to the head or tail
// allocator depending on the sign of the alignment.

#pragma thumb on
extern "C" {
extern void *FUN_0232e640(void *, int, int);
extern void *FUN_0232e680(void *, int, int);
void *FUN_0232e710(char *o, int size, int align)
{
    void *heap = o + 0x24;

    if (size == 0) size = 1;
    size = (size + 3) & ~3;
    if (align >= 0) return FUN_0232e640(heap, size, align);
    return FUN_0232e680(heap, size, -align);
}
}
