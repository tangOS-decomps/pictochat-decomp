extern "C" {
// decomp: module=unk_autoload_0 addr=0x023260c4 name=FUN_023260c4
struct S_023260c4 { int f0; int f4; };
int FUN_023260c4(void) {
    struct S_023260c4 *g = (struct S_023260c4 *)0x0239c914;
    if (g->f4 == 2) {
        return 1;
    }
    return 0;
}

}
