// decomp: module=arm7 addr=0x022c614c name=FUN_022c614c
// flags: -noThumb
// size: 0x1c - includes the trailing pool word; Ghidra's cached 0x18 stops at
// `bx lr` (see notes/pictochat-layout.md).

// Sets the requested bit in the 16-bit flag word at 0x038051ec and returns the
// new value.

extern unsigned short G_038051ec;

int FUN_022c614c(unsigned int bit)
{
    int v = G_038051ec | (1 << bit);
    G_038051ec = v;
    return v;
}
