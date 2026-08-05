//cpp
// decomp: module=unk_autoload_0 addr=0x0232a4fc name=FUN_0232a4fc

// Stores `v` at G_023bd698 when the mode from FUN_0232996c is 0 or 1. The mode
// is fetched twice - the ROM does not cache it across the ||.

#pragma thumb on
extern "C" {
extern int FUN_0232996c(void);
extern unsigned short G_023bd698[];
void FUN_0232a4fc(unsigned short v)
{
    if (FUN_0232996c() == 0 || FUN_0232996c() == 1) G_023bd698[0] = v;
}
}
