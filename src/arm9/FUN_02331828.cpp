//cpp
// decomp: module=unk_autoload_0 addr=0x02331828 name=FUN_02331828
// flags: -noThumb

// Clears the given bits in CP15 c3,c0,0. See FUN_023317c4.

extern "C" void FUN_02331828(unsigned int mask) {
    unsigned int v;
    asm { mrc p15,0,v,c3,c0,0 }
    asm { bic v,v,mask }
    asm { mcr p15,0,v,c3,c0,0 }
}
