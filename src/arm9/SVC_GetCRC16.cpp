// decomp: module=unk_autoload_0 addr=0x02332d3a name=SVC_GetCRC16
// HAND-ASM PRIMITIVE: bare SWI/SVC syscall trampoline, sibling of
// FUN_02332d10 (see its comment for the full rationale and the mwccarm
// asm-syntax/--flags gotchas).
asm void SVC_GetCRC16(void) {
    swi 0xe
    bx lr
}
