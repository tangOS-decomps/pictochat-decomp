//cpp
// decomp: module=unk_autoload_0 addr=0x023227e0 name=FUN_023227e0
#pragma thumb on
extern "C" {
extern const unsigned short G_0233a01c[];
extern unsigned short *FUN_023227a8(unsigned short *, int);
unsigned short *FUN_023227e0(unsigned short *out, int index)
{
    if (index < 10) {
        *out = G_0233a01c[index];
        out[1] = 0;
        return out + 1;
    }
    return FUN_023227a8(out, index);
}
}
