// decomp: module=unk_autoload_0 addr=0x02336710 name=VRAM_GetEngineBBaseAddr
extern "C" int VRAM_GetEngineBBaseAddr(void) {
    unsigned short val = *(unsigned short *)0x0400100a;
    int field = (val & 0x3c) >> 2;
    return (field << 14) + 0x06200000;
}
