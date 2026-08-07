//cpp
// decomp: module=unk_autoload_0 addr=0x023320ac name=FUN_023320ac
extern "C" {
asm unsigned int FUN_023320ac(void) { mrs r0, cpsr; orr r1, r0, #0xc0; msr cpsr_c, r1; and r0, r0, #0xc0; bx lr }
}
