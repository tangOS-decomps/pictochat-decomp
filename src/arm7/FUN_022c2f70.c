// decomp: module=arm7 addr=0x022c2f70 name=FUN_022c2f70
// flags: -O4,s -noThumb

typedef unsigned int u32;
typedef unsigned short u16;

extern unsigned char *G_0380fff4;

u32 FUN_022c2f70(u32 value)
{
    if (value >= 0x04805f60) {
        value -= *(u16 *)(G_0380fff4 + 0x3de);
    }
    return value;
}
