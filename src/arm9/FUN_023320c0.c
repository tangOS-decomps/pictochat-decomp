// decomp: module=unk_autoload_0 addr=0x023320c0 name=FUN_023320c0
asm unsigned int FUN_023320c0(unsigned int param_1) { mrs r1, cpsr; bic r2, r1, #0xc0; orr r2, r2, r0; msr cpsr_c, r2; and r0, r1, #0xc0; bx lr }
