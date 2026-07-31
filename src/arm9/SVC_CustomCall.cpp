// decomp: module=unk_autoload_0 addr=0x02332d4e name=SVC_CustomCall
// HAND-ASM PRIMITIVE: bare SWI/SVC syscall trampoline, sibling of
// FUN_02332d10 (see its comment for the full rationale and the mwccarm
// asm-syntax/--flags gotchas).
asm void SVC_CustomCall(void) {
    swi 0x13
    bx lr
}
