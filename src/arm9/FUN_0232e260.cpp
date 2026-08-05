//cpp
// decomp: module=unk_autoload_0 addr=0x0232e260 name=FUN_0232e260

// Fills a two-word descriptor from the packet at `p`: the start pointer is `p`
// backed up by the 7-bit header field at +2, and the end pointer is `p` plus
// 0x10 plus the length at +4.
//
// The backed-up offset is truncated to 16 bits before the subtraction - that is
// the lsls/lsrs #16 pair - so the intermediate has to be `unsigned short`.

#pragma thumb on
extern "C" {
void FUN_0232e260(int *out, int p)
{
    unsigned short d = (*(unsigned short *)(p + 2) >> 8) & 0x7f;
    out[0] = p - d;
    out[1] = *(int *)(p + 4) + (p + 0x10);
}
}
