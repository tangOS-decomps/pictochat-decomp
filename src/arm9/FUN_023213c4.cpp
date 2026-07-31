//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x023213c4 name=FUN_023213c4
struct S { char pad[4]; int field4; int field8; };
int FUN_023213c4(struct S *a, int b) {
    if (a->field8 == 3 && a->field4 == b) return 1;
    return 0;
}

}
