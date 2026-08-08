//cpp
// decomp: module=unk_autoload_0 addr=0x02339298 name=FUN_02339298
// verify: python tools/match.py --c src/arm9/FUN_02339298.cpp --func FUN_02339298 --addr 0x02339298 --size 0x28 --module unk_autoload_0 --version 2.0/sp1

// Queues the three-argument request with FUN_023390b8 as its hook; on
// immediate success pumps the idle callback and returns the filled slot.

#pragma thumb on
extern "C" {
typedef void (*VoidFn)(void);
extern int FUN_02339250(int, int, int, void *, int *);
extern void FUN_023390b8(void);
extern VoidFn G_0236a180;
int FUN_02339298(int a, int b, int c)
{
    int out;
    int rc = FUN_02339250(a, b, c, (void *)FUN_023390b8, &out);

    if (rc != 0) return rc;
    G_0236a180();
    return out;
}
}
