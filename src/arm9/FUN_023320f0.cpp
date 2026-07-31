//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x023320f0 name=FUN_023320f0
// HAND-ASM PRIMITIVE: register-only busy-wait spin loop (cycle-count delay,
// likely a NitroSDK/TwlSDK-style OS_SpinWait) - no separate C shape to lose.
// A plain-C do-while translation of this either optimizes away entirely
// (verified: `count` has no observable effect, non-volatile compiles to a
// bare `bx lr`) or, if `volatile` is added to survive that, forces per-
// iteration stack loads/stores that don't match the real 3-instruction body
// at all. The tight loop directly reuses SUBS's own carry flag for the
// branch rather than a separate CMP - a hand-timed cycle-count loop, not
// something this compiler's do-while lowering produces from source.
asm void FUN_023320f0(unsigned int count) {
Loop:
    subs r0, r0, #4
    bhs Loop
    bx lr
}

}
