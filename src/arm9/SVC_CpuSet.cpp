// decomp: module=unk_autoload_0 addr=0x02332d2e name=SVC_CpuSet
// HAND-ASM PRIMITIVE: bare SWI/SVC syscall trampoline, sibling of
// FUN_02332d10 (see its comment for the full rationale and the mwccarm
// asm-syntax/--flags gotchas).
asm void SVC_CpuSet(void) {
    swi 0xb
    bx lr
}
