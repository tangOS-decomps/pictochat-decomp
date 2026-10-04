// decomp: module=unk_autoload_0 addr=0x0232e198 name=FUN_0232e198
extern char *FUN_0232e178(void *list, void *prev);

void *FUN_0232e198(void *list, unsigned int addr) {
    char *n;
    for (n = FUN_0232e178(list, 0); n != 0; n = FUN_0232e178(list, n)) {
        if (*(unsigned int *)(n + 0x18) <= addr && addr < *(unsigned int *)(n + 0x1c)) {
            void *r = FUN_0232e198(n + 0xc, addr);
            if (r != 0) {
                return r;
            }
            return n;
        }
    }
    return 0;
}
