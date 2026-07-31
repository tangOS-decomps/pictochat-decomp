// decomp: module=unk_autoload_0 addr=0x023321f4 name=FUN_023321f4
// HAND-ASM PRIMITIVE: a bare count-leading-zeros wrapper (ARMv5TE CLZ) with
// no separate C shape - a plain-C leading-zero loop compiles to 0x30 bytes
// (a real loop) here, not the single instruction, and this compiler doesn't
// recognize any of the common CLZ intrinsic spellings (__cntlz32, _clz,
// __clz, _CountLeadingZeros, _lzcnt all compile as unresolved external
// calls, not the CLZ opcode) - verified empirically, not assumed.
asm unsigned int FUN_023321f4(unsigned int x) {
    clz r0, r0
    bx lr
}
