// decomp: module=unk_autoload_0 addr=0x0232dc5c name=FUN_0232dc5c
#pragma thumb on

extern int FUN_0232db60(int a, unsigned short e, int c, int d);
extern void FUN_0232dc8c(int a, int b, int c, int d, unsigned short e, int f);

void FUN_0232dc5c(int a, int b, int c, int d, unsigned short e, int f)
{
    unsigned short t = FUN_0232db60(a, e, c, d);
    FUN_0232dc8c(a, b, c, d, t, f);
}
