// decomp: module=unk_autoload_0 addr=0x023320e4 name=ARMProcessorMode
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/ARMProcessorMode.c. Compiles byte-identical here too (verified: tools/match.py
// --func ARMProcessorMode --addr 0x023320e4 --size 0xc --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
asm void ARMProcessorMode(void) { mrs r0, cpsr; and r0, r0, #0x1f; bx lr }
