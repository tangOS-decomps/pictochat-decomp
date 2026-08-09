// decomp: module=unk_autoload_0 addr=0x0232b0d0 name=FUN_0232b0d0
extern int FUN_02329c00(void);
extern void FUN_0232b9e4(void);
extern void FUN_0232c0c4(void);
extern void FUN_0232b124(void);
extern int FUN_0232cf20(void (*)(void), int, unsigned short, int, unsigned short, int, int, int, int, int, int);
extern void FUN_02329bd8(int);
extern int G_023bd698[];

void FUN_0232b0d0(void)
{
    if (FUN_02329c00() == 0)
    {
        FUN_0232b9e4();
        FUN_0232c0c4();

        G_023bd698[4] = 0;
        G_023bd698[8] = 0;
        G_023bd698[9] = 0;

        if (FUN_0232cf20(FUN_0232b124,
                         G_023bd698[6],
                         ((unsigned short *)G_023bd698)[1],
                         G_023bd698[10],
                         ((unsigned short *)G_023bd698)[5],
                         4, 4, 1, 1, 1, 0) != 2)
        {
            FUN_02329bd8(0xC);
        }
    }
}
