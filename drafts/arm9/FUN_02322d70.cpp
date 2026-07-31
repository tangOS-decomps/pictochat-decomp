// decomp: module=unk_autoload_0 addr=0x02322d70 name=FUN_02322d70
struct S_02322d70 {
    int f0;
    int f4;
    int f8;
    int fc;
};

void FUN_02322d70(int a) {
    struct S_02322d70 *g = (struct S_02322d70 *)0x0238ede0;
    g->f4 = 0;
    g->fc = (a + 8) & 0xf;
    g->f8 = 0;
}
