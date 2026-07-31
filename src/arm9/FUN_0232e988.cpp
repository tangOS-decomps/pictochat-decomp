//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x0232e988 name=FUN_0232e988
void FUN_0232e988(int *p) {
    if (*(int *)p != 0) {
        int *q = *(int **)p;
        *q = 0;
        *(int *)p = 0;
    }
}

}
