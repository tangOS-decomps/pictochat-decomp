// decomp: module=unk_autoload_0 addr=0x023305d8 name=FUN_023305d8
struct S_023305d8 { int f0[2]; int f8; int fc; };
int FUN_023305d8(struct S_023305d8 *a) {
    if (a->f8 >= a->fc) {
        return 1;
    }
    return 0;
}
