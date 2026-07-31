// decomp: module=unk_autoload_0 addr=0x02328d60 name=FUN_02328d60
extern "C" void FUN_02328d60(int value, int flag) {
    unsigned short *reg = (unsigned short *)0x0400104a;
    unsigned int v = (*reg & ~0x3f) | value;
    if (flag != 0) {
        v |= 0x20;
    }
    *reg = (unsigned short)v;
}
