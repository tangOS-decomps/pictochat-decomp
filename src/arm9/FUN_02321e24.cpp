//cpp
// decomp: module=unk_autoload_0 addr=0x02321e24 name=FUN_02321e24

// Registers one 0x50-entry table and two smaller ones against the shared context
// G_0233b8c4, then binds each of the two to a key code.

#pragma thumb on
extern "C" {
extern void FUN_02321634(int, void *, void *, int);
extern void FUN_02321664(int, void *, void *, int);
extern void FUN_02321684(void *, void *, int);
extern int G_0238e05c[];
extern int G_0233b8c4[];
extern int G_0238e09c[];
extern int G_0238e0dc[];
void FUN_02321e24(int a)
{
    FUN_02321634(a, G_0238e05c, G_0233b8c4, 0x50);
    FUN_02321664(a, G_0238e09c, G_0233b8c4, 1);
    FUN_02321664(a, G_0238e0dc, G_0233b8c4, 2);
    FUN_02321684(G_0238e09c, G_0233b8c4, 0x2d);
    FUN_02321684(G_0238e0dc, G_0233b8c4, 0x2e);
}
}
