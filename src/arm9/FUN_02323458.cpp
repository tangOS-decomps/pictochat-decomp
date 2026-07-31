// decomp: module=unk_autoload_0 addr=0x02323458 name=FUN_02323458
extern "C" {
    struct S_3458 { char pad[0x18]; int f18; int f1c; };
    extern struct S_3458 G_3458;
    void FUN_02323458(int a, int b) {
        G_3458.f18 = a;
        G_3458.f1c = b;
    }
}
