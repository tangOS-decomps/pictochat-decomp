//cpp
// decomp: module=unk_autoload_0 addr=0x02332884 name=FUN_02332884

// Reads the two EXMEMCNT fields that FUN_023328b8 writes back into a two-int
// structure, then forces the first field to 3 and clears the second.
//
// The field extractions are ARITHMETIC shifts - the masked value promotes to
// `int` - and the register is `volatile` because the ROM re-reads it for every
// statement.

#pragma thumb on
extern "C" {
void FUN_02332884(int *out)
{
    volatile unsigned short *reg = (volatile unsigned short *)0x04000204;
    out[0] = (*reg & 0xc) >> 2;
    out[1] = (*reg & 0x10) >> 4;
    *reg = (*reg & ~0xc) | 0xc;
    *reg = *reg & ~0x10;
}
}
