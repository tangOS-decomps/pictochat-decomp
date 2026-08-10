//cpp
// decomp: module=unk_autoload_0 addr=0x023272c8 name=FUN_023272c8
// verify: python tools/match.py --c src/arm9/FUN_023272c8.cpp --func FUN_023272c8 --addr 0x023272c8 --size 0xc8 --module unk_autoload_0 --version 2.0/sp1

extern "C" {
typedef unsigned int u32;

int FUN_02326780(int);
int FUN_02326774(int);
void FUN_023314e8(void *, int);
void FUN_02336c1c(void *, int, int);
void *FUN_023366e8(void);
void *FUN_023364f0(void);
void FUN_0233746c(int, void *, int);
void FUN_02336ac8(void *, int, int);

void FUN_023272c8(void)
{
    char *state = (char *)0x0239c930;
    char *large = *(char **)(state + 0x0c);
    char *small = *(char **)(state + 0x10);
    u32 selector = *(u32 *)(state + 0x14);
    int slot = (int)selector >> 3;
    int remaining = FUN_02326780(slot);
    int i;

    for (i = 0; i < 25; i++) {
        int reverse = 24 - i;
        if (remaining < 0) {
            char *p = (char *)FUN_023366e8();
            FUN_0233746c(0, p + reverse * 0x400, 0x400);
            p = (char *)FUN_023364f0();
            FUN_0233746c(0, p + reverse * 0x40, 0x40);
        } else {
            FUN_023314e8(large + slot * 0x400, 0x400);
            FUN_02336c1c(large + slot * 0x400, reverse * 0x400, 0x400);
            FUN_023314e8(small + slot * 0x40, 0x40);
            FUN_02336ac8(small + slot * 0x40, reverse * 0x40, 0x40);
        }
        slot = FUN_02326774(slot);
        remaining--;
    }

    *(u32 *)0x04000014 = ((selector & 7) + 4) << 16 & 0x01ff0000;
    *(u32 *)0x04000018 = (selector & 7) << 16 & 0x01ff0000;
}
}
