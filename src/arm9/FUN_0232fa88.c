// decomp: module=unk_autoload_0 addr=0x0232fa88 name=FUN_0232fa88
extern int FUN_0232f74c(void *a);
extern int FUN_0232f54c(void);
extern int FUN_0232fa24(void *a, void (*cb)(void), int x, void *d, int b);
extern void FUN_0232f76c(void *a, int r);
extern void FUN_0232fc14(void);

int FUN_0232fa88(void *a, int b, int c) {
    int r = FUN_0232f74c(a);
    if (r == 0) {
        int x;
        if (c != 0) {
            x = FUN_0232f54c();
        } else {
            x = 0;
        }
        r = FUN_0232fa24(a, FUN_0232fc14, x, a, b);
        if (c != 0 && r != 0) {
            FUN_0232f76c(a, r);
        }
    }
    return r;
}
