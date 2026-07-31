// ==========================================================
// C++ Class Implementation: SVC
// ==========================================================

// --- SVC_WaitByLoop.cpp ---
// decomp: module=unk_autoload_0 addr=0x02332d10 name=SVC_WaitByLoop
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
asm void SVC_WaitByLoop(void) {
    swi 0x3
    bx lr
}

// --- SVC_CpuSet.cpp ---
// decomp: module=unk_autoload_0 addr=0x02332d2e name=SVC_CpuSet
// HAND-ASM PRIMITIVE: bare SWI/SVC syscall trampoline, sibling of
// FUN_02332d10 (see its comment for the full rationale and the mwccarm
// asm-syntax/--flags gotchas).
asm void SVC_CpuSet(void) {
    swi 0xb
    bx lr
}

// --- SVC_FastCopy.cpp ---
// decomp: module=unk_autoload_0 addr=0x02332d32 name=SVC_FastCopy
// HAND-ASM PRIMITIVE: bare SWI/SVC syscall trampoline, sibling of
// FUN_02332d10 (see its comment for the full rationale and the mwccarm
// asm-syntax/--flags gotchas).
asm void SVC_FastCopy(void) {
    swi 0xc
    bx lr
}

// --- SVC_GetCRC16.cpp ---
// decomp: module=unk_autoload_0 addr=0x02332d3a name=SVC_GetCRC16
// HAND-ASM PRIMITIVE: bare SWI/SVC syscall trampoline, sibling of
// FUN_02332d10 (see its comment for the full rationale and the mwccarm
// asm-syntax/--flags gotchas).
asm void SVC_GetCRC16(void) {
    swi 0xe
    bx lr
}

// --- SVC_IsDebuggerPresent.cpp ---
// decomp: module=unk_autoload_0 addr=0x02332d42 name=SVC_IsDebuggerPresent
// HAND-ASM PRIMITIVE: bare SWI/SVC syscall trampoline, sibling of
// FUN_02332d10 (see its comment for the full rationale and the mwccarm
// asm-syntax/--flags gotchas).
asm void SVC_IsDebuggerPresent(void) {
    swi 0x10
    bx lr
}

// --- SVC_CustomCall.cpp ---
// decomp: module=unk_autoload_0 addr=0x02332d4e name=SVC_CustomCall
// HAND-ASM PRIMITIVE: bare SWI/SVC syscall trampoline, sibling of
// FUN_02332d10 (see its comment for the full rationale and the mwccarm
// asm-syntax/--flags gotchas).
asm void SVC_CustomCall(void) {
    swi 0x13
    bx lr
}

