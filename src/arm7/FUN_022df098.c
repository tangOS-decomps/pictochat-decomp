// decomp: module=arm7 addr=0x022df098 name=FUN_022df098
// flags: -noThumb

// Runs FUN_022df0b0 then FUN_022ddf10(1).

extern void FUN_022df0b0(void);
extern void FUN_022ddf10(int);
void FUN_022df098(void)
{
    FUN_022df0b0();
    FUN_022ddf10(1);
}
