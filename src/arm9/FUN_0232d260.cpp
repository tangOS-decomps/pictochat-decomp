//cpp
// decomp: module=unk_autoload_0 addr=0x0232d260 name=FUN_0232d260
#pragma thumb on
#pragma opt_common_subs off

extern "C" {
extern void FUN_02330938(int, int, int);
extern void FUN_02330998(int, int, int);
extern volatile unsigned int G_02fff888[];

unsigned short FUN_0232d260(unsigned int mask)
{
    unsigned short saved = *(volatile unsigned short *)0x04000208;
    *(volatile unsigned short *)0x04000208 = 0;
    FUN_02330938(0x6e, (int)G_02fff888, 0);
    G_02fff888[2] |= mask;
    FUN_02330998(0x6e, (int)G_02fff888, 0);
    unsigned short result = *(volatile unsigned short *)0x04000208;
    *(volatile unsigned short *)0x04000208 = saved;
    return result;
}
}
