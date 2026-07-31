// decomp: module=arm7 addr=0x022d811c name=FUN_022d811c
// Contributed by opie-x (TangOS Discord): AI-assisted candidate (local
// checkpoints/final-v1 model), verified byte-exact via tools/match.py.
// Copies three halfwords from src to dst.
void FUN_022d811c(unsigned short *dst, unsigned short *src) {
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
}
