//cpp
// decomp: module=unk_autoload_0 addr=0x0232e614 name=FUN_0232e614
// verify: python tools/match.py --c src/arm9/FUN_0232e614.cpp --func FUN_0232e614 --addr 0x0232e614 --size 0x2c --module unk_autoload_0 --version 2.0/sp1

// Stamps the arena header (tagged 'HMRF') over the region and seeds the
// sub-block at +0x24 from the bounds already stored at +0x18/+0x1c.

#pragma thumb on
extern "C" {
typedef struct Sub {
    void *a;
    void *b;
    int c;
    char tail[1];
} Sub;

typedef struct Arena {
    char pad[0x18];
    void *lo;
    void *hi;
    int pad2;
    Sub sub;
} Arena;

extern void FUN_0232e1f4(Arena *, int, void *, char *, int);
Arena *FUN_0232e614(Arena *s, char *end, int c)
{
    Sub *b = &s->sub;

    FUN_0232e1f4(s, 0x46524D48, &b->tail, end, c);
    b->a = s->lo;
    b->b = s->hi;
    b->c = 0;
    return s;
}
}
