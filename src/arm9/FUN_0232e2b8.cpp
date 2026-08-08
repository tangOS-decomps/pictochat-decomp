//cpp
// decomp: module=unk_autoload_0 addr=0x0232e2b8 name=FUN_0232e2b8
// verify: python tools/match.py --c src/arm9/FUN_0232e2b8.cpp --func FUN_0232e2b8 --addr 0x0232e2b8 --size 0x1a --module unk_autoload_0 --version 2.0/sp1

// Lays a fresh 0x10-byte header over the head of the context's buffer: tag,
// cleared flags, the remaining room after the header, and two zeroed words.

#pragma thumb on
extern "C" {
typedef struct Hdr {
    unsigned short tag;
    unsigned short flags;
    int room;
    int a;
    int b;
} Hdr;

typedef struct Ctx {
    char *buf;
    char *end;
} Ctx;

Hdr *FUN_0232e2b8(Ctx *c, int tag)
{
    Hdr *h = (Hdr *)c->buf;

    h->tag = (unsigned short)tag;
    h->flags = 0;
    h->room = c->end - ((char *)h + 0x10);
    h->a = 0;
    h->b = 0;
    return h;
}
}
