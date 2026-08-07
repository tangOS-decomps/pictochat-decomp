//cpp
// decomp: module=unk_autoload_0 addr=0x0233206c name=FUN_0233206c
extern "C" {
asm unsigned int FUN_0233206c(void) { mrs r0, cpsr; bic r1, r0, #0x80; msr cpsr_c, r1; and r0, r0, #0x80; bx lr }
}
