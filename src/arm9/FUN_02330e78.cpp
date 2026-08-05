//cpp
// decomp: module=unk_autoload_0 addr=0x02330e78 name=FUN_02330e78

// Takes the lock, then hands the field at +0x20 of G_023c07c4 to FUN_02330e90.

#pragma thumb on
extern "C" {
extern void FUN_02332080(void);
extern void FUN_02330e90(int, int);
extern int G_023c07c4[];
void FUN_02330e78(void)
{
    FUN_02332080();
    FUN_02330e90(G_023c07c4[8], 0);
}
}
