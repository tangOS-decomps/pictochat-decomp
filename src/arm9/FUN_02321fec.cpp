// decomp: module=unk_autoload_0 addr=0x02321fec name=FUN_02321fec
extern "C" {
    struct S_02321fec { char pad[0x14]; int f14; };
    extern struct S_02321fec G_02321fec;
    int FUN_02321fec(void) {
        return G_02321fec.f14 != -1;
    }
}
