// decomp: module=unk_autoload_0 addr=0x02332d32 name=FUN_02332d32
// HAND-ASM PRIMITIVE: bare SWI/SVC syscall trampoline, sibling of
// FUN_02332d10 (see its comment for the full rationale and the mwccarm
// asm-syntax/--flags gotchas).
asm void FUN_02332d32(void) {
    swi 0xc
    bx lr
}
