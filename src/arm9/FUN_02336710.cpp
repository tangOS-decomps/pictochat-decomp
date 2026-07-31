// decomp: module=unk_autoload_0 addr=0x02336710 name=FUN_02336710
int FUN_02336710(void) {
    unsigned short val = *(unsigned short *)0x0400100a;
    int field = (val & 0x3c) >> 2;
    return (field << 14) + 0x06200000;
}
