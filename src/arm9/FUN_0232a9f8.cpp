extern "C" {
// decomp: module=unk_autoload_0 addr=0x0232a9f8 name=FUN_0232a9f8
struct Elem0232a9f8 { unsigned short f0; char pad[4]; };
unsigned short FUN_0232a9f8(void) {
    unsigned short v;
    int i;
    volatile struct Elem0232a9f8 *p = (volatile struct Elem0232a9f8 *)0x023bd7b4;
    for (i = 0; i < 16; i++) {
        v = p->f0;
        p++;
    }
    return v;
}

}
