//cpp
// decomp: module=unk_autoload_0 addr=0x02337dd8 name=FUN_02337dd8
// verify: python tools/match.py --c src/arm9/FUN_02337dd8.cpp --func FUN_02337dd8 --addr 0x02337dd8 --size 0x30 --module unk_autoload_0 --version 2.0/sp1

// Pops the head of the singly-linked free list at G_023c1960 under the same
// lock pair FUN_02339034 uses; emptying the list also clears the tail at +0x10.

#pragma thumb on
extern "C" {
extern int FUN_02332080(void);
extern void FUN_02332094(int);
extern int G_023c1960[];

int FUN_02337dd8(void)
{
    int s = FUN_02332080();
    int node = G_023c1960[0];
    int next;

    if (node == 0) {
        FUN_02332094(s);
        return 0;
    }
    next = *(int *)node;
    G_023c1960[0] = next;
    if (next == 0) {
        G_023c1960[4] = 0;
    }
    FUN_02332094(s);
    return node;
}
}
