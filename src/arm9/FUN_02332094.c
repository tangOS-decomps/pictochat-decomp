// decomp: module=unk_autoload_0 addr=0x02332094 name=FUN_02332094
asm unsigned int FUN_02332094(unsigned int param_1)
{
    mrs r1, cpsr;
    bic r2, r1, #0x80;
    orr r2, r2, r0;
    msr cpsr_c, r2;
    and r0, r1, #0x80;
    bx lr;
}
