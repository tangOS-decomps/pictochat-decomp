// decomp: module=unk_autoload_0 addr=0x0232c3cc name=FUN_0232c3cc
extern char G_023bd8b8[];
extern int FUN_023312a0(void *q, unsigned short **out, int flags);
extern void func_023314cc(void *p, int size);
extern void FUN_02331308(void *q, void *p, int flags);

unsigned short *FUN_0232c3cc(void) {
    unsigned short *p;
    if (FUN_023312a0(G_023bd8b8, &p, 0) == 0) {
        return 0;
    }
    func_023314cc(p, 2);
    if ((*p & 0x8000) == 0) {
        FUN_02331308(G_023bd8b8, p, 1);
        return 0;
    }
    return p;
}
