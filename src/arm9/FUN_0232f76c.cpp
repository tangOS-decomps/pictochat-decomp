extern "C" {
// decomp: module=unk_autoload_0 addr=0x0232f76c name=FUN_0232f76c
void FUN_0232f76c(int a, int b) {
    int *base = *(int **)(*(int *)0x023bf010 + 0x84);
    *(int *)((char *)base + (a << 4) + 0x14) = b;
}

}
