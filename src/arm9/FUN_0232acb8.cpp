//cpp
// decomp: module=unk_autoload_0 addr=0x0232acb8 name=FUN_0232acb8
// verify: python tools/match.py --c src/arm9/FUN_0232acb8.cpp --func FUN_0232acb8 --addr 0x0232acb8 --size 0x1c --module unk_autoload_0 --version 2.0/sp1

// Raises event 8, copies the caller's halfword at +0xa into the slot at
// G_023bd698+0xc, then kicks the follow-up pass.

#pragma thumb on
extern "C" {
extern void FUN_02329bd8(int);
extern void FUN_0232b0d0(void);
extern unsigned short G_023bd698[];
void FUN_0232acb8(unsigned short *p)
{
    FUN_02329bd8(8);
    G_023bd698[6] = p[5];
    FUN_0232b0d0();
}
}
