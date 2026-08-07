// decomp: module=arm7 addr=0x022c7af4 name=FUN_022c7af4
// NOTE: verify with --size 0x24, not the batch's 0x18 - the ROM's own 3
// trailing literal-pool words (seed pointer, multiplier, increment) sit
// right after `bx lr` and are part of the function's true byte range
// (same excluded-pool-word issue as FUN_022c614c/FUN_022c4854).
// LCG PRNG step: classic Numerical-Recipes constants (0x19660D / 0x3C6EF35F).

extern unsigned int G_03804948;

unsigned short FUN_022c7af4(void)
{
    unsigned int v = G_03804948 * 0x0019660D + 0x3C6EF35F;
    G_03804948 = v;
    return (unsigned short)(v >> 16);
}
