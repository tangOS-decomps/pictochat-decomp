// decomp: module=unk_autoload_0 addr=0x02337358 name=FUN_02337358
extern int func_02332080(void);
extern void func_02332094(int irq);

void FUN_02337358(unsigned int ch) {
    int irq = func_02332080();
    volatile unsigned int *cnt = (volatile unsigned int *)(0x040000b8 + ch * 12);
    unsigned int v;
    *cnt &= 0xc5ffffff;
    *cnt &= 0x7fffffff;
    v = *cnt;
    v = *cnt;
    if (ch == 0) {
        volatile unsigned int *r = (volatile unsigned int *)(0x040000b0 + ch * 12);
        r[0] = 0;
        r[1] = 0;
        r[2] = 0x81400001;
    }
    func_02332094(irq);
}
