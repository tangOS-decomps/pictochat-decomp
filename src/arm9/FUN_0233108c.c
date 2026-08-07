// decomp: module=unk_autoload_0 addr=0x0233108c name=FUN_0233108c
extern int FUN_02332080(void);
extern void FUN_02332094(int);
extern int G_023c07c4[];

int FUN_0233108c(void)
{
    int lock = FUN_02332080();
    int result;
    int old = G_023c07c4[1];

    if ((unsigned int)old < 0xFFFFFFFFu) {
        G_023c07c4[1] = old + 1;
        result = old;
    }

    FUN_02332094(lock);
    return result;
}
