// decomp: module=unk_autoload_0 addr=0x02339410 name=FUN_02339410
extern int FUN_02339298(int a, int b, unsigned short *out);

int FUN_02339410(int *a, int *b) {
    unsigned short v;
    int r = FUN_02339298(0xf, 3, &v);
    if (r == 0) {
        if (a != 0) {
            *a = (v & 8) ? 1 : 0;
        }
        if (b != 0) {
            *b = (v & 4) ? 1 : 0;
        }
    }
    return r;
}
