// decomp: module=arm7 addr=0x022d8e04 name=FUN_022d8e04
// flags: -O4,s -noThumb

// Folds one byte of data into a 16-bit CRC, a nibble at a time, using the
// 16-entry half-word table at 0x023163f8.  The table is XOR-linear, so the
// usual tbl[(crc ^ data) & 0xf] step is written out as the two separate
// lookups tbl[crc & 0xf] ^ tbl[data & 0xf].

extern const unsigned short G_023163f8[];

unsigned short FUN_022d8e04(int data, int crc)
{
    unsigned short hi;
    unsigned short c;

    hi = (crc >> 4) & 0xfff;
    c = (G_023163f8[crc & 0xf] ^ hi) ^ G_023163f8[data & 0xf];
    hi = (c >> 4) & 0xfff;
    return (G_023163f8[c & 0xf] ^ hi) ^ G_023163f8[(data >> 4) & 0xf];
}
