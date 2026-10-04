//cpp
// decomp: module=unk_autoload_0 addr=0x02337ccc name=FUN_02337ccc
extern "C" {
extern unsigned int G_023c1960[];
extern int func_02332080(void);
extern void func_02332094(int irq);

int FUN_02337ccc(unsigned int t) {
    int irq = func_02332080();
    unsigned int now = G_023c1960[1];
    int r;
    if (t > now) {
        if (t - now < 0x80000000) {
            r = 0;
        } else {
            r = 1;
        }
    } else {
        if (now - t < 0x80000000) {
            r = 1;
        } else {
            r = 0;
        }
    }
    func_02332094(irq);
    return r;
}
}
