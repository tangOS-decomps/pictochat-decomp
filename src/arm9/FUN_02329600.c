// decomp: module=unk_autoload_0 addr=0x02329600 name=FUN_02329600
#pragma thumb on
extern unsigned char G_023bd5c0[];
extern void *FUN_02332080(void *);
extern void FUN_02332094(void *);

void FUN_02329600(void)
{
    unsigned char v = G_023bd5c0[1];
    void *p = FUN_02332080(G_023bd5c0);
    if (v < G_023bd5c0[0]) v = v + 6;
    G_023bd5c0[3] = v - G_023bd5c0[0];
    FUN_02332094(p);
}
