// decomp: module=unk_autoload_0 addr=0x02329a08 name=FUN_02329a08
extern "C" int FUN_02329a08(void *p) {
    if (p != 0) {
        unsigned char v = *((unsigned char *)p + 0xa);
        switch (v) {
            case 0: return 0;
            case 1: return 1;
            case 2: return 2;
            case 3: return 3;
        }
    }
    return 5;
}
