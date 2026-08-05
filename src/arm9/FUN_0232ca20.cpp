//cpp
// decomp: module=unk_autoload_0 addr=0x0232ca20 name=FUN_0232ca20

// Returns 0x8000 when FUN_0232c4dc reports busy, otherwise the halfword at
// 0x02fffcfa.

#pragma thumb on
extern "C" {
extern int FUN_0232c4dc(void);
unsigned short FUN_0232ca20(void)
{
    if (FUN_0232c4dc() != 0) return 0x8000;
    return *(unsigned short *)0x02fffcfa;
}
}
