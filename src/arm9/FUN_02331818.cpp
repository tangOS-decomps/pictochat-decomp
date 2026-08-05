//cpp
// decomp: module=unk_autoload_0 addr=0x02331818 name=FUN_02331818
// flags: -noThumb

// Sets the given bits in CP15 c3,c0,0 - the domain access control register.
// See FUN_023317c4.

extern "C" void FUN_02331818(unsigned int mask) {
    unsigned int v;
    asm { mrc p15,0,v,c3,c0,0 }
    asm { orr v,v,mask }
    asm { mcr p15,0,v,c3,c0,0 }
}
