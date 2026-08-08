//cpp
// decomp: module=unk_autoload_0 addr=0x023223f0 name=FUN_023223f0
// verify: python tools/match.py --c src/arm9/FUN_023223f0.cpp --func FUN_023223f0 --addr 0x023223f0 --size 0x30 --module unk_autoload_0 --version 2.0/sp1

// Queues a new value for entry `i` unless it already reads that way and no
// request is outstanding.  Each of the three fields is reached through its own
// base, which is why all three land in the pool separately.

#pragma thumb on
extern "C" {
extern int G_0238e134[];
extern int G_0238e138[];
extern int G_0238e144[];
void FUN_023223f0(int v, int i)
{
    int off = i * 0x54;

    if (v == *(int *)((char *)G_0238e134 + off) &&
        *(int *)((char *)G_0238e138 + off) == -1)
        return;
    *(int *)((char *)G_0238e138 + off) = v;
    *(int *)((char *)G_0238e144 + off) = 1;
}
}
