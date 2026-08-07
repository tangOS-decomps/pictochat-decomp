// decomp: module=arm7 addr=0x022d98d8 name=FUN_022d98d8
// flags: -O4,p -noThumb

typedef unsigned int u32;

extern unsigned char G_037f9614[];
extern void FUN_037c8f18(u32, void *, u32, u32);
extern void FUN_037c904c(u32);

void FUN_022d98d8(u32 unused0, u32 unused1, u32 arg2, u32 arg3)
{
    FUN_037c8f18(0x01000000, G_037f9614, arg2, arg3);
    FUN_037c904c(0x01000000);
}
