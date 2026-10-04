//cpp
// decomp: module=unk_autoload_0 addr=0x02329b2c name=FUN_02329b2c
extern "C" {
extern char G_023bd5e0[];
extern int FUN_0232996c(void);
extern void FUN_02329bf0(int a);
extern int FUN_0232cae8(void *p);
extern void FUN_02329bd8(int a);

void FUN_02329b2c(void *p, int flag) {
    if (*(int *)(G_023bd5e0 + 0x10) != 0) {
        return;
    }
    if (flag != 0) {
        FUN_02329bf0(2);
    } else if (FUN_0232996c() >= 0xc) {
        return;
    }
    {
        int r = FUN_0232cae8(p);
        *(int *)(G_023bd5e0 + 0x10) = 1;
        if (r != 2) {
            FUN_02329bd8(0xc);
            *(int *)(G_023bd5e0 + 0x10) = 0;
        }
    }
}
}
