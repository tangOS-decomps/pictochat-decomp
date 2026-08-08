//cpp
// decomp: module=unk_autoload_0 addr=0x0232e958 name=FUN_0232e958
// verify: python tools/match.py --c src/arm9/FUN_0232e958.cpp --func FUN_0232e958 --addr 0x0232e958 --size 0x28 --module unk_autoload_0 --version 2.0/sp1

// Runs the pass over every live slot of the sixteen-entry table.

#pragma thumb on
extern "C" {
typedef struct Slot {
    char pad[0x2c];
    unsigned char live;
    char pad2[0x17];
} Slot;
extern Slot G_023be584[];
extern void FUN_0232ec6c(Slot *, void *);
void FUN_0232e958(void *arg)
{
    int i;

    for (i = 0; i < 0x10; i++)
        if (G_023be584[i].live != 0) FUN_0232ec6c(&G_023be584[i], arg);
}
}
