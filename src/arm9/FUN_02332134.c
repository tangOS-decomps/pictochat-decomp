// decomp: module=unk_autoload_0 addr=0x02332134 name=FUN_02332134
// flags: -noThumb
extern unsigned short G_023c0b10;
extern void FUN_023381f8(void);
extern int FUN_023382f8(int, int);
extern void FUN_023382ac(int, void *);

void FUN_02332134(void)
{
    if (G_023c0b10 != 0)
        return;

    G_023c0b10 = 1;
    FUN_023381f8();
    while (FUN_023382f8(0xc, 1) == 0)
        ;
    FUN_023382ac(0xc, (void *)0x02330869);
}
