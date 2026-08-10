//cpp
// decomp: module=unk_autoload_0 addr=0x023272c8 name=FUN_023272c8
// NONMATCHING: state loading, loop control, branch bodies, and literal-pool layout are correct; the remaining 11 differences are callee-saved register coloring and scheduling. (div=11). Logic verified correct vs ROM; not byte-exact.

extern "C" {
typedef unsigned int u32;

extern u32 G_0239c930[];
typedef struct ChatState {
    u32 unused[3];
    char *large;
    char *small;
    u32 selector;
} ChatState;
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
    char *state;
    char *large;
    char *small;
    u32 selector;
    u32 low;

    state = (char *)G_0239c930;
    large = ((ChatState *)state)->large;
    small = ((ChatState *)state)->small;
    selector = ((ChatState *)state)->selector;

    int slot;
    int remaining;
    int i;
    int reverse;

    slot = (int)selector >> 3;
    low = selector & 7;
    remaining = FUN_02326780(slot);

    for (i = 0; i < 25; i++) {
        if (remaining >= 0) {
            reverse = 24 - i;
            FUN_023314e8(large + slot * 0x400, 0x400);
            FUN_02336c1c(large + slot * 0x400, reverse * 0x400, 0x400);
            FUN_023314e8(small + slot * 0x40, 0x40);
            FUN_02336ac8(small + slot * 0x40, reverse * 0x40, 0x40);
        } else {
            reverse = 24 - i;
            char *p = (char *)FUN_023366e8();
            FUN_0233746c(0, p + reverse * 0x400, 0x400);
            p = (char *)FUN_023364f0();
            FUN_0233746c(0, p + reverse * 0x40, 0x40);
        }
        slot = FUN_02326774(slot);
        remaining--;
    }

    *(u32 *)0x04000014 = (low + 4) << 16 & 0x01ff0000;
    *(u32 *)0x04000018 = low << 16 & 0x01ff0000;
}
}
