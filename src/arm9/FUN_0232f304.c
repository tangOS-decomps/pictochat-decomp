// decomp: module=unk_autoload_0 addr=0x0232f304 name=FUN_0232f304

// Shuts down the subsystem whose state block is G_023bef1c: masks/stops the
// configured channel, drains the queue at G_023beedc, releases the resources
// recorded at +0x20/+0x28/+0x2c and clears the active flag.

extern char G_023bef1c[];
extern char G_023beedc[];
extern void FUN_02337784(int a, int b, int mask, int d);
extern int FUN_02337cac(void);
extern void FUN_02337b54(int a);
extern void FUN_02337c68(int a);
extern int FUN_023312a0(void *q, void *out, int flags);
extern void FUN_0232e868(int a);
extern void FUN_0232e830(int a);
extern void FUN_0232e8a4(int a);
extern void FUN_023378c4(int a, int b, int c, int d);

void FUN_0232f304(void) {
    char *g = G_023bef1c;
    int has;
    int mask;
    int r;
    if (*(int *)g == 0) {
        return;
    }
    has = *(int *)(g + 0x2c) >= 0;
    if (has) {
        mask = 1 << *(int *)(g + 0x2c);
    } else {
        mask = 0;
    }
    FUN_02337784(*(int *)(g + 0x24), *(int *)(g + 0x28), mask, 0);
    if (has) {
        r = FUN_02337cac();
        FUN_02337b54(1);
        FUN_02337c68(r);
        while (FUN_023312a0(G_023beedc, 0, 0) != 0) {
        }
    }
    if (*(int *)(g + 0x28) != 0) {
        FUN_0232e868(*(int *)(g + 0x28));
    }
    if (*(int *)(g + 0x20) != 0) {
        FUN_0232e830(*(int *)(g + 0x20));
    }
    if (has) {
        FUN_0232e8a4(*(int *)(g + 0x2c));
    }
    if (*(int *)(g + 4) == 1) {
        FUN_023378c4(0, 0, 0, 0);
    }
    *(int *)g = 0;
}
