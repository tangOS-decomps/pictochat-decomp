//cpp
// decomp: module=unk_autoload_0 addr=0x0232df14 name=FUN_0232df14

// Returns the LOW byte of entry `i` of the halfword table at +0xc - the
// FUN_0232de60 shape with `(v << 24) >> 24`.

#pragma thumb on
extern "C" {
extern int FUN_0232db60(void);
unsigned int FUN_0232df14(int p)
{
    int i = FUN_0232db60();
    return ((unsigned int)*(unsigned short *)(*(int *)(p + 0xc) + i * 2) << 24) >> 24;
}
}
