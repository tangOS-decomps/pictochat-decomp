// decomp: module=arm7 addr=0x022d8138 name=FUN_022d8138
#pragma arm on
extern "C" {
    void FUN_022d8138(unsigned short *dst, unsigned short *srcA, unsigned short *srcB) {
        dst[0] = srcA[0]; dst[1] = srcA[1]; dst[2] = srcA[2];
        dst[3] = srcB[0]; dst[4] = srcB[1]; dst[5] = srcB[2];
    }
}
