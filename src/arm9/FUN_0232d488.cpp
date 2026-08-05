//cpp
// decomp: module=unk_autoload_0 addr=0x0232d488 name=FUN_0232d488

// Drains FUN_0232d3fc for as long as FUN_0232d4a0 keeps reporting work. The ROM
// PEELS the first test - it calls the predicate once before the loop and enters
// on a `beq` - which is what the plain `while` spelling produces here.

#pragma thumb on
extern "C" {
extern int FUN_0232d4a0(void);
extern void FUN_0232d3fc(void);
void FUN_0232d488(void)
{
    while (FUN_0232d4a0() != 0) FUN_0232d3fc();
}
}
