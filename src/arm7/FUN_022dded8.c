// decomp: module=arm7 addr=0x022dded8 name=FUN_022dded8
#pragma arm
extern void FUN_037c5de8(unsigned short *a, unsigned short *b);

void FUN_022dded8(unsigned short *a, unsigned short *b)
{
    unsigned short *p = b + b[7];
    b[6] = p[8];
    p[9] = 2;
    p[10] = 0;
    p[11] = b[12];
    FUN_037c5de8(a, b);
}
