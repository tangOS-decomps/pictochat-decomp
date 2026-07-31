// decomp: module=arm7 addr=0x022d816c name=FUN_022d816c
// Contributed by opie-x (TangOS Discord): AI-assisted candidate (local
// checkpoints/final-v1 model), verified byte-exact via tools/match.py.
// Copies three halfwords each from s1, s2, s3 into consecutive out slots.
void FUN_022d816c(unsigned short *out, unsigned short *s1, unsigned short *s2, unsigned short *s3) {
    out[0] = s1[0]; out[1] = s1[1]; out[2] = s1[2];
    out[3] = s2[0]; out[4] = s2[1]; out[5] = s2[2];
    out[6] = s3[0]; out[7] = s3[1]; out[8] = s3[2];
}
