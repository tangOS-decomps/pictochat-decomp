// decomp: module=unk_autoload_0 addr=0x02329bd8 name=FUN_02329bd8
struct State02329bd8 { char pad[0x14]; int state; };
void FUN_02329bd8(int arg0) {
    struct State02329bd8 *g = (struct State02329bd8 *)0x023bd5e0;
    if (g->state < 0xc || arg0 == 0xe) {
        g->state = arg0;
    }
}
