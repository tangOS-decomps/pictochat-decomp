//cpp
// decomp: module=arm7 addr=0x022c9c18 name=FUN_022c9c18

typedef unsigned int u32;

extern "C" void FUN_022c7c8c(void*, void*, u32);
extern "C" void FUN_022c73a0(int, void*);
extern unsigned char G_038069bc[];
extern unsigned char G_038069dc[];
extern unsigned char G_03801b39[];
extern volatile u32 G_03805838;

extern "C" void FUN_022c9c18(void)
{
    FUN_022c7c8c(G_038069bc, G_038069dc, 8);
    FUN_022c73a0(7, G_03801b39);
    G_03805838 = 0;
}
