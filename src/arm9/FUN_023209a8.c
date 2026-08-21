// decomp: module=unk_autoload_0 addr=0x023209a8 name=FUN_023209a8
#pragma thumb on
void FUN_023209a8(char *dst, const int *src)
{
    *(short *)(dst + 0x06) = src[0] >> 4;
    *(short *)(dst + 0x0e) = src[1] >> 4;
    *(short *)(dst + 0x16) = src[2] >> 4;
    *(short *)(dst + 0x1e) = src[3] >> 4;
}
