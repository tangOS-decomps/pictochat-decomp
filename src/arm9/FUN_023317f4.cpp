//cpp
// decomp: module=unk_autoload_0 addr=0x023317f4 name=FUN_023317f4
// flags: -noThumb

// Clears the given bits in CP15 c2,c0,0. See FUN_023317c4.

extern "C" void FUN_023317f4(unsigned int mask) {
    unsigned int v;
    asm { mrc p15,0,v,c2,c0,0 }
    asm { bic v,v,mask }
    asm { mcr p15,0,v,c2,c0,0 }
}
