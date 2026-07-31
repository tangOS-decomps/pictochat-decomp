// decomp: module=unk_autoload_0 addr=0x02328d80 name=FUN_02328d80
void FUN_02328d80(int value, int flag) {
    unsigned short *reg = (unsigned short *)0x0400104a;
    int v = (*reg & 0xffffc0ff) | (value << 8);
    if (flag != 0) {
        v |= 0x2000;
    }
    *reg = v;
}
