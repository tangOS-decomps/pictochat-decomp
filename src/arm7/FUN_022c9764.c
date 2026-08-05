// decomp: module=arm7 addr=0x022c9764 name=FUN_022c9764

// Returns the address of a per-slot record in the table at G_03805838: indices
// below 0x10 land in the per-entry block chosen by the byte at +1 of `p`,
// higher indices land in the shared block at +0x260.

#pragma thumb on
extern int G_03805838;
int FUN_022c9764(int p, int i)
{
    int base = G_03805838;
    if (base == 0) return 0;
    if (i < 0x10)
        return base + 0x20 + *(unsigned char *)(p + 1) * 0x24 + i * 2;
    return base + 0x260 + (i - 0x10) * 2;
}
