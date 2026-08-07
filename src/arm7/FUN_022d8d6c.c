// decomp: module=arm7 addr=0x022d8d6c name=FUN_022d8d6c
// flags: -noThumb

typedef unsigned int uint;
typedef unsigned short ushort;

uint FUN_022d8d6c(ushort *param_1)
{
    unsigned char uVar1;
    if ((uint)param_1 & 1) {
        uVar1 = *(ushort *)((int)param_1 - 1) >> 8;
    } else {
        uVar1 = *param_1;
    }
    return uVar1 & 0xff;
}
