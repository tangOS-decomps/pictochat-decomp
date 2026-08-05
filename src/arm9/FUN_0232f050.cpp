//cpp
// decomp: module=unk_autoload_0 addr=0x0232f050 name=FUN_0232f050

// Calls FUN_0232f304 only when G_023bef1c[0] is non-null and G_023bef1c[1] is
// exactly 1.

#pragma thumb on
extern "C" {
extern void FUN_0232f304(void);
extern int G_023bef1c[];
void FUN_0232f050(void)
{
    if (G_023bef1c[0] != 0 && G_023bef1c[1] == 1) FUN_0232f304();
}
}
