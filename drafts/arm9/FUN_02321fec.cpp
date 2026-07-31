// decomp: module=unk_autoload_0 addr=0x02321fec name=FUN_02321fec
struct S { char pad[0x14]; int f14; };
extern struct S G;
int FUN_02321fec(void) {
    return G.f14 != -1;
}
