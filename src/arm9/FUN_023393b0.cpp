//cpp
// decomp: module=unk_autoload_0 addr=0x023393b0 name=FUN_023393b0
// verify: python tools/match.py --c src/arm9/FUN_023393b0.cpp --func FUN_023393b0 --addr 0x023393b0 --size 0x30 --module unk_autoload_0 --version 2.0/sp1

// Swaps the idle callback to the drain routine for the duration of the wait,
// then leaves the pump routine installed.

#pragma thumb on
extern "C" {
typedef void (*VoidFn)(void);
extern int FUN_02339394(void *, int *);
extern void FUN_023390b8(void);
extern void FUN_02339084(void);
extern void FUN_0233905c(void);
extern VoidFn G_0236a180;
int FUN_023393b0(void)
{
    int out;
    int rc = FUN_02339394((void *)FUN_023390b8, &out);

    if (rc != 0) return rc;
    G_0236a180 = FUN_02339084;
    G_0236a180();
    G_0236a180 = FUN_0233905c;
    return out;
}
}
