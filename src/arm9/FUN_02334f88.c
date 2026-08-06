// decomp: module=unk_autoload_0 addr=0x02334f88 name=FUN_02334f88

// Sign bit of a double: the classic push {r0-r3} prologue spills the register
// double to the stack and reads the high word. Sits in the libm region next to
// the 0x7FF00000 exponent-mask functions.

int FUN_02334f88(double x) {
    return ((int*)&x)[1] & 0x80000000;
}
