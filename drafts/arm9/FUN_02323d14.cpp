// decomp: module=unk_autoload_0 addr=0x02323d14 name=FUN_02323d14
struct S { char pad[0xc]; int fc; };
extern struct S G;
int FUN_02323d14(void) {
    return G.fc != 0;
}
