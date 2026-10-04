// decomp: module=unk_autoload_0 addr=0x0232a480 name=FUN_0232a480
extern char G_023bd698[];
extern char G_023bd728[];
extern int FUN_0232996c(void);
extern int func_02332080(void);
extern void func_02332094(int irq);
extern void FUN_02331ef0(void *p);
extern void FUN_02329d0c(int a);
extern void FUN_0232b1c0(void);

void FUN_0232a480(void) {
    if (FUN_0232996c() == 7) {
        int irq = func_02332080();
        *(int *)(G_023bd698 + 0x14) = 0;
        FUN_02331ef0(G_023bd728);
        FUN_02329d0c(0);
        *(int *)(G_023bd698 + 0x30) = 1;
        *(int *)(G_023bd698 + 0x2c) = 0;
        func_02332094(irq);
        *(int *)(G_023bd698 + 0x40) = 1;
        FUN_0232b1c0();
    }
}
