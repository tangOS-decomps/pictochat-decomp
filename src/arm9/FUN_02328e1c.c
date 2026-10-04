// decomp: module=unk_autoload_0 addr=0x02328e1c name=FUN_02328e1c
extern void FUN_023296d8(int a, void *b, void *c);
extern void FUN_0232b9cc(void *f);
extern void func_0233746c(int v, void *dst, int size);
extern void func_023314e8(void *p, int size);
extern void FUN_02329524(void);
extern void FUN_023230e0(void);
extern void FUN_023230f8(void);
extern void FUN_023293d0(void);
extern char G_023a1500[];
extern int G_023a0f0c;
extern char G_023a0f70[];

void FUN_02328e1c(void) {
    FUN_023296d8(2, FUN_023230e0, FUN_023230f8);
    FUN_0232b9cc(FUN_023293d0);
    func_0233746c(0, G_023a1500, 0x4000);
    G_023a0f0c = 0;
    func_0233746c(0, G_023a0f70, 0x580);
    func_023314e8(G_023a0f70, 0x580);
    FUN_02329524();
}
