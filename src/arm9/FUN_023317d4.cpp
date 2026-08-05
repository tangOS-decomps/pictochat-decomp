//cpp
// decomp: module=unk_autoload_0 addr=0x023317d4 name=FUN_023317d4
// flags: -noThumb

// Clears the given bits in CP15 c2,c0,1. See FUN_023317c4.

extern "C" void FUN_023317d4(unsigned int mask) {
    unsigned int v;
    asm { mrc p15,0,v,c2,c0,1 }
    asm { bic v,v,mask }
    asm { mcr p15,0,v,c2,c0,1 }
}
