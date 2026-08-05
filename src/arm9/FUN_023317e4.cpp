//cpp
// decomp: module=unk_autoload_0 addr=0x023317e4 name=FUN_023317e4
// flags: -noThumb

// Sets the given bits in CP15 c2,c0,0 - the instruction-cacheable configuration
// register. See FUN_023317c4.

extern "C" void FUN_023317e4(unsigned int mask) {
    unsigned int v;
    asm { mrc p15,0,v,c2,c0,0 }
    asm { orr v,v,mask }
    asm { mcr p15,0,v,c2,c0,0 }
}
