//cpp
// decomp: module=unk_autoload_0 addr=0x023295e4 name=FUN_023295e4

// Writes the gap between two byte cursors at G_023bd5c0 into the third byte,
// wrapping the read cursor by 6 when it trails the write cursor. The wrap is
// truncated back to 8 bits, which is the lsls/lsrs #24 pair.

#pragma thumb on
extern "C" {
extern unsigned char G_023bd5c0[];
void FUN_023295e4(void)
{
    unsigned char v = G_023bd5c0[1];
    if (v < G_023bd5c0[0]) v = v + 6;
    G_023bd5c0[2] = v - G_023bd5c0[0];
}
}
