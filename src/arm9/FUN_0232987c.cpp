//cpp
// decomp: module=unk_autoload_0 addr=0x0232987c name=FUN_0232987c

// The FUN_02329858 shape, setting the state word to 0xb instead of clearing it.

#pragma thumb on
extern "C" {
extern int FUN_0232996c(void);
extern void FUN_02329b2c(void (*)(void), int);
extern void FUN_02329b70(void);
extern int G_023bd5e0[];
void FUN_0232987c(void)
{
    if (FUN_0232996c() != 0) {
        G_023bd5e0[2] = 0xb;
        FUN_02329b2c(FUN_02329b70, 1);
    }
}
}
