//cpp
// decomp: module=unk_autoload_0 addr=0x0232de60 name=FUN_0232de60

// Returns the HIGH byte of entry `i` of the halfword table at +0xc, where `i`
// comes from FUN_0232db60.
//
// The extraction is `(v << 16) >> 24` on an UNSIGNED value, which is the exact
// `lsls #16`/`lsrs #24` pair in the ROM. Writing it as `(unsigned char)(v >> 8)`
// is the same number but compiles to three instructions instead of two.

#pragma thumb on
extern "C" {
extern int FUN_0232db60(void);
unsigned int FUN_0232de60(int p)
{
    int i = FUN_0232db60();
    return ((unsigned int)*(unsigned short *)(*(int *)(p + 0xc) + i * 2) << 16) >> 24;
}
}
