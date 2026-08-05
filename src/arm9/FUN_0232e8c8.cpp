//cpp
// decomp: module=unk_autoload_0 addr=0x0232e8c8 name=FUN_0232e8c8

// Stores the low 16 bits of `v` into the first word of entry `i` of the
// 0x24-byte table at G_023be9dc.

#pragma thumb on
extern "C" {
extern char G_023be9dc[];
void FUN_0232e8c8(int i, unsigned int v)
{
    *(unsigned int *)(G_023be9dc + i * 0x24) = v & 0xffff;
}
}
