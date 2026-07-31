//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x023213d8 name=FUN_023213d8
struct S { int field0; char pad[4]; int field8; };
int FUN_023213d8(struct S *a, int b) {
    int r = -1;
    if (a->field0 == b) r = a->field8;
    return r;
}

}
