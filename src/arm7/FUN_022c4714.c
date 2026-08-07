// decomp: module=arm7 addr=0x022c4714 name=FUN_022c4714
// flags: -noThumb
// size: 0x24 - includes the two trailing pool words; Ghidra's cached 0x1c
// stops at `bx lr` (see notes/pictochat-layout.md).

// Clears the two-word block at 0x03804eec and the shared-RAM word at
// 0x02fffc3c, and hands the cleared block back.
//
// The block pointer has to be RETURNED, not just written through: that is what
// pins it to r0. Spelled as a void function mwcc colours it r1 and gives r0 to
// the 0x02fffc3c base, inverting every register against the ROM.

int *FUN_022c4714(void)
{
    int *p = (int *)0x03804eec;
    p[1] = 0;
    p[0] = 0;
    *(int *)0x02fffc3c = 0;
    return p;
}
