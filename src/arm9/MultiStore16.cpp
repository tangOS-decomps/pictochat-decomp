// decomp: module=unk_autoload_0 addr=0x0233740c name=MultiStore16
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/MultiStore16.c. Compiles byte-identical here too (verified: tools/match.py
// --func MultiStore16 --addr 0x0233740c --size 0x18 --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
//
// NOTE: this one is compiled ARM-mode in the real binary despite being plain C
// (no asm block for match.py's auto-detect to key off) - pass
// --flags "-O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc"
// (i.e. the default minus -thumb) to reproduce the match.
void MultiStore16(short val, char *dst, int nbytes) {
    int i = 0;
    do {
        if (i < nbytes) {
            *(short*)(dst + i) = val;
            i += 2;
        } else break;
    } while (1);
}
