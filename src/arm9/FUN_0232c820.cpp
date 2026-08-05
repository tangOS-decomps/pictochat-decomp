//cpp
// decomp: module=unk_autoload_0 addr=0x0232c820 name=FUN_0232c820

// Clears bit 0 of the halfword at 0x02ffff96 if it is set. The register is read
// once and the loaded value reused for the write-back, not re-read.

#pragma thumb on
extern "C" {
void FUN_0232c820(void)
{
    unsigned short v = *(volatile unsigned short *)0x02ffff96;
    if (v & 1) *(volatile unsigned short *)0x02ffff96 = v & ~1;
}
}
