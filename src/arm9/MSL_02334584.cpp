// decomp: module=unk_autoload_0 addr=0x02334584 name=FUN_02334584
int FUN_02334584(const signed char *p) {
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
