//cpp
// decomp: module=unk_autoload_0 addr=0x0232d238 name=FUN_0232d238

// When bit 3 of the word at 0x02fff890 is clear, calls FUN_0232d260(0x08000000).
// The ROM builds the argument by re-shifting the same constant 8 it used for the
// bit test.

#pragma thumb on
extern "C" {
extern void FUN_0232d260(int);
void FUN_0232d238(void)
{
    if ((*(volatile int *)0x02fff890 & 8) == 0) FUN_0232d260(0x08000000);
}
}
