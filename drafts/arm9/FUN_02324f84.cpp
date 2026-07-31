// decomp: module=unk_autoload_0 addr=0x02324f84 name=FUN_02324f84
struct S { char pad[0x2c]; int f2c; };
extern struct S G;
int FUN_02324f84(void) {
    return G.f2c == 1;
}
