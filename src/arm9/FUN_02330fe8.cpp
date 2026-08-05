//cpp
// decomp: module=unk_autoload_0 addr=0x02330fe8 name=FUN_02330fe8

// Runs FUN_02330c4c under the FUN_02332080/FUN_02332094 lock pair. The lock
// cookie is carried in a local across the call.

#pragma thumb on
extern "C" {
extern int FUN_02332080(void);
extern void FUN_02330c4c(void);
extern void FUN_02332094(int);
void FUN_02330fe8(void)
{
    int v = FUN_02332080();
    FUN_02330c4c();
    FUN_02332094(v);
}
}
