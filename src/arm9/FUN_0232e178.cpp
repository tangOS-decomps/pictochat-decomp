//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x0232e178 name=FUN_0232e178
int FUN_0232e178(int *a, int b) {
    if (b == 0) {
        return *a;
    }
    return *(int *)(b + *(unsigned short *)((char *)a + 0xa) + 4);
}

}
