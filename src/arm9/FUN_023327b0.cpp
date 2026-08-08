//cpp
// decomp: module=unk_autoload_0 addr=0x023327b0 name=FUN_023327b0
// verify: python tools/match.py --c src/arm9/FUN_023327b0.cpp --func FUN_023327b0 --addr 0x023327b0 --size 0x2c --module unk_autoload_0 --version 2.0/sp1

// Reports bit 1 of the shared-WRAM status byte, kicking the enable path once
// if it is still clear.

#pragma thumb on
extern "C" {
typedef struct HW {
    char pad[5];
    unsigned char b0 : 1;
    unsigned char ready : 1;
    unsigned char rest : 6;
} HW;
extern int FUN_0233276c(void);
extern void FUN_023327dc(void);
int FUN_023327b0(void)
{
    HW *hw = (HW *)0x02FFFC30;

    if (FUN_0233276c() == 0) return 0;
    if (hw->ready == 0) FUN_023327dc();
    return hw->ready;
}
}
