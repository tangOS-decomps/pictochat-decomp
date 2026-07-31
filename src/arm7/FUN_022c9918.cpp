//cpp
extern "C" {
// decomp: module=arm7 addr=0x022c9918 name=FUN_022c9918
// Locked lookup of a packed relative-or-absolute pointer: reads a 32-bit
// slot at base + index*4 + 0x3c. 0 stays 0; a value below 0x02000000 (ARM9
// main RAM's base address) is treated as an offset from `base` and
// converted to an absolute pointer; anything >= 0x02000000 is already an
// absolute pointer and passed through as-is. FUN_022c7bc4/FUN_022c7bc8
// bracket it as an interrupt-disable/restore pair (unverified names).
extern void FUN_022c7bc4(void);
extern void FUN_022c7bc8(void);

void *FUN_022c9918(char *base, int index)
{
    FUN_022c7bc4();
    unsigned int v = *(unsigned int *)(base + index * 4 + 0x3c);
    void *result;
    if (v != 0) {
        if (v < 0x02000000) {
            result = base + v;
        } else {
            result = (void *)v;
        }
    } else {
        result = 0;
    }
    FUN_022c7bc8();
    return result;
}

}
