//cpp
// decomp: module=unk_autoload_0 addr=0x02321770 name=FUN_02321770
// NONMATCHING: byte-identical ONLY under `#pragma optimize_for_size on`, which
// the surrounding code contradicts. Counts as decompiled, not matched.
//
// Walks the list rooted at `p` with the iterator FUN_0232e178, calling
// FUN_02321708 on every element whose byte at +0x28 is zero. The logic is not
// in doubt - the shape below compiles to the target's exact instructions.
//
// What is in doubt is the build setting. At the project's normal settings the
// compiler PEELS the first iteration (it calls the iterator once before the
// loop and enters with a `beq`, 0x2c bytes); the ROM instead jumps to a test at
// the bottom (`b test`, 0x26 bytes). Adding `#pragma optimize_for_size on`
// reproduces the ROM byte-for-byte:
//
//     python tools/match.py --c <this, with the pragma> --func FUN_02321770 \
//       --addr 0x02321770 --size 0x26 --module unk_autoload_0 --version 2.0/sp1
//     -> MATCHING VERSIONS: 2.0/sp1
//
// That match was NOT banked, because the pragma cannot be true here. Eight
// already-matched functions bracketing this one on both sides - FUN_02321198,
// FUN_023213c4, FUN_02321480, FUN_023215e4 below it and FUN_02321c58,
// FUN_02321cf8, FUN_02321f9c, FUN_02321fbc above it - all match at the normal
// settings and ALL EIGHT break under the pragma. Code from one translation unit
// is laid out contiguously, so this function sits in the same file as functions
// that were demonstrably not built optimize-for-size. A byte match bought with
// a flag its own neighbours disprove is a wrong answer that happens to have the
// right bytes, so it is parked here instead.
//
// The real difference is therefore still the loop rotation, and the C phrasing
// that avoids the peel at default settings has not been found yet. Tried, all
// at 2.0/sp1: the plain `while ((e = f(p, e)) != 0)` above (0x2c, peeled);
// `for (;;) { e = f(p, e); if (!e) break; ... }` (0x24); the same with
// `continue` instead of the nested if (0x24); `goto` into a `do`/`while` body
// to force the bottom test (0x2c); `goto` into a `for (;;)` (0x2c); and the
// two honoured pragmas `opt_loop_invariants off` and `opt_common_subs off`,
// separately and together (0x2c in every combination).

#pragma thumb on
extern "C" {
extern int FUN_0232e178(int *, int);
extern void FUN_02321708(int);

void FUN_02321770(int *p)
{
    int e = 0;
    while ((e = FUN_0232e178(p, e)) != 0) {
        if (*(unsigned char *)(e + 0x28) == 0)
            FUN_02321708(e);
    }
}
}
