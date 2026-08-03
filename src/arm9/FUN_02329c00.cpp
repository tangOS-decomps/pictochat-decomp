extern "C" {
// decomp: module=unk_autoload_0 addr=0x02329c00 name=FUN_02329c00
struct State02329bd8 { char pad[0x14]; int state; };
int FUN_02329c00(void) {
    struct State02329bd8 *g = (struct State02329bd8 *)0x023bd5e0;
    return g->state >= 0xc;
}

}
