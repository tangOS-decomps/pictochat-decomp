// decomp: module=arm7 addr=0x022d7374 name=FUN_022d7374
// flags: -O4,s -noThumb
// size: 0x24 - the stated 0x20 excludes the trailing pool word (0x0380fff4).

// Stores a 0..1 selector into the halfword at +0x332 of the ARM7 state block.
// Rejects anything above 1 with error code 5.  Note the stored value is the
// argument itself - `movhi r0, #5` only fires on the reject path, so on the
// accept path r0 still holds the parameter when the strh executes.

int FUN_022d7374(unsigned int sel)
{
    if (sel > 1) {
        return 5;
    }
    *(unsigned short *)(*(int *)0x0380fff4 + 0x332) = (unsigned short)sel;
    return 0;
}
