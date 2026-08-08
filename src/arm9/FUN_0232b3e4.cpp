//cpp
// decomp: module=unk_autoload_0 addr=0x0232b3e4 name=FUN_0232b3e4
// verify: python tools/match.py --c src/arm9/FUN_0232b3e4.cpp --func FUN_0232b3e4 --addr 0x0232b3e4 --size 0x2c --module unk_autoload_0 --version 2.0/sp1

// Retires the record: clears its two state bytes, reports the id, and returns
// both buffers through the installed free hook.

#pragma thumb on
extern "C" {
typedef void (*Free)(void *);
typedef struct R {
    unsigned char id;
    unsigned char a;
    unsigned char b;
    unsigned char pad;
    void *p1;
    void *p2;
} R;
extern void FUN_02331ffc(int);
extern Free G_023bd5ec;
void FUN_0232b3e4(R *r)
{
    r->a = 0;
    r->b = 0;
    FUN_02331ffc(r->id + 0x80);
    if (G_023bd5ec != 0) {
        G_023bd5ec(r->p1);
        G_023bd5ec(r->p2);
    }
}
}
