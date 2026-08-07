// decomp: module=arm7 addr=0x022d81b8 name=FUN_022d81b8
// flags: -O4,s -noThumb

// Runs the reset at FUN_022d81e8, then zero-fills the 0xb4-byte region at
// +0x53c in the ARM7 state block pointed to by 0x0380fff4.  The fill helper
// at 0x037cb7a8 takes (value, dst, size).

extern void FUN_022d81e8(void);
extern void FUN_037cb7a8(int value, void *dst, int size);

void FUN_022d81b8(void)
{
    FUN_022d81e8();
    FUN_037cb7a8(0, *(char **)0x0380fff4 + 0x53c, 0xb4);
}
