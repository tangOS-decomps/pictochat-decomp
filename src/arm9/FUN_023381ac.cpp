//cpp
// decomp: module=unk_autoload_0 addr=0x023381ac name=FUN_023381ac
// verify: python tools/match.py --c src/arm9/FUN_023381ac.cpp --func FUN_023381ac --addr 0x023381ac --size 0x20 --module unk_autoload_0 --version 2.0/sp1

// Writes one slot of the table at +0x3c under the object lock and flushes just
// that word.

#pragma thumb on
extern "C" {
typedef struct Tbl {
    char pad[0x3c];
    int slot[1];
} Tbl;
extern void FUN_02337980(Tbl *);
extern void FUN_02337990(void);
extern void FUN_023314e8(void *, int);
void FUN_023381ac(Tbl *t, int i, int v)
{
    FUN_02337980(t);
    t->slot[i] = v;
    FUN_023314e8(&t->slot[i], 4);
    FUN_02337990();
}
}
