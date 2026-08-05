// decomp: module=arm7 addr=0x022d7144 name=FUN_022d7144
// flags: -noThumb

// Sets bit 0 of the mode word at +0x33a of the ARM7 state block from `v`,
// rejecting anything above 1 with code 5.
//
// The guard has to be written `if (v > 1) return 5;` and not `if (v < 2) {...}`.
// Same condition, but the ROM emits cmp #1 / movhi / bxhi where the other
// spelling gives cmp #2 / movhs / bxhs.

int FUN_022d7144(unsigned int v)
{
    unsigned short *p;
    if (v > 1) return 5;
    p = (unsigned short *)(*(int *)0x0380fff4 + 0x33a);
    *p = (*p & ~1) | (v & 1);
    return 0;
}
