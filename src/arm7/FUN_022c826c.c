// decomp: module=arm7 addr=0x022c826c name=FUN_022c826c
#include "include/nds/types.h"

extern u16 FUN_022c8600(u32 param_1);

#pragma thumb on

void FUN_022c826c(u8 *param_1, u32 param_2) {
    *(u16 *)(param_1 + 0x20) = FUN_022c8600(param_2);
}
