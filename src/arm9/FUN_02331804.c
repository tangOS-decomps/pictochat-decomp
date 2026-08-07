// decomp: module=unk_autoload_0 addr=0x02331804 name=FUN_02331804
void FUN_02331804(unsigned int clear_mask, unsigned int set_mask) {
    unsigned int v;
    asm { mrc p15,0,v,c5,c0,2 }
    asm { bic v,v,clear_mask }
    asm { orr v,v,set_mask }
    asm { mcr p15,0,v,c5,c0,2 }
}
