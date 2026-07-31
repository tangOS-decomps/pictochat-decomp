// decomp: module=unk_autoload_0 addr=0x0232c820 name=FUN_0232c820
void FUN_0232c820(void) {
    unsigned short *reg = (unsigned short *)0x02ffff96;
    int v = *reg;
    if (v & 1) {
        *reg = v & ~1;
    }
}
