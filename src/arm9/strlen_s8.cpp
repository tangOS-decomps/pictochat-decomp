//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x02334584 name=strlen_s8
int strlen_s8(const signed char *p) {
    int len = -1;
    int c;
    int zero = 0;
    do {
        len++;
        c = p[zero];
        p++;
    } while (c != 0);
    return len;
}

}
