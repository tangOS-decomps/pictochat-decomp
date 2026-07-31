// decomp: module=arm7 addr=0x022d8138 name=FUN_022d8138
// Contributed by opie-x (TangOS Discord): AI-assisted candidate (local
// checkpoints/final-v1 model), verified byte-exact via tools/match.py.
// Copies three halfwords each from srcA and srcB into consecutive dst slots.
void FUN_022d8138(unsigned short *dst, unsigned short *srcA, unsigned short *srcB) {
    dst[0] = srcA[0]; dst[1] = srcA[1]; dst[2] = srcA[2];
    dst[3] = srcB[0]; dst[4] = srcB[1]; dst[5] = srcB[2];
}
