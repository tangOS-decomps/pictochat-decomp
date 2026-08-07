// decomp: module=arm7 addr=0x022d8d40 name=FUN_022d8d40
// flags: -O4,s -noThumb

void FUN_022d8d40(unsigned short *dst, unsigned short value)
{
    if ((unsigned int)dst & 1) {
        *(unsigned short *)((char *)dst - 1) =
            (*(unsigned short *)((char *)dst - 1) & 0xff) | (value << 8);
    } else {
        *dst = (*dst & 0xff00) | (value & 0xff);
    }
}
