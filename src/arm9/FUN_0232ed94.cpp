//cpp
// decomp: module=unk_autoload_0 addr=0x0232ed94 name=FUN_0232ed94

// Tears down whatever the object at `p` owns: when the byte at +0x2c is 2 it
// first releases the handle at +0x3c through FUN_02337710, then releases the
// same handle through FUN_023376cc unconditionally, then hands the object to
// FUN_0232ee10.
//
// Both bytes are read UNSIGNED. Writing +0x2c as `char` gives an ldrsb and
// stops matching - the ROM uses ldrb.

#pragma thumb on
extern "C" {
extern void FUN_02337710(unsigned int, int);
extern void FUN_023376cc(unsigned int);
extern void FUN_0232ee10(int);

void FUN_0232ed94(int p)
{
    if (*(unsigned char *)(p + 0x2c) == 2)
        FUN_02337710(*(unsigned char *)(p + 0x3c), -723);
    FUN_023376cc(*(unsigned char *)(p + 0x3c));
    FUN_0232ee10(p);
}
}
