// decomp: module=unk_autoload_0 addr=0x02329780 name=FUN_02329780
#pragma thumb on

extern int FUN_0232996c(void);
extern void FUN_02329858(void);
extern void FUN_023298a0(void);
extern void FUN_02329bd8(int);
extern volatile int G_023bd5e0[];

void FUN_02329780(void)
{
    G_023bd5e0[2] = 0;
    if (FUN_0232996c() == 1 ||
        (FUN_0232996c() >= 0xc && FUN_0232996c() != 0xe)) {
        FUN_02329858();
        return;
    }
    if (FUN_0232996c() == 0xb) {
        FUN_023298a0();
        FUN_02329bd8(0);
        return;
    }
    if (FUN_0232996c() != 0 && FUN_0232996c() < 0xc)
        G_023bd5e0[6] = 2;
}
