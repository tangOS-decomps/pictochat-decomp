// decomp: module=arm7 addr=0x022c83d0 name=FUN_022c83d0
struct S { char pad[0x48]; int f48; int f4c; };
void FUN_022c83d0(struct S *p) {
    if (p != 0) {
        p->f48 = 0;
        p->f4c = 0;
    }
}
