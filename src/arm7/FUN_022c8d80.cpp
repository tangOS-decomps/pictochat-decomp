//cpp
extern "C" {
// decomp: module=arm7 addr=0x022c8d80 name=FUN_022c8d80
struct S { char pad[0x24]; int f24; int f28; };
void FUN_022c8d80(struct S *o, int a, int b) {
    o->f24 = a;
    o->f28 = a + b;
}

}
