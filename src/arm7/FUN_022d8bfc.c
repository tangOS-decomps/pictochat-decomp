// decomp: module=arm7 addr=0x022d8bfc name=FUN_022d8bfc
// flags: -noThumb
// NOTE: verify with --size 0x20, not the batch's 0x18 - the ROM's own 2
// trailing literal-pool words (conn-struct pointer, tail-call target) sit
// right after `bx ip` and are part of the function's true byte range
// (same excluded-pool-word issue as FUN_022c614c/FUN_022d865c). The
// 0x0380fff4 pointer indirection matches the sibling FUN_022d84e0.

extern void *FUN_037fe090(void *);

void *FUN_022d8bfc(void)
{
    return FUN_037fe090((void *)(*(int *)0x0380fff4 + 0x634));
}
