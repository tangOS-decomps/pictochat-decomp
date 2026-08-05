//cpp
// decomp: module=unk_autoload_0 addr=0x0232b1c0 name=FUN_0232b1c0

// The FUN_0232a16c shape registering FUN_0232b1e0 through FUN_0232d050.

#pragma thumb on
extern "C" {
extern int FUN_02329c00(void);
extern int FUN_0232d050(void (*)(void));
extern void FUN_02329bd8(int);
extern void FUN_0232b1e0(void);
void FUN_0232b1c0(void)
{
    if (FUN_02329c00() == 0 && FUN_0232d050(FUN_0232b1e0) != 2)
        FUN_02329bd8(0xc);
}
}
