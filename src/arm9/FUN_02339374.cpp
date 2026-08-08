//cpp
// decomp: module=unk_autoload_0 addr=0x02339374 name=FUN_02339374
// verify: python tools/match.py --c src/arm9/FUN_02339374.cpp --func FUN_02339374 --addr 0x02339374 --size 0x20 --module unk_autoload_0 --version 2.0/sp1

// Two-argument sibling of FUN_023392f8.

#pragma thumb on
extern "C" {
typedef void (*VoidFn)(void);
extern int FUN_02339318(int, int, void *, int *);
extern void FUN_023390b8(void);
extern VoidFn G_0236a180;
int FUN_02339374(int a, int b)
{
    int out;
    int rc = FUN_02339318(a, b, (void *)FUN_023390b8, &out);

    if (rc != 0) return rc;
    G_0236a180();
    return out;
}
}
