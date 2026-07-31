// decomp: module=unk_autoload_0 addr=0x02332d84 name=SafeStoreByte
int SafeStoreByte(char *ptr, char val) {
    if (ptr == 0) {
        return 0;
    }
    *ptr = val;
    return 1;
}
