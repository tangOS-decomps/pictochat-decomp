// decomp: module=unk_autoload_0 addr=0x0232b064 name=FUN_0232b064
extern int FUN_02329c00(void);
extern int FUN_0232d098(void (*)(void), int, unsigned short, int, unsigned short, int);
extern void FUN_02329bd8(int);
extern void FUN_0232b09c(void);
extern int G_023bd698[];

void FUN_0232b064(void)
{
    if (FUN_02329c00() == 0 &&
        FUN_0232d098(FUN_0232b09c,
                     G_023bd698[0x0D],
                     ((unsigned short *)G_023bd698)[2],
                     0,
                     ((unsigned short *)G_023bd698)[4],
                     1) != 2)
    {
        FUN_02329bd8(0xC);
    }
}
