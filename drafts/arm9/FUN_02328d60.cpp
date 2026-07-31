// decomp: module=unk_autoload_0 addr=0x02328d60 name=FUN_02328d60
void FUN_02328d60(int value, int flag) {
    int v = (*(unsigned short *)0x0400104a & ~0x3f) | value;
    if (flag != 0) {
        v |= 0x20;
    }
    *(unsigned short *)0x0400104a = v;
}
