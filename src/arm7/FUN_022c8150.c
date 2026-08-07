// decomp: module=arm7 addr=0x022c8150 name=FUN_022c8150
#include "include/nds/types.h"

extern void FUN_022c864c(void *a, u32 b);

#pragma thumb on

struct Target41Struct {
    u32 words[3];
};

u32 FUN_022c8150(u8 *param_1, const struct Target41Struct *param_2, u32 param_3, u32 param_4) {
    param_1[1] = 0;
    *(struct Target41Struct *)(param_1 + 0x38) = *param_2;
    *(u32 *)(param_1 + 0x44) = param_3;
    FUN_022c864c(param_1, param_4);
    return 1;
}
