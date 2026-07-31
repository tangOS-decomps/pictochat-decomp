// decomp: module=unk_autoload_0 addr=0x0232cbc4 name=FUN_0232cbc4
// Validates three u16 fields of a struct against fixed ranges: offset 4
// must be <= 0x70, offset 0x18 must be in [10, 1000], offset 0x32 must be
// in [1, 14]. Returns 1 if all three hold, 0 otherwise.
int FUN_0232cbc4(void *s)
{
    unsigned short a = *(unsigned short *)((char *)s + 4);
    if (a > 0x70) return 0;
    unsigned short b = *(unsigned short *)((char *)s + 0x18);
    if (b < 10 || b > (unsigned short)(0xfa << 2)) return 0;
    unsigned short c = *(unsigned short *)((char *)s + 0x32);
    if (c < 1 || c > 0xe) return 0;
    return 1;
}
