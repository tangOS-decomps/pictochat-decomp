// decomp: module=unk_autoload_0 addr=0x02331064 name=FUN_02331064
extern int FUN_02332080(void);
extern void FUN_02332094(int);
extern int G_023c07c4[];

int FUN_02331064(int value)
{
    int lock = FUN_02332080();
    int old = G_023c07c4[10];
    G_023c07c4[10] = value;
    FUN_02332094(lock);
    return old;
}
