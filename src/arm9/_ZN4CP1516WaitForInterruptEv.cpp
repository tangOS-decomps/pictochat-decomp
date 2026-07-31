// decomp: module=unk_autoload_0 addr=0x0233229c name=_ZN4CP1516WaitForInterruptEv
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/_ZN4CP1516WaitForInterruptEv.c. CP15 system-control coprocessor
// primitive (SDK hardware abstraction layer), not game-specific code. See
// notes/cross-project-matching.md.
//
// NOTE: unlike every other matched function so far, this one does NOT
// compile byte-identical on any dsi/ build - only the NTR-era 1.2/* family
// (verified: tools/match.py --func _ZN4CP1516WaitForInterruptEv --addr
// 0x0233229c --size 0xc --module unk_autoload_0 --version 1.2/sp2p3 --flags
// "-O4,p -enum int -lang c99 -char signed -interworking -proc arm946e
// -gccext,on -msgstyle gcc"). Every dsi/ build instead materializes the
// local `v = 0` via a literal-pool load instead of `mov r0,#0` - likely an
// optimizer-heuristic change between the compiler families, not evidence
// this ROM used 1.2/*: every other matched function only lines up on dsi/,
// and tools/probe_versions.py finds the whole dsi/ family codegen-identical
// for everything tried so far. Flagged here in case a pattern emerges.
void _ZN4CP1516WaitForInterruptEv(void){
    unsigned int v = 0;
    asm { mcr p15,0,v,c7,c0,4 }
}
