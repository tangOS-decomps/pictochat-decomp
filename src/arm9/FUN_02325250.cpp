//cpp
// decomp: module=unk_autoload_0 addr=0x02325250 name=FUN_02325250
// verify: python tools/match.py --c src/arm9/FUN_02325250.cpp --func FUN_02325250 --addr 0x02325250 --size 0x28 --module unk_autoload_0 --version 2.0/sp1

// Maps the current triple to its id, or 0 when the triple has no repeat.  The
// block is reached through both its array and its record declaration, which is
// why its address lands in the pool twice.

#pragma thumb on
extern "C" {
typedef struct Triple {
    unsigned short a, b, c;
    unsigned short pad[2];
    unsigned short id;
} Triple;

extern int FUN_023251cc(void *);
extern int FUN_023212c8(int);
extern unsigned short G_0239c108[];
extern Triple T_0239c108;
unsigned short FUN_02325250(void)
{
    int v;

    if (FUN_023251cc(G_0239c108) != 0) v = FUN_023212c8(T_0239c108.id);
    else v = 0;
    return (unsigned short)v;
}
}
