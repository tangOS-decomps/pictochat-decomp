// decomp: module=arm7 addr=0x022d865c name=FUN_022d865c
// flags: -noThumb
// NOTE: verify with --size 0x20, not the batch's 0x18 - the ROM's own 2
// trailing literal-pool words (reg pointer, tail-call target) sit right
// after `bx ip` and are part of the function's true byte range (same
// excluded-pool-word issue as FUN_022c614c/FUN_022c7af4/FUN_022c9a24).

extern void FUN_037fb780(void);

void FUN_022d865c(unsigned int value)
{
    *(volatile unsigned short *)0x0480817E = (unsigned short)value;
    *(volatile unsigned short *)0x0480817C = (unsigned short)(value >> 16);
    FUN_037fb780();
}
