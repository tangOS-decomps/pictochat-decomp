// decomp: module=unk_autoload_0 addr=0x023345fc name=wcslen
int wcslen(const unsigned short *p) {
    int len = -1;
    do {
        len++;
    } while (*p++ != 0);
    return len;
}
