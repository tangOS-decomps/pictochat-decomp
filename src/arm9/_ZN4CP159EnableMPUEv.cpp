// decomp: module=unk_autoload_0 addr=0x023317a4 name=_ZN4CP159EnableMPUEv
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/_ZN4CP159EnableMPUEv.c. Compiles byte-identical here too (verified: tools/match.py
// --func _ZN4CP159EnableMPUEv --addr 0x023317a4 --size 0x10 --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
unsigned int _ZN4CP159EnableMPUEv(void){
    unsigned int v;
    asm { mrc p15,0,v,c1,c0,0 }
    v |= 1;
    asm { mcr p15,0,v,c1,c0,0 }
    return v;
}
