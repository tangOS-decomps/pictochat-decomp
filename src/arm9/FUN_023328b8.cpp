//cpp
// decomp: module=unk_autoload_0 addr=0x023328b8 name=FUN_023328b8

// Programs two fields of EXMEMCNT (0x04000204) from a two-int structure: the
// first int into bits 2-3, the second into bit 4. Each field is written with a
// separate read-modify-write, so the register is read twice.
//
// Two details are load-bearing:
//   * the parameter is `volatile int *`. Without it the compiler sinks each
//     load past the register read, which reorders the instructions and costs
//     the callee-saved register the ROM actually uses.
//   * each field value is read into a local BEFORE the read-modify-write. The
//     mask has to be evaluated before the shift, or the shifted value lands in
//     the wrong register and two redundant moves appear.

#pragma thumb on
extern "C" {
void FUN_023328b8(volatile int *p)
{
    volatile unsigned short *reg = (volatile unsigned short *)0x04000204;
    int a, b;
    a = p[0];
    *reg = (*reg & ~0xc) | (a << 2);
    b = p[1];
    *reg = (*reg & ~0x10) | (b << 4);
}
}
