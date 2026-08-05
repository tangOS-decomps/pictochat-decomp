//cpp
// decomp: module=unk_autoload_0 addr=0x0232f688 name=FUN_0232f688

// Returns entry `i` of the 0x10-byte table hanging off +0x84 of G_023bf010,
// or null when `i` is past the count stored at +8.

#pragma thumb on
extern "C" {
extern int G_023bf010[];
int FUN_0232f688(unsigned int i)
{
    int base = *(int *)(G_023bf010[0] + 0x84);
    if (i >= *(unsigned int *)(base + 8)) return 0;
    return *(int *)(base + i * 0x10 + 0x10);
}
}
