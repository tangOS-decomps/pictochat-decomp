//cpp
// decomp: module=unk_autoload_0 addr=0x02337e54 name=FUN_02337e54

// Increments the byte at +8 of entry `i` of the 0xc-byte table at G_023c3440.
// The counter is read with `ldrb`, so it is unsigned.

#pragma thumb on
extern "C" {
extern unsigned char G_023c3440[];
void FUN_02337e54(int i)
{
    unsigned char *p = G_023c3440 + i * 0xc;
    p[8] = p[8] + 1;
}
}
