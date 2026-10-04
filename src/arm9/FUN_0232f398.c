// decomp: module=unk_autoload_0 addr=0x0232f398 name=FUN_0232f398
extern char G_023bef1c[];
extern void FUN_02337784(int a, int b, int mask, int d);
extern int FUN_02337cac(void);
extern void FUN_02337b54(int a);
extern void FUN_02337c68(int a);

void FUN_0232f398(void) {
    char *g = G_023bef1c;
    int mask;
    int r;
    if (*(int *)g == 0) {
        return;
    }
    if (*(int *)(g + 0x2c) >= 0) {
        mask = 1 << *(int *)(g + 0x2c);
    } else {
        mask = 0;
    }
    FUN_02337784(*(int *)(g + 0x24), *(int *)(g + 0x28), mask, 0);
    r = FUN_02337cac();
    FUN_02337b54(1);
    FUN_02337c68(r);
}
