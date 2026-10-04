// decomp: module=unk_autoload_0 addr=0x02337d84 name=FUN_02337d84
extern void FUN_023382ac(int ch, void (*cb)(void));
extern int FUN_02337e08(void);
extern int FUN_023382f8(int ch, int a);
extern void FUN_023320fc(int ms);
extern void FUN_02337d6c(void);

void FUN_02337d84(void) {
    FUN_023382ac(7, FUN_02337d6c);
    if (FUN_02337e08() != 0) {
        while (FUN_023382f8(7, 1) == 0) {
            FUN_023320fc(0x32);
        }
    }
}
