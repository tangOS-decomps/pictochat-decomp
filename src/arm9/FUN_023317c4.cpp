//cpp
// decomp: module=unk_autoload_0 addr=0x023317c4 name=FUN_023317c4
// flags: -noThumb

// Sets the given bits in CP15 c2,c0,1 - the data-cacheable configuration
// register. mrc/mcr have no C spelling, so this is one of the sanctioned inline
// asm cases (fixed hardware-register programming, not application logic). It sits
// immediately after CP15_DisableMPU in the same accessor block.

extern "C" void FUN_023317c4(unsigned int mask) {
    unsigned int v;
    asm { mrc p15,0,v,c2,c0,1 }
    asm { orr v,v,mask }
    asm { mcr p15,0,v,c2,c0,1 }
}
