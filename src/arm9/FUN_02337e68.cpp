//cpp
// decomp: module=unk_autoload_0 addr=0x02337e68 name=FUN_02337e68
// verify: python tools/match.py --c src/arm9/FUN_02337e68.cpp --func FUN_02337e68 --addr 0x02337e68 --size 0x20 --module unk_autoload_0 --version 2.0/sp1

// Refills slot `i` of the table FUN_02337e38 blanks and returns its bumped
// generation byte.

#pragma thumb on
extern "C" {
typedef struct Slot {
    int a;
    int b;
    unsigned char gen;
} Slot;
extern Slot G_023c3440[];
int FUN_02337e68(int i, int a, int b)
{
    Slot *s = &G_023c3440[i];

    s->a = a;
    s->b = b;
    s->gen++;
    return s->gen;
}
}
