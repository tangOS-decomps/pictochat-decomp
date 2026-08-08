//cpp
// decomp: module=unk_autoload_0 addr=0x02337e88 name=FUN_02337e88
// verify: python tools/match.py --c src/arm9/FUN_02337e88.cpp --func FUN_02337e88 --addr 0x02337e88 --size 0x2c --module unk_autoload_0 --version 2.0/sp1

// Fires slot `k & 0xff` of the callback table, but only if the generation byte
// packed into the high half of `k` still matches.

#pragma thumb on
extern "C" {
typedef void (*Fn)(int);
typedef struct Slot {
    Fn fn;
    int arg;
    unsigned char gen;
} Slot;
extern Slot G_023c3440[];
void FUN_02337e88(int k)
{
    unsigned char idx = (unsigned char)k;
    unsigned char gen = (unsigned char)(k >> 8);
    Slot *s = &G_023c3440[idx];

    if (gen != s->gen) return;
    if (s->fn == 0) return;
    s->fn(s->arg);
}
}
