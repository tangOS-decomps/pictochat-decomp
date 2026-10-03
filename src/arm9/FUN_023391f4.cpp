//cpp
// decomp: module=unk_autoload_0 addr=0x023391f4 name=FUN_023391f4
#pragma thumb on

extern "C" {
extern void FUN_023391a0(unsigned int *cmd, int count);
extern int FUN_023396c0(int a, int b, int c, int d);

int FUN_023391f4(unsigned int a, unsigned short b)
{
    unsigned int data[2];

    data[0] = 0x03006000;
    FUN_023391a0(data, 1);

    while (FUN_023396c0(0, 2, 0, 1) != 1) {
    }

    data[0] = 0x02006200 | (a & 0xff);
    data[1] = 0x01010000 | (b & 0xffff);
    FUN_023391a0(data, 2);
    return 0;
}
}
