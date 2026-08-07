// decomp: module=arm7 addr=0x022d7398 name=FUN_022d7398
// flags: -O4,s -noThumb

// Programs a two-register radio setting: rejects out-of-range values with
// error 5, otherwise writes `mode` to register 0x13 and `value` to 0x35.

extern void FUN_022d862c(int reg, int value);

int FUN_022d7398(unsigned int mode, unsigned int value)
{
    if (mode > 3) {
        return 5;
    }
    if (value > 0x3f) {
        return 5;
    }
    FUN_022d862c(0x13, mode);
    FUN_022d862c(0x35, value);
    return 0;
}
