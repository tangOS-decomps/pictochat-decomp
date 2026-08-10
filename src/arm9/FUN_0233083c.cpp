//cpp
// decomp: module=unk_autoload_0 addr=0x0233083c name=FUN_0233083c

// Writes the two linker-defined stack guard values. The constants are kept as
// address-valued externs because the original object materialized them through
// relocations rather than folding the address arithmetic at compile time.
extern "C" {
extern unsigned char G_03000000[];
extern unsigned char G_fddb597d[];
extern unsigned char G_00003f7c[];
extern unsigned char G_7bf9dd5b[];
extern unsigned char G_00001000[];

void FUN_0233083c(void)
{
    unsigned int base;
    unsigned int first;
    register unsigned int offset;
    unsigned int second;

    base = (unsigned int)G_03000000;
    offset = (unsigned int)G_fddb597d;
    first = offset;
    offset = (unsigned int)G_00003f7c;
    second = (unsigned int)G_7bf9dd5b;

    *(volatile unsigned int *)(base + offset) = first;
    *(volatile unsigned int *)(base + (offset + 4) - (unsigned int)G_00001000) = second;
}
}
