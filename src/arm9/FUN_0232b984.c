// decomp: module=unk_autoload_0 addr=0x0232b984 name=FUN_0232b984
extern char G_023bd814[];
extern int G_02369d04;
extern int func_02332080(void);
extern void func_02332094(int irq);
extern int FUN_0232b95c(void);
extern void FUN_0232bcfc(void);

int FUN_0232b984(int a, int b) {
    int irq = func_02332080();
    if (FUN_0232b95c() != 0) {
        *(int *)(G_023bd814 + 0x14) = 1;
        *(int *)(G_023bd814 + 0x28) = b;
        G_02369d04 = a;
        *(int *)(G_023bd814 + 0x1c) = 0;
        *(int *)(G_023bd814 + 0x20) = -1;
        FUN_0232bcfc();
        func_02332094(irq);
        return 1;
    }
    func_02332094(irq);
    return 0;
}
