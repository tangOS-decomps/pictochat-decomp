// decomp: module=arm7 addr=0x022c8c14 name=FUN_022c8c14
// Packs three FUN_022c88bc(p) results into a 24-bit little-endian-ish value
// (call1 | call2<<8 | call3<<16) - likely reading three color channels
// (R,G,B) from a shared cursor/stream that FUN_022c88bc advances.
extern int FUN_022c88bc(void *p);

int FUN_022c8c14(void *p)
{
    int acc = FUN_022c88bc(p);
    acc |= FUN_022c88bc(p) << 8;
    acc |= FUN_022c88bc(p) << 16;
    return acc;
}
