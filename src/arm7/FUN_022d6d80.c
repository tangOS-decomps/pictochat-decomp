// decomp: module=arm7 addr=0x022d6d80 name=FUN_022d6d80
// flags: -noThumb
// Resets the eight 12-byte queue headers that start at +0x194 in the ARM7
// state block.
extern void FUN_022d6dd8(void *);

void FUN_022d6d80(void)
{
    unsigned char *p = *(unsigned char **)0x0380fff4;
    FUN_022d6dd8(p + 0x194);
    FUN_022d6dd8(p + 0x1a0);
    FUN_022d6dd8(p + 0x1ac);
    FUN_022d6dd8(p + 0x1b8);
    FUN_022d6dd8(p + 0x1c4);
    FUN_022d6dd8(p + 0x1d0);
    FUN_022d6dd8(p + 0x1dc);
    FUN_022d6dd8(p + 0x1e8);
}
