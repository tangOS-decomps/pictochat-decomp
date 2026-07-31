// decomp: module=unk_autoload_0 addr=0x02332d10 name=FUN_02332d10
// HAND-ASM PRIMITIVE: bare SWI/SVC syscall trampoline (NitroSDK/TwlSDK-style
// "SVC_xxx" BIOS-call wrapper) - the instruction IS the whole specification,
// no separate C shape to lose. Part of a family of one-instruction-per-
// syscall-number stubs sitting back-to-back in ROM (see FUN_02332d2e,
// FUN_02332d32, FUN_02332d3a, FUN_02332d42, FUN_02332d4e for siblings at
// other SWI numbers) - only some of the numbers in the run got their own
// Ghidra function boundary (presumably only the ones actually called from
// elsewhere in this range). mwccarm's asm wants bare `swi N` (no `#`,
// confirmed empirically - `svc`/`SWI`/`#`-prefixed forms all fail to
// assemble here) and match.py's auto -thumb-strip heuristic (triggered by
// the literal word "asm" in the source) is wrong for this Thumb-mode
// function, so verifying/rebuilding it needs an explicit --flags with
// -thumb kept in, not the bare --version default.
asm void FUN_02332d10(void) {
    swi 0x3
    bx lr
}
