//cpp
// decomp: module=unk_autoload_0 addr=0x02337d54 name=FUN_02337d54

// Returns 0x100 minus the two sub-totals from FUN_02337d0c and FUN_02337d30.

#pragma thumb on
extern "C" {
extern int FUN_02337d0c(void);
extern int FUN_02337d30(void);
int FUN_02337d54(void)
{
    int a = FUN_02337d0c();
    int b = FUN_02337d30();
    return (0x100 - a) - b;
}
}
