//cpp
// decomp: module=unk_autoload_0 addr=0x0232fc14 name=FUN_0232fc14

// Finishes a transfer: flushes through FUN_0232fbd8, hands the byte range to
// FUN_02337894, then releases the handle.

#pragma thumb on
extern "C" {
extern void FUN_0232fbd8(int, int, int, int);
extern void FUN_02337894(int, int);
extern void FUN_02338020(int);
void FUN_0232fc14(int a, int b, int c, int d)
{
    FUN_0232fbd8(a, c, d, d);
    FUN_02337894(a, a + b);
    FUN_02338020(a);
}
}
