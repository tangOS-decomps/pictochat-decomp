//cpp
// decomp: module=unk_autoload_0 addr=0x02331a3c name=FUN_02331a3c

// Installs FUN_02331940 as the handler at 0x02fffd9c, but only when
// G_023c0a40[0] is set.

#pragma thumb on
extern "C" {
extern void FUN_02331940(void);
extern int G_023c0a40[];
void FUN_02331a3c(void)
{
    if (G_023c0a40[0] != 0)
        *(void (**)(void))0x02fffd9c = FUN_02331940;
}
}
