// decomp: module=unk_autoload_0 addr=0x023317b4 name=_ZN4CP1510DisableMPUEv
extern "C" unsigned int _ZN4CP1510DisableMPUEv(void){
    unsigned int v;
    asm { mrc p15,0,v,c1,c0,0 }
    asm { bic v,v,#1 }
    asm { mcr p15,0,v,c1,c0,0 }
    return v;
}
