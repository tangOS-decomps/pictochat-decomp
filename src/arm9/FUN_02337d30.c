// decomp: module=unk_autoload_0 addr=0x02337d30 name=FUN_02337d30
extern int FUN_02332080(void);
extern void FUN_02332094(int);
extern int G_023c1960[];

int FUN_02337d30(void)
{
    int lock = FUN_02332080();
    int count = 0;
    int *p = (int *)G_023c1960[2];

    while (p != 0)
    {
        p = (int *)*p;
        count++;
    }

    FUN_02332094(lock);
    return count;
}
