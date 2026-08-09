// decomp: module=unk_autoload_0 addr=0x02334564 name=FUN_02334564
#pragma thumb on
extern void FUN_02334528(int, int, int, void *);

void FUN_02334564(int a, int b, ...)
{
    FUN_02334528(a, -1, b, (char *)(((int)&b) & ~3) + 4);
}
