//cpp
// decomp: module=unk_autoload_0 addr=0x02332290 name=FUN_02332290

// Runs FUN_02332080 once and then calls FUN_0233229c forever - this never
// returns, which is why there is no epilogue after the loop.

#pragma thumb on
extern "C" {
extern void FUN_02332080(void);
extern void FUN_0233229c(void);
void FUN_02332290(void)
{
    FUN_02332080();
    for (;;) FUN_0233229c();
}
}
