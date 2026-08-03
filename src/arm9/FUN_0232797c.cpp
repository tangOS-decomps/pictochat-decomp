extern "C" {
// decomp: module=unk_autoload_0 addr=0x0232797c name=FUN_0232797c
struct S_0232797c { int f0[4]; int f10; };
int FUN_0232797c(void) {
    struct S_0232797c *g = (struct S_0232797c *)0x0239fe68;
    if (g->f10 == 1) {
        return 1;
    }
    return 0;
}

}
