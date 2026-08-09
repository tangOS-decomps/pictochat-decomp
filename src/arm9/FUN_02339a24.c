// decomp: module=unk_autoload_0 addr=0x02339a24 name=FUN_02339a24
#pragma thumb on
extern int FUN_023399c0(int, void *, int);
extern void FUN_02339e48(void);
extern void FUN_02339e54(void);
extern int G_023c35a0[];

int FUN_02339a24(int a0)
{
    int r0 = FUN_023399c0(a0, (void *)FUN_02339e48, 0);
    G_023c35a0[9] = r0;
    if (r0 == 0)
        FUN_02339e54();
    return G_023c35a0[9];
}
