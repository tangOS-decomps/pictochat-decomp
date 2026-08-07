// decomp: module=arm7 addr=0x022c857c name=FUN_022c857c
void FUN_022c857c(unsigned char *object)
{
    object[0] = 0;
    object[2] = 0;
    object[3] = 1;
    object[1] = 0x10;
    *(unsigned short *)(object + 4) = 0;
}
