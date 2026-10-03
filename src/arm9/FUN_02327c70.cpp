//cpp
// decomp: module=unk_autoload_0 addr=0x02327c70 name=FUN_02327c70
// verify: python tools/match.py --c src/arm9/FUN_02327c70.cpp --func FUN_02327c70 --addr 0x02327c70 --size 0x2c --module unk_autoload_0 --version 2.0/sp1

// Sibling of FUN_02327c54: probes the handle at +0x3c through FUN_02325b74,
// reports 4 or 0xf accordingly, then hands the block to FUN_0232571c.

#pragma thumb on
extern "C" {
extern int FUN_02325b74(int, int *, int);
extern void FUN_02320978(int);
extern void FUN_0232571c(int *);
void FUN_02327c70(int *a)
{
    int tmp;

    if (FUN_02325b74(a[0xf], &tmp, 1) != 0) {
        FUN_02320978(4);
    } else {
        FUN_02320978(0xf);
    }
    FUN_0232571c(a);
}
}
