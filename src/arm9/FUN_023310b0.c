// decomp: module=unk_autoload_0 addr=0x023310b0 name=FUN_023310b0
extern int FUN_02332080(void);
extern void FUN_02332094(int);
extern int G_023c07c4[];

int FUN_023310b0(void)
{
    int lock = FUN_02332080();
    int result = 0;
    int old = G_023c07c4[1];

    if (old != 0) {
        G_023c07c4[1] = old - 1;
        result = old;
    }

    FUN_02332094(lock);
    return result;
}
