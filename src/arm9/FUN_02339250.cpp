//cpp
// decomp: module=unk_autoload_0 addr=0x02339250 name=FUN_02339250
#pragma thumb on
extern "C" {
int FUN_02339034(void);
void FUN_02339454(unsigned int);
extern int G_023c3564[];
int FUN_02339250(unsigned int a, unsigned int b, int c, int d, int e)
{
    if (FUN_02339034() == 0) {
        return 1;
    }
    G_023c3564[12] = d;
    G_023c3564[13] = e;
    G_023c3564[14] = c;
    FUN_02339454(0x02006100 | (unsigned char)a);
    FUN_02339454(0x01010000 | (unsigned short)b);
    return 0;
}
}
