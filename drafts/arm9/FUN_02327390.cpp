// decomp: module=unk_autoload_0 addr=0x02327390 name=FUN_02327390
struct S { char pad[0x18]; int f18; int f1c; char pad2[0x20 - 0x1c - 4]; int f20; };
extern struct S G;
void FUN_02327390(void) {
    int v = G.f20;
    G.f18 = v;
    G.f1c = v;
}
