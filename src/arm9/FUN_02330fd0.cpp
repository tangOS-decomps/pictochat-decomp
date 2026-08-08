//cpp
// decomp: module=unk_autoload_0 addr=0x02330fd0 name=FUN_02330fd0
// verify: python tools/match.py --c src/arm9/FUN_02330fd0.cpp --func FUN_02330fd0 --addr 0x02330fd0 --size 0x18 --module unk_autoload_0 --version 2.0/sp1

// Walks the chain hanging off G_023c07c4+0x24 and returns the first link whose
// kind word is 1 (or null when the chain runs out).

#pragma thumb on
extern "C" {
typedef struct Link Link;
struct Link {
    char pad[0x64];
    int kind;
    Link *next;
};
extern Link *G_023c07c4[];
Link *FUN_02330fd0(void)
{
    Link *p = G_023c07c4[9];
    while (p != 0 && p->kind != 1) p = p->next;
    return p;
}
}
