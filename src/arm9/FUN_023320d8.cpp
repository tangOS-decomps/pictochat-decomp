//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x023320d8 name=FUN_023320d8
// HAND-ASM PRIMITIVE: same category as the sibling IRQ::Enable/Disable/Restore
// and ARMProcessorMode functions right next to this one in the ROM (see
// notes/cross-project-matching.md) - a bare CPSR-bit read with no side effect
// and no separate C shape to lose. Likely an "IsIrqDisabled"-style query
// (reads the same 0x80 IRQ-disable bit that IRQ::Enable/Disable/Restore
// toggle), but not identified in the sm64ds-decomp cross-match batch, so kept
// as FUN_023320d8 rather than guessing a mangled symbol name.
asm unsigned int FUN_023320d8(void) { mrs r0, cpsr; and r0, r0, #0x80; bx lr }

}
