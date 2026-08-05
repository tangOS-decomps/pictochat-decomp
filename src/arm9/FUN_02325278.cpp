//cpp
// decomp: module=unk_autoload_0 addr=0x02325278 name=FUN_02325278

// Returns the low 16 bits of FUN_023212bc(0x2fff) when that call reports
// non-zero, and falls back to FUN_02325250 otherwise. The predicate call is made
// twice - the ROM does not cache it.

#pragma thumb on
extern "C" {
extern int FUN_023212bc(int);
extern unsigned int FUN_02325250(void);
unsigned int FUN_02325278(void)
{
    if (FUN_023212bc(0x2fff) != 0)
        return (unsigned short)FUN_023212bc(0x2fff);
    return FUN_02325250();
}
}
