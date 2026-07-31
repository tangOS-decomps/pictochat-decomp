// decomp: module=unk_autoload_0 addr=0x02329270 name=FUN_02329270
// Ghidra's cached size for this one (0x2c) stops mid-jump-table - it can't
// statically resolve the indirect `add pc,r0` dispatch, so its code-flow
// boundary misses the last table entry and the default-case body. True
// size is 0x38 (56 bytes); see notes/tooling.md's "Ghidra's function size
// can exclude a trailing literal pool" section for the same undercounting
// pattern in non-switch functions.
int FUN_02329270(int v)
{
    switch (v) {
        case 0: return 0;
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
        case 4: return 3;
        case 5: return 0;
        default: return 0;
    }
}
