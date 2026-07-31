// decomp: module=unk_autoload_0 addr=0x023317a4 name=_ZN4CP159EnableMPUEv
extern "C" unsigned int _ZN4CP159EnableMPUEv(void){
    unsigned int v;
    asm { mrc p15,0,v,c1,c0,0 }
    v |= 1;
    asm { mcr p15,0,v,c1,c0,0 }
    return v;
}
