// decomp: module=unk_autoload_0 addr=0x0232fbd8 name=FUN_0232fbd8
#pragma thumb on

extern int FUN_02332080(int a);
extern void FUN_02332094(int a);
extern int FUN_0232f53c(int a);
extern int FUN_0232f74c(int a);
extern void FUN_0232f76c(int a, int b);

void FUN_0232fbd8(int a, int b, int c) {
    if (b != 0) {
        int x = FUN_02332080(a);
        int y = FUN_0232f53c(b);
        if (FUN_0232f74c(c) == a) {
            FUN_0232f76c(c, 0);
        }
        FUN_0232f53c(y);
        FUN_02332094(x);
    }
}
