// decomp: module=unk_autoload_0 addr=0x023363a4 name=FUN_023363a4
extern unsigned short G_023c1910;
extern unsigned short G_0236a178;

void FUN_023363a4(unsigned int mode, unsigned int bg, unsigned int bg0) {
    unsigned int cnt = *(volatile unsigned int *)0x04000000;
    G_023c1910 = mode;
    if (G_0236a178 == 0) {
        mode = 0;
    }
    *(volatile unsigned int *)0x04000000 = (bg0 << 3) | (((cnt & 0xfff0fff0) | (mode << 16)) | bg);
    if (G_023c1910 == 0) {
        G_0236a178 = 0;
    }
}
