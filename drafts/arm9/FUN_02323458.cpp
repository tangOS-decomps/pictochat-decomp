// decomp: module=unk_autoload_0 addr=0x02323458 name=FUN_02323458
struct S { char pad[0x18]; int f18; int f1c; };
extern struct S G;
void FUN_02323458(int a, int b) {
    G.f18 = a;
    G.f1c = b;
}
