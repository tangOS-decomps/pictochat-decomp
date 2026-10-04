// decomp: module=unk_autoload_0 addr=0x02335da4 name=FUN_02335da4
// flags: -noThumb

// First entry of the runtime's 64-bit divide/modulo pair (assembly in the
// original runtime): saves the shared frame, selects the quotient (r4 = 0),
// and falls into the common body of its sibling FUN_02335db0, whose own entry
// selects the remainder (r4 = 1). Only 0xc bytes long; the 0x140 in the
// symbol map is Ghidra running on into the next routines.

extern void func_02335db8(void); /* common body inside FUN_02335db0 */

asm void FUN_02335da4(void)
{
    stmfd sp!, {r4-r7, r11, r12, lr}
    mov r4, #0
    b func_02335db8
}
